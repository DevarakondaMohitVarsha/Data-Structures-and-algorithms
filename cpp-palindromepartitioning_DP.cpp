/* Dynamic Programming Optimized Solution for Palindrome Partitioning Problem

Time Complexity: O(n2) */


#include <limits.h> 
#include <stdio.h> 
#include <string.h>
#include <iostream> 

using namespace std;
int min(int a, int b) { 
	return (a < b) ? a : b; 
} 

/* Returns the minimum number of cuts needed to partition a string 
	such that every part is a palindrome */
int minPalPartion(char* str) 
{ 
	int n = strlen(str); 

	/* Create two arrays to build the solution in bottom-up manner 
	C[i] = Minimum number of cuts needed for a palindrome partitioning 
				of substring str[0..i] 
	P[i][j] = true if substring str[i..j] is palindrome, else false 
	Note that C[i] is 0 if P[0][i] is true */
	int C[n]; 
	bool P[n][n]; 

	int i, j, k, L;

	
	for (i = 0; i < n; i++) { 
		P[i][i] = true; 
	} 

	/* L is substring length. Build the solution in bottom up manner by 
	considering all substrings of length starting from 2 to n. */
	for (L = 2; L <= n; L++) { 
		// For substring of length L, set different possible starting indexes 
		for (i = 0; i < n - L + 1; i++) { 
			j = i + L - 1; 

		
			if (L == 2) 
				P[i][j] = (str[i] == str[j]); 
			else
				P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1]; 
		} 
	} 

	for (i = 0; i < n; i++) { 
		if (P[0][i] == true) 
			C[i] = 0; 
		else { 
			C[i] = INT_MAX; 
			for (j = 0; j < i; j++) { 
				if (P[j + 1][i] == true && 1 + C[j] < C[i]) 
					C[i] = 1 + C[j]; 
			} 
		} 
	} 

	// Return the min cut value for complete string. i.e., str[0..n-1] 
	return C[n - 1]; 
} 

// main function 
int main() 
{ 
	char str[] = "adabbaabbaaca"; 
	cout<<"Min cuts needed for Palindrome Partitioning of "<<str<<" is "<<minPalPartion(str); 
	return 0; 
} 
