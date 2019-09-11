#include <iostream>
#include <cassert>
using namespace std;

string answer(int x)
{
	if (x%2==0)
		return " is even";
	else
		return " is odd";
}
void test()
{
	assert(answer(0) == " is even");
	assert(answer(99999) == " is odd");
	
	cout << "all test cases passed" << endl;
}
void kattis()
{
	int num, x;
	cin >> num;
	for (int i=0; i<num; i++)
	{
		cin >> x;
		cout << x << answer(x) << endl;
	}
}
int main(int argc, char* argv[])
{
	if (argc > 1 && strncmp(argv[1], "test", 4) == 0 )
		test();
	else
		kattis();
	
	return 0;
}

//cat sample.in | ./a.out
//cat sample.in | ./a.out | diff -sample.ans