#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iterator>
using namespace std;
void test()
{
	cout << "a";
}
void kattis()
{
	int i, Fnum, Fmax, in, ans, temp, count = 1;
	vector<int> list;
	vector<int>::iterator it, head;
	cin >> Fnum >> Fmax;
	for ( i=0; i<Fnum; i++ )
	{	
		cin >> in;
		list.push_back( in );
	}
	it = list.begin();
	while( distance(it,list.end())>1 && distance(it,list.end())>=count )
	{
		ans = *it;
		head = it+1;
		temp = 1;
		while (ans < Fmax && distance(head,list.end())>= 1)
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
	cout << count << endl;
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