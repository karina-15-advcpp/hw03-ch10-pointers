/* hw3pc5_pie_a_la_mode.cpp - Find the mode of slices of pie eaten
   Author:  Karina Elias
   Module:	3
   Project:	Homework 3 - Programming Challenge 5
   
   Problem Statement: In statistics, the mode of a set of values is the value
	that occurs most often. Write a program that determines how many pieces of
	pie most people eat in a year. Set up a dynamically-allocated integer array
	that can hold responses from 30 people. For each person enter the number of
	pieces they say they eat in a year. Then write a function that finds the mode
	of those 30 values (this will be the number of pie slices eaten by the most
	people). The function that finds and returns the mode should accept two
	arguments, an array of integers, and a value indicating how many elements are
	in the array.
	One possible approach is to sort the array after all responses have been
	entered. Scan the array, counting the number of times each response occur
	 consecutively in the array. Print the responses in sorted order to make
	 verification easier.
   
   Algorithm / Plan:
	   1. Declare constant for number of people
	   2. Declare pointer for array
	   3. Dynamically allocate array from step 2
	   4. Prompt user for number of slices of pie eaten for each person
	   5. Sort array using bubble sort
	   6. Display sorted array
	   7. Calculate mode by going through sorted array and counting most
	   		occurrences of each number
	   8. Display mode and how many people ate the same number of slices of pie
	   9. Delete dynamically allocated memory
*/

#include <iostream>

using namespace std;

// function prototypes
void sortArray(int *);
void calculateMode(int *);

// constants
const int MAX_PEOPLE = 30;

int main()
{
	int *slices_ptr;	// dynamically allocate an array
	int mode;			// most common number of slices eaten
	
	// dynamically allocate array of size of user input
	slices_ptr = new int[MAX_PEOPLE];
	
	// get user input for number of slices eaten
	for(int i = 0; i < MAX_PEOPLE; i++)
	{
		cout << "Slices of pie eaten by person " << i + 1 << ": ";
		cin >> *(slices_ptr + i);
	}
	// call functions
	sortArray(slices_ptr);
	calculateMode(slices_ptr);
	
	// free dynamically allocated memory
	delete [] slices_ptr;
	slices_ptr = nullptr;

	return 0;
}

//*******************************************************
//						sortArray						*
// Uses bubble sort to sort array of number of slices.	*
// Displays the sorted array.							*
//*******************************************************
void sortArray(int *slices_ptr)
{
	int temp;	// temporary holder for swap
	bool swap;	// flag is true if swap was made
	do
	{
		swap = false;
		for (int count = 0; count < (MAX_PEOPLE - 1); count++)
		{
			// swap if current score is greater than the next score
			if (*(slices_ptr + count) > *(slices_ptr + count + 1))
			{
				temp = *(slices_ptr + count);
				*(slices_ptr + count) = *(slices_ptr + count + 1);
				*(slices_ptr + count + 1) = temp;
				swap = true;
			}
		}
	} while (swap);
	
	// display array after sorting
	cout << "\nSorted array:\n";
	for(int i = 0; i < MAX_PEOPLE; i++)
	{
		cout << *(slices_ptr + i) << " ";
	}
}

//*******************************************************
//					calculateMode						*
// Calculates the mode (most occurrences) by keeping	*
// count of how many times a number occurs in the array	*
// and updating the mode if the new count is greater	*
// than the previous count of most occurrences. When new*
// number occurs in the array, count starts over until	*
// the array is completely traversed. The number of		*
// people and mode is displayed.						*
//*******************************************************
void calculateMode(int *slices_ptr)
{
	int count = 0;		// keep count of a number's occurrence
	int count_mode = 0;	// current mode while traversing array
	int mode;			// final mode after traversing array
	
	// traverse through sorted array of number of slices
	for(int i = 0; i < MAX_PEOPLE; i++)
	{
		count++;	// count occurrences of current number of slices
		// if the next number of slices is different from
		// current number of slices
		if(*(slices_ptr + i) < *(slices_ptr + i + 1))
		{
			// new mode
			if(count > count_mode)
			{
				count_mode = count;	// mode is the biggest occurence
				mode = *(slices_ptr + i);
			}
			count = 0;	// reset count for next new number in array
		}
	}
	// display how many people and mode
	cout << "\nMost people (" <<count_mode << ") eat " << mode
		<< " slices of pie.\n";
}
