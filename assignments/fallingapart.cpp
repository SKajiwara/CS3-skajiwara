#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
using namespace std;

void get_num(int &num)
{
	cin >> num;
	cin.ignore();
}
void get_line(vector<int> &vect, int N)
{
	string temp;
	getline (cin, temp);
	istringstream iss(temp);
	int sub=0;
	for(int i=0; i<N; i++)
	{
		iss >> sub;
		vect.push_back(sub);
	} 
}
void sort_vector(vector<int> &vect)
{
	sort(vect.begin(), vect.end());
}
string falling_apart(int &N, int A, int B, vector<int>& V)
{
	sort_vector(V);
	for(int i=0; i<N; i++)
	{
		if (i%2 == 0)
		{
			A += V.back();	
		}
		else
		{
			B += V.back();
		}
		V.pop_back();
	}
	return to_string(A) + " " + to_string(B);
}
int main(int argc, char *argv[])
{
	int num = 0;
	int Alice = 0;
	int Bob = 0;
	vector<int> vect;
	
	if (argc > 1 && strncmp(argv[1], "test", 4) == 0)
	{
		int test1[] = { 5, 2, 4, 5, 3 };
		int test2[] = { 3, 100 };
		int test3[] = { 2, 2, 2, 2 };
		int sizes[] = {5, 2, 4};
		vector<int> test_vect1 ( test1, test1 + sizes[0] );
		assert(falling_apart( sizes[0], Alice, Bob, test_vect1) == "11 8" );
		vector<int> test_vect2 ( test2, test2 + sizes[1] );
		assert(falling_apart( sizes[1], Alice, Bob, test_vect2 ) == "100 3" );
		vector<int> test_vect3 ( test3, test3 + sizes[2] );
		assert(falling_apart( sizes[2], Alice, Bob, test_vect3 ) == "4 4");
		cout << "all test cases passed!\n";
	}
	else
	{
		get_num(num);
		get_line(vect, num);
		cout << falling_apart( num, Alice, Bob, vect );
	}
	return 0;
}
