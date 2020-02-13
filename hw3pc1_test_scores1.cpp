/* hw3pc1_test_scores1.cpp - Find the average of test scores
   Author:  Karina Elias
   Module:	3
   Project:	Homework 3 - Programming Challenge 1
   
   Problem Statement: Write a program that dynamically allocates an array large
   	enough to hold a user-defined number of test scores.  Once all of the scores
	are entered the array should be passed to a function that sorts them in
	ascending order.  Another function should be called that calculates the
	average score.  The program should then display the sorted list of scores
	and the average with appropriate headings.  Use pointer notation rather than
	array notation whenever possible.
	When finished with the array, use the delete operator to de-allocate the
	array.
	Input Validation:  Do not accept negative test scores
   
   Algorithm / Plan:
	   1. Declare pointer for array
	   2. Prompt user for total number of scores to be entered
	   3. Dynamically allocate array from step 2
	   4. Prompt user for each score using a for loop
	   5. Check that score is positive (score > 0)
	   6. Use bubble sort to swap scores and sort in ascending order
	   7. Calculate the average by adding up all the scores and dividing
	   		the total sum by the number of test scores
	   8. Display the sorted scores and the average
	   9. Delete dynamically allocated memory
*/

using namespace std;

#include <iostream>
#include <iomanip>	// setprecision

// function prototypes
void sortAscendingOrder(double *, int);
double calculateAverageScore(double *, int);
void printResults(double *, int, double);

int main() {
	
	double *scores_ptr;			// dynamically allocate an array
	double average;				// average of all test scores
	int total_number_of_scores;	// total scores from user
	
	cout << "Enter total number of test scores: ";
	cin >> total_number_of_scores;
	
	// dynamically allocate array of size of user input
	scores_ptr = new double[total_number_of_scores];
	
	// Get each test score from user
	for(int i = 0; i < total_number_of_scores; i++)
	{
		do
		{
			cout << "Enter score " << i + 1 << ": ";
			cin >> *(scores_ptr + i);
			// input validation: does not accept negative scores
			if(*(scores_ptr + i) < 0)
			{
				cout << "Score must be positive. Try again.\n";
			}
		} while (*(scores_ptr + i) < 0);
	}
	
	// call functions
	sortAscendingOrder(scores_ptr, total_number_of_scores);
	average = calculateAverageScore(scores_ptr, total_number_of_scores);
	printResults(scores_ptr, total_number_of_scores, average);
	
	// free dynamically allocated memory
	delete [] scores_ptr;
	scores_ptr = nullptr;
	
	return 0;
}

//*******************************************************
//					sortAscendingOrder					*
// Sorts test scores in ascending (smaller->larger)		*
// order using bubble sort. The parameters are the		*
// scores and total number of scores input from the user*
//*******************************************************
void sortAscendingOrder(double *scores_ptr, int total_number_of_scores)
{
	int temp;	// temporary holder for swap
	bool swap;	// flag is true if swap was made
	do
	{
		swap = false;
		for (int count = 0; count < (total_number_of_scores - 1); count++)
		{
			// swap if current score is greater than the next score
			if (*(scores_ptr + count) > *(scores_ptr + count + 1))
			{
				temp = *(scores_ptr + count);
				*(scores_ptr + count) = *(scores_ptr + count + 1);
				*(scores_ptr + count + 1) = temp;
				swap = true;
			}
		}
	} while (swap);
}

//*******************************************************
//				calculateAverageScore					*
// Calcualte the average by adding up all the scores and*
// dividing it by the total number of scores. The		*
// parameters are the scores and the total number of	*
// scores. Returns the average.							*
//*******************************************************
double calculateAverageScore(double *scores_ptr, int total_number_of_scores)
{
	double total_sum;	// total sum of all scores
	// add up all scores
	for(int i = 0; i < total_number_of_scores; i++)
	{
		total_sum += *(scores_ptr + i);
	}
	// calculate and return the average
	return total_sum / total_number_of_scores;
}

//*******************************************************
//					printResults						*
// Displays the total number of scores, the scores in	*
// ascending order, and the average of all the scores.	*
//*******************************************************
void printResults(double *scores_ptr, int total_number_of_scores,
					double average)
{
	cout << "\n======Test Scores======" << endl;
	cout << "Number of scores: " << total_number_of_scores << endl;
	cout << "Scores in ascending orders:" << endl;
	// print all scores
	for(int i = 0; i < total_number_of_scores; i++)
	{
		cout << i + 1 << ": " << *(scores_ptr + i) << endl;
	}
	// round average to 2 decimal places
	cout << fixed << showpoint << setprecision(2);
	cout << "Average: " << average << endl;
}
