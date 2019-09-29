// Jon White
//
// Program for Fibonacci Numbers
// Compares the runtime of Recursive way and
// stepping through the sequence number by number
//
// NOTE: For this program the Sequence begins with 0
// NOTE: Changed from int to long b/c of overflow.
//
// Fibonacci Sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...
//
// NOTE: As it is now, can only calculate up to the 47th Fibonacci Number before experiencing overflow

#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

long seriesFibonacci(int, int &);
long recursiveFibonacci(int, unsigned long long int &);

int main() {

	//cout << setw(10) << "n-th term" << setw(20) << "Series" << setw(25) << "Series Runtime(ns)" << setw(20) << "Recursive" << setw(25) << "Recursive Runtime(ns)" << endl;
	
	// Shows the number of steps taken to get to n-th Fibonacci Number instead of Runtimes
	cout << setw(10) << "n-th term" << setw(20) << "Series" << setw(25) << "Series Counter" << setw(20) << "Recursive" << setw(25) << "Recursive Counter" << endl;
	cout << setw(10) << "---------" << setw(20) << "------" << setw(25) << "------------------" << setw(20) << "---------" << setw(25) << "---------------------" << endl;

	for (int n = 1; n <= 50; n++) {

		int counterS = 0;
		unsigned long long int counterR = 0;

		// Variables
		long seriesN = 0;
		long recurN = 0;

		// Method 1 ----------------------------------------------------------------------------------------------
		auto start = high_resolution_clock::now();

		seriesN = seriesFibonacci(n, counterS);								// Stepping through Fibonacci Series

		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);			// Execution time

		// Method 2 ----------------------------------------------------------------------------------------------
		
		auto start2 = high_resolution_clock::now();

		recurN = recursiveFibonacci(n, counterR);							// Recursive Method
		
		auto stop2 = high_resolution_clock::now();
		auto duration2 = duration_cast<nanoseconds>(stop2 - start2);		// Execution time

		// Output
		//cout << setw(10) << n << setw(20) << seriesN << setw(25) << duration.count() << setw(20) << recurN << setw(25) << duration2.count() << endl;

		cout << setw(10) << n << setw(20) << seriesN << setw(25) << counterS << setw(20) << recurN << setw(25) << counterR << endl;

	}

	system("pause");		// Bad practice, but works for this project

	return 0;
}

// Function to go through Fibonacci Series up to n number of terms
long seriesFibonacci(int n, int &counterS) {
	long fib1 = 0;
	long fib2 = 1;
	long nextTerm = 0;
	
	if (n == 1) {
		counterS++;
		return 0;
	}
	else if (n == 2) {
		counterS++;
		return 1;
	}
	else {
		// The Loop for the Fibonacci Sequence -  Only works if n > 2
		for (int i = 2; i < n; i++) {
			counterS++;
			nextTerm = fib1 + fib2;
			fib1 = fib2;
			fib2 = nextTerm;
		}
	}

	return nextTerm;
}

// Function to Recursively calculate Fibonacci Numbers
long recursiveFibonacci(int n, unsigned long long int &counterR) {
	if (n == 1) {
		counterR++;
		return 0;
	}
	else if (n == 2) {
		counterR++;
		return 1;
	}
	else {
		return (recursiveFibonacci(n - 1, counterR) + recursiveFibonacci(n - 2, counterR));
	}

	return n;
}
