
#include<bits/stdc++.h> 
using namespace std; 


int stringLen(string str) 
{ 
	
	map<int, int> m; 
	
	 
	m[0] = -1; 
	
	int count_0 = 0, count_1 = 0; 
	int res = 0; 
	for (int i=0; i<str.size(); i++) 
	{ 
		
		if (str[i] == '0') 
			count_0++; 
		else
			count_1++; 
		
		if (m.find(count_1 - count_0) != m.end()) 
			res = max(res, i - m[count_1 - count_0]); 
			
				 
		else
			m[count_1 - count_0] = i; 
	} 

	return res; 
} 


int main() 
{ 
	string str = "101001000"; 
	cout << "Length of longest balanced"
			" sub string = "; 
	cout << stringLen(str); 
	return 0; 
}

