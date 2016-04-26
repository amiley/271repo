//============================================================================
// Name        : last_hw_tgod.cpp
// Author      : Me
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

//takes the information from the file and places it into an array

bool getFile (int *& my_array)
{
    if(my_array!=NULL) delete my_array;
    char *lineData[] = new int[];
    int number;

	string file_name; //declares object to hold user-requested file name
	cout << "What is the name of the file? \n " << file_name; //asks user for file name  to read
	cin >> file_name; //takes in the users input and sets it to the file_name object

	//THIS CODE NEEDS TO BE CORRECTED AS OF COMMENTS ON HW 3


	if ("file_name.txt" =="everybodys_social.txt"){ //if the file name is everybodys_social.txt...
		int i = 0;
		ifstream in; //input file stream in
		in.open(file_name); //open file of whatever file name
		if(!in.is_open()) {
			cout << "I cannot find the file << " ;
			return false; //if in will not open return false
		}
		//takes comma delimited info out of file and places it in array
		else{
			while (in.good()){
				in.getline(lineData, ',');
				my_array[i] = atoi(lineData);
				i++;
			}
			in.close();
		}
	}

	else{
		cout << "Sorry, I cannot find the file, please enter the correct filename" << file_name;
	}

		string line; //declare variable for what is in the line
		string out; //variable for all output
		int array_size = my_array.size; //get val for array size
		return array_size;

}
int extraction_method(int hash_num)
{
	/*Take the value that the user has previously specified from the file(there are 450 mil SS
	 * numbers, so if they say 10, it'll be the tenth SS number), and extract each digit from the integer specified,
	 * and place it in it's own space in the array. Then, once all of the digits in the array have been placed in the
	 * array, we take the third value and multiply it by 1000, the fifth mult. by 100, seventh by 10 and eighth by nothing,
	 * and add them together, which gives the hashing address
	 */
	int *array_of_digits = new int[8];
	int address;
	int num_sub; //this value is the one placed in the next available space in the array
	int new_num; //this value will be used as a temporary value of sorts
	for(int i = 8; i >= 0; i--) {
		num_sub = hash_num % 10;
		new_num = hash_num - num_sub;
		new_num = new_num / 10;
		array_of_digits[i] = num_sub;
		hash_num = new_num;
		return array_of_digits[8];
	}
	int val1 = array_of_digits[2]*1000; //thousandths place
	int val2 = array_of_digits[4]*100; //hundredths place
	int val3 = array_of_digits[6]*10; //tens place
	int val4 = array_of_digits[7]; //ones place
	address = val1 + val2 + val3 + val4; //val used to hash with
	return address;
}


int quadratic_probing_with_replacement(int hash_table[], int address) {

	int M = 65000;  //set val M to the number of SSN's in the file
	while (hash_table[address] != 0){ //while theres a number in the hashtable at the specified address
		int i = 1; //integer for the f(i) function
		//represents iteration of the implementation of the hash function

		address = (address + i^2)%M; //new address is the origin
	}
	return address;
}

int main()
{

	int hash_num;
	cout << "Please provide an integer, non-negative number between 1 and 450 million" << hash_num; //this is the number we hash

	int *hash_table[] = new int[]; //this is the hash table
	int * array_of_numbers = new int[];

	getFile("everybodys_social.txt",array_of_numbers); //get a file to store everyone's SSN

	//hash the elements into the hash_table

	int indx; //the address for the place to put an SSN

	for(i = 0; i < getFile(my_array); i++) { //for loop to go through the file

		indx= extraction_method(hash_num); //user specified location within the file for the address in the hash table

		if(hash_table[indx] == 0) //if there is no val in the hash table at the specified function
			hash_table[indx] = array_of_numbers[hash_num-1]; //the address for the specified SSN is the indx

		else
		{
			quadratic_probing_with_replacement(hash_table, indx); //modify indx in hash_table using quadratic probing
		}
	}

	cout << hashtable[] << everybodys_social.txt << endl; //write out the array to the file for everyone's SSN

	return 1;
}
