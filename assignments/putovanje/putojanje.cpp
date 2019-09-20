#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iterator>
using namespace std;
int answer(vector<int>& list, const int Fmax)
{
	int ans, temp = 0;
	int count = 0;
	vector<int>::iterator head, it = list.begin();
	// When capacity C is 1 and there is fruit weights 1 in Forest 
	if (Fmax==1 && find(list.begin(), list.end(), 1) != list.end()) return 1;
	while( (distance(it,list.end())>1 && distance(it,list.end())>=count) )
	{
		ans = *it;
		head = it+1;
		if( Fmax > ans) temp = 1;
		while (distance(head,list.end())>= 1)
		{
			if( Fmax >= (ans + *head)) 
			{	
				ans += *head;
				temp++;
		
				head++;
			}
			else head++;
		}
		if (temp>count) count = temp;
		it++;
	}
	return count;
}
void test()
{
	vector<int> test = {4, 5, 3, 1, 6, 3, 2, 4, 1, 4, 5, 4, 2, 1, 4};
	cout << answer(test, 1);
	test = {4, 5, 3, 1, 6, 3, 2, 4, 1, 4, 5, 4, 2, 1, 4};
	assert(answer(test, 10) == 5);
	test = {8};
	assert(answer(test, 5 ) == 0);
	
}
void kattis()
{
	int i, Fnum, Fmax, in;
	vector<int> list;
	cin >> Fnum >> Fmax;
	for ( i=0; i<Fnum&&cin >> in; i++ ) list.push_back( in );
	cout << answer(list, Fmax)<< endl;
}
int main(int argc, char* argv[])
{
	if(argc >1 && strncmp(argv[1], "test", 4)==0)
		test();
	else
		kattis();
	return 0;
}

//cat putovanje.1.in | ./a.out | diff - putovanje.1.ans