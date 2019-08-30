#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <iterator>
#include <list>

using namespace std;

void print(vector<int> const &input)
{
	for (int i = 0; i < input.size()-1; i++) {
		cout << input.at(i) << ' ';
	}
}

int func(int a)
{
	return a * 2;
}

int main()
{
	
	cout << func(5) << endl;
	int test1[] = { 2, 2, 2, 2 };
	vector<int> test_vect (test1, test1 + 5);
	vector<int> vect1({10, 20, 30});
	
	print(vect1);
	
	
	print(test_vect);
	 
	return 0;
}