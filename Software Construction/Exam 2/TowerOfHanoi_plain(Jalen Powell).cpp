/*
 * Jalen Powell
 * 03/26/2021
 * Midterm Exam 2
 * Software Construction COMP2710
 * Instructor: Xuechao Li @ Auburn University
 */

#include <iostream>
#include <time.h>
using namespace std;

void moveOneDisk(int n, char startPeg, char endPeg)
{

	cout << "Move Disk" << n << " from " << startPeg << " to " << endPeg << endl;
}

// tower of HANOI function implementation
void moveDisk(int n, char Original, char Aux, char Dest)
{
	/*
 * Please implement this function with a given I/O format.
 *
 */
	if (n == 1)
	{
		moveOneDisk(n, Original, Dest);
	}
	else
	{
		moveDisk(n - 1, Original, Dest, Aux);
		moveOneDisk(n, Original, Dest);
		moveDisk(n - 1, Aux, Original, Dest);
	}
}

// main program
int main()
{
	int n;
	time_t start, end;

	cout << "Enter the number of disks:";
	cin >> n;

	// calling the moveDisk
	time(&start);
	moveDisk(n, 'A', 'B', 'C');
	time(&end);

	double elapse = difftime(end, start);
	cout << "The elapsed time is " << elapse << " seconds"
		 << " for moving " << n << " disks " << endl;

	return 0;
}
