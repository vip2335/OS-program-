
#include <bits/stdc++.h> 
using namespace std; 


int getSubstringWithEqual012(string str) 
{ 
	int n = str.length(); 


	map< pair<int, int>, int > mp; 
	mp[make_pair(0, 0)] = 1; 
 
	int zc = 0, oc = 0, tc = 0; 

	
	int res = 0; 
	for (int i = 0; i < n; ++i) 
	{ 
		if (str[i] == '0') zc++; 
		else if (str[i] == '1') oc++; 
		else tc++; 
		pair<int, int> tmp = make_pair(zc - oc, 
									zc - tc); 

		
		res = res + mp[tmp]; 

	 
		mp[tmp]++; 
	} 

	return res; 
} 


int main() 
{ 
	string str = "0102010"; 
	cout << getSubstringWithEqual012(str) << endl; 
	return 0; 
} 

