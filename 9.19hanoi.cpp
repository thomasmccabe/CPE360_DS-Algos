#include<iostream>
using namespace std;

void hanoi(int n, char S, char A, char D)
{
	//Base case
	if(n == 1)
		cout << "Move disk " << n << " from " << S << " ---> " << D << endl;
	else {
		//Recursive step: goal is to reduce the poblem to the base case
		hanoi(n-1, S, D, A);
		cout << "Move disk " << n << " from " << S << " ---> " << D << endl;
		hanoi(n-1, A, S, D);
	}
}

int main()
{
	int n;
	char S = 'S', A = 'A', D = 'D';

	cout << "Enter number of disks: " << endl;
	cin >> n;

	hanoi(n, S, A, D);

	return 1;
}