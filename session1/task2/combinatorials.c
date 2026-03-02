#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int factorial(int n);

int main(int argc, char **argv)
{
	/*
	The program should accept a command line argument as follows:
	./combinatorials n C r
	./combinatorials n P r

	where n and r are both positive integers, and r is always less than or equal to n.

	for example:
	./combinatorials 7 C 2

	Your program should then calculate and print out the correct result

	nCr should return the total combinations of r items out of n.
	This is calculated by: n! / (r! (n - r)!)

	nPr should return the total permutations of r items out of n.
	This is calculated by: n! / (n-r)!

	Add appropriate validation to your program to make your code robust.

	You should try and use functions to write your program.

	*/
	if(argc!=4)
	{
		printf("Usage:\n    ./combinatorials n C k\n    ./combinatorials n P k");
		return 1;
	}
	int n=atoi(argv[1]);
	int k=atoi(argv[3]);
	if(strcmp(argv[2],"C")==0)
	{
		int nCr=factorial(n)/(factorial(r)*factorial(n-r));
		printf("%iC%i=%i",n,k,nCr);
	}
	else if(strcmp(argv[2],"P")==0)
	{
		int nPr=factorial(n)/factorial(n-r);
		printf("%iP%i=%i",n,k,nPr);
	}
}

/**
 * @brief recursively calculates the factorial of an integer n.
 * 
 * @param n number to find factorial of.
 * @return int n factorial.
 */
int factorial(int n)
{
	// the base case - this determines when the recursion should stop
	if(n==0)
	{
		return 1;
	}

	return n*factorial(n-1);
}