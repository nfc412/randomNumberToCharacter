// Creating random numbers using the system time and static casting them to ascii characters and printing them and
//if they are unprintable, print NA or if they are a letter, print the upper and lower case

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iomanip>

//Setting standard for in/out statements
using namespace std;

//File access
fstream rand_nbrs;





int main()
{
	int counter, nbr;

	rand_nbrs.open("C:\\Users\\Nicholas\\source\\repos\\Random_Nbrs.txt", ios::out);

	//Test for the file validity
	if (!rand_nbrs) {
		cout << "File not found" << '\n';
		system("PAUSE");
		return 0;
	}
	unsigned seed;

	//Taking the system time at the current instance and putting it in seed
	seed = time(0);
	//Incrementing factor for loop
	counter = 0;
	srand(seed);


	//Basic column formatting to help readability
	cout << setw(10) << " Random Number\t| Character\t| Uppercase\t| Lowercase\n";
	cout << "-------------------------------------------------------------\n";

	rand_nbrs << setw(10) << " Random Number\t| Character\t| Uppercase\t| Lowercase\n";
	rand_nbrs << "-------------------------------------------------------------\n";


	//Loop for amount of random numbers
	while (counter < 100) {
		nbr = rand() % 123;


		//Console prints
		cout <<  setw(10) << " " << nbr;
		
		
		//Test for unprintable characters
		if (nbr >= 0 && nbr <= 31) {
			cout << "\t|\t" << "NA";
		}
		else if (nbr == 32) {
			cout << "\t|\t" << "Space";
		}
		else {
			cout << "\t|\t" << static_cast<char>(nbr);
		}
		
		
		//Text file prints
		rand_nbrs << setw(10) << " " << nbr;
		
		//Test for unprintable
		if (nbr >= 0 && nbr <= 31) {
			rand_nbrs << "\t|\t" << "NA";
		}
		else if (nbr == 32) {
			rand_nbrs << "\t|\t" << "Space";
		}
		else {
			rand_nbrs << "\t|\t" << static_cast<char>(nbr);
		}
		
		
		//Print upper case
		if(nbr >= 65 && nbr <= 90) {
			cout << "\t|\t" << static_cast<char>(nbr);
			rand_nbrs << "\t|\t" << static_cast<char>(nbr);
		}
		else if (nbr >= 97 && nbr <= 122) {
			cout << "\t|\t" << static_cast<char>((nbr - 32));
			rand_nbrs << "\t|\t" << static_cast<char>((nbr - 32));
		}
		else if (nbr >= 0 && nbr <= 31) {
			cout << "\t|\t" << "NA";
			rand_nbrs << "\t|\t" << "NA";
		}
		else if (nbr == 32) {
			cout << "\t|\t" << "Space";
			rand_nbrs << "\t|\t" << "Space";
		}
		//Technically I could remove the first if statement in this if else block, 
		//but it helps with the readability so I'm just leaving it here
		else {
			cout << "\t|\t" << static_cast<char>(nbr);
			rand_nbrs << "\t|\t" << static_cast<char>(nbr);
		}

		//Print lower case
		if (nbr >= 97 && nbr <= 122) {
			cout << "\t|\t" << static_cast<char>(nbr) << '\n';
			rand_nbrs << "\t|\t" << static_cast<char>(nbr) << '\n';
		}
		else if (nbr >= 65 && nbr <= 90) {
			cout << "\t|\t" << static_cast<char>((nbr + 32)) << '\n';
			rand_nbrs << "\t|\t" << static_cast<char>((nbr + 32)) << '\n';
		}
		else if (nbr >= 0 && nbr <= 31) {
			cout << "\t|\t" << "NA" << '\n';
			rand_nbrs << "\t|\t" << "NA" << '\n';
		}
		else if (nbr == 32) {
			cout << "\t|\t" << "Space" << '\n';
			rand_nbrs << "\t|\t" << "Space" << '\n';
		}
		//Technically I could remove the first if statement in this if else block, 
		//but it helps with the readability so I'm just leaving it here
		else {
			cout << "\t|\t" << static_cast<char>(nbr) << '\n';
			rand_nbrs << "\t|\t" << static_cast<char>(nbr) << '\n';
		}
		
		//Increment the loop
		counter++;
	}
	//Closing the random numbers file
	rand_nbrs.close();

	return 0;



}