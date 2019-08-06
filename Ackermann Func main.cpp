// Jon White
// Ackerman function
// https://en.wikipedia.org/wiki/Ackermann_function

// Inspired to explore this topic from
// Computerphile video: The Most Difficult Program to Compute?
// https://www.youtube.com/watch?v=i7sm9dzFtEI

// Stack overflow occurs at ack(4,1)
// The value for that pair should be 65533
// Everything else is fine up until that point.

// UPDATE: Running Visual Studio in Release mode allows
// the computation of ack(4,1), but then we run into an
// unhandled exception.
// Which is finse since calculating ack(4,2) could take
// longer than the time left until the Big Crunch. lol

#include <iostream>

using namespace std;

int ackermann(int, int);

int main() {

	int ackerNum = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ackerNum = ackermann(i, j);
			cout << "\nThe Ackerman number for the pair (" << i << "," << j << ") is: " << ackerNum;
		}
	}

	return 0;
}

int ackermann(int m, int n) {
	
	int ackNum = 0;

	if (m == 0) {
		ackNum = n + 1;
	}
	else if (m > 0 && n == 0) {
		ackNum = ackermann(m - 1, 1);
	}
	else if (m > 0 && n > 0) {		//m>0 check here is probably not needed b/c the check is already made in the previous else-if block
		ackNum = ackermann(m - 1, ackermann(m, n - 1));
	}
	else cout << "\n!!! ERROR !!!\n";

	return ackNum;
}