/* hw3pc2_test_scores2.cpp - Find the average of test scores using names
   Author:  Karina Elias
   Module:	3
   Project:	Homework 3 - Programming Challenge 2
   
   Problem Statement: Modify the program above to allow the user to enter
	name-score pairs. For each student taking the test, the user should enter a
	string representing name of the student, followed by an integer representing
	the student's score. Modify both the sorting and average-calculating
	functions so they take arrays of objects, with each object containing the
	name and score of a single student. In traversing the arrays, use pointers
	than array indices.
	When finished with the array, use the delete operator to de-allocate the
	array.
	Include a class definition for a student, including a constructor, getters
	and setters for the name and score, and a destructor.
   
   Algorithm / Plan:
	   1. Use code from hw3pc1_test_scores2.cpp
	   2. Create Student class with name and score data members, getters,
	   		setters, constructor, and destructor
	   3. Update code for user to input students' names
	   4. Update pointer for Student class score
	   5. Update function printResults to include name display
*/

#include <iostream>
#include <iomanip>	// setprecision

using namespace std;

//*******************************************************
//					Student class						*
// Includes name and test score, constructor, destructor*
// and getters/setters.									*
//*******************************************************
class Student
{
	public:
		// data members
		string name;
		int score;
	
		// constructor
		Student()
		{
			name = "Name";
			score = 0;
		}
		
		// destructor
		~Student() { }
	
		// getters
		string getName() { return name; }
		int getScore() { return score; }
		
		// setters
		void setName(string name)
		{
			this->name = name;
		}
		
		void setScore(int score)
		{
			this->score = score;
		}
};

// function prototypes
void sortAscendingOrder(Student *, int);
double calculateAverageScore(Student *, int);
void printResults(Student *, int, double);

int main()
{
	Student *scores_ptr;		// dynamically allocate an array
	double average;				// average of all test scores
	int total_number_of_scores;	// total scores from user
	
	cout << "Enter total number of test scores: ";
	cin >> total_number_of_scores;
	
	// dynamically allocate array of size of user input
	scores_ptr = new Student[total_number_of_scores];
	
	// Get each test score from user
	for(int i = 0; i < total_number_of_scores; i++)
	{
		cout << "Enter name of student " << i + 1 << ": ";
		cin >> (scores_ptr + i)->name;
		do
		{
			cout << (scores_ptr + i)->name << "'s score: ";
			cin >> (scores_ptr + i)->score;
			// input validation: does not accept negative scores
			if((scores_ptr + i)->score < 0)
			{
				cout << "Score must be positive. Try again.\n";
			}
		} while ((scores_ptr + i)->score < 0);
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
void sortAscendingOrder(Student *scores_ptr, int total_number_of_scores)
{
	Student temp;	// temporary holder for swap
	bool swap;		// flag is true if swap was made
	do
	{
		swap = false;
		for (int count = 0; count < (total_number_of_scores - 1); count++)
		{
			// swap if current score is greater than the next score
			if ((scores_ptr + count)->score > (scores_ptr + count + 1)->score)
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
double calculateAverageScore(Student *scores_ptr, int total_number_of_scores)
{
	double total_sum;	// total sum of all scores
	// add up all scores
	for(int i = 0; i < total_number_of_scores; i++)
	{
		total_sum += (scores_ptr + i)->score;
	}
	// calculate and return the average
	return total_sum / total_number_of_scores;
}

//*******************************************************
//					printResults						*
// Displays the total number of scores, the scores in	*
// ascending order, and the average of all the scores.	*
//*******************************************************
void printResults(Student *scores_ptr, int total_number_of_scores,
					double average)
{
	cout << "\n======Test Scores======" << endl;
	cout << "Number of scores: " << total_number_of_scores << endl;
	cout << "Scores in ascending orders:" << endl;
	// print all names and scores
	for(int i = 0; i < total_number_of_scores; i++)
	{
		cout << left << setw(8) << setfill(' ');
		cout << (scores_ptr + i)->name;
		cout << (scores_ptr + i)->score << endl;
	}
	// round average to 2 decimal places
	cout << fixed << showpoint << setprecision(2);
	cout << "Average: " << average << endl;
}
