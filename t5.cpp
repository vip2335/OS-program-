
#include <bits/stdc++.h> 
using namespace std; 

 
int getPosOfRightmostSetBit(int n) 
{ 
	return log2(n & -n); 
} 


unsigned int toggleLastKBits(unsigned int n, 
							unsigned int k) 
{ 
	
	unsigned int num = (1 << k) - 1; 

	
	return (n ^ num); 
} 

unsigned int incrementByOne(unsigned int n) 
{ 
	 
	int k = getPosOfRightmostSetBit(~n); 

	
	n = ((1 << k) | n); 

	
	if (k != 0) 
		n = toggleLastKBits(n, k); 

	
	return n; 
} 

 
int main() 
{ 
	unsigned int n = 15; 
	cout << incrementByOne(n); 
	return 0; 
} 

