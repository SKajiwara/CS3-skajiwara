#include <iostream>  
#include <unordered_set> 
#include <algorithm>  
using namespace std;  
int main()  
{  
	int i, N,M,cd, count = 0;
	unordered_set<int> ns;
	while( cin >>N>>M && N!=0 && M!=0)
	{
		for (i=N; i>0 && cin>>cd;i--) ns.insert(cd);
		
		//sort(ns.begin(), ns.end());
		
		for (i=0; i<M && cin>>cd && cd!=0;i++)
		{	
			if(binary_search(ns.begin(), ns.end(), cd)&&cd!=ns.end()) 
				count++;
		}
		
    }
	cout << count << endl;
	return 0;  
}  