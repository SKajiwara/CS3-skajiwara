#include <iostream>  
#include <vector> 
#include <algorithm>  
using namespace std;  
int main()  
{  
	int i, N,M,cd;
	while( cin >>N>>M && N!=0 && M!=0 )
	{
		vector<int> ns;
		vector<int>::iterator it;
		for ( i=0; i<(N+M);i++ )
		{	
			cin >> cd;
			ns.push_back(cd);
		}
		sort(ns.begin(), ns.end());
		it = unique(ns.begin(), ns.end());
		cout << distance(it, ns.end());
	}
	return 0;  
}  