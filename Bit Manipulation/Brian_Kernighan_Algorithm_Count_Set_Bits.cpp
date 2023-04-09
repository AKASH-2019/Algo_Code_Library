// compute number of different bits...................
// CF -> 467B


#include <bits/stdc++.h>
using namespace std;


int solve(int A, int B)
{
	int XOR = A ^ B;
  	cout<<"org "<<XOR<<endl;
	// Check for 1's in the binary form using
	// Brian Kernighan's Algorithm
	int count = 0;
	while (XOR) {
		XOR = XOR & (XOR - 1);
		count++;
	}
	return count;
}

// Driver code
int main()
{
	int A = 12, B = 15;
	// 12 = 1100 & 15 = 1111
	int result = solve(A, B);
	cout << "Number of different bits : " << result;

	return 0;
}
