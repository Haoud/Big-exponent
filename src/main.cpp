#include <cmath>
#include <ctime>
#include <gmpxx.h>
#include <fstream>
#include <iostream>

#include <signal.h>
#include <unistd.h>
using namespace std;


int main(int argc, char *argv[])
{
	unsigned int exp;
	mpz_class num;
	ofstream file;

	cout << "Enter the number:";
	cin >> num;

	cout << "Enter the exposant:";
	cin >> exp;

	file.open("save", ios::out);

	if(!file)
	{
		cerr << "Unable to open the backup file" << endl;
		return -1;
	}

	cout << "Generating " << num << " ^ " << exp << "..." << flush;
	mpz_pow_ui(num.get_mpz_t(), num.get_mpz_t(), exp);
	cout << "done" << endl;

	cout << "The number is composed of " << mpz_sizeinbase(num.get_mpz_t(), 10) << " digits" << endl;

	cout << "Saving this number on disk..." << flush;
	file << num << endl;
	file.close();
	cout << "done" << endl;

	return 0;
}
