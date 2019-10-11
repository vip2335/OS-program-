
#include <bits/stdc++.h> 
using namespace std; 


void generateString(int A, int B) 
{ 
	string rt; 
	while (0 < A || 0 < B) { 

		
		if (A < B) { 
			if (0 < B--) 
				rt.push_back('b'); 
			if (0 < B--) 
				rt.push_back('b'); 
			if (0 < A--) 
				rt.push_back('a'); 
		} 

		
		else if (B < A) { 
			if (0 < A--) 
				rt.push_back('a'); 
			if (0 < A--) 
				rt.push_back('a'); 
			if (0 < B--) 
				rt.push_back('b'); 
		} 

		else { 
			if (0 < A--) 
				rt.push_back('a'); 
			if (0 < B--) 
				rt.push_back('b'); 
		} 
	} 
	cout << rt; 
} 

int main() 
{ 
	int A = 2, B = 6; 
	generateString(A, B); 

	return 0; 
} 

