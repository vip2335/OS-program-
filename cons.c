
#include <iostream> 
using namespace std; 

 
int minimum(int a, int b, int c) 
{ 
	return min(min(a, b), c); 
} 


int findMinSum(int arr[], int n) 
{ 
	 
	int sum[n]; 

	
	sum[0] = arr[0]; 
	sum[1] = arr[1]; 
	sum[2] = arr[2]; 

	for (int i=3; i<n; i++) 
	sum[i] = arr[i] + 
			minimum(sum[i-3], sum[i-2], sum[i-1]); 

	return minimum(sum[n-1], sum[n-2], sum[n-3]); 
} 


int main() 
{ 
	int arr[] = {1, 2, 3, 20, 2, 10, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Min Sum is " << findMinSum(arr, n); 
	return 0; 
} 

