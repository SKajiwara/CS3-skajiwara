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
		vector<int> test_vect1 (test1, test1 + 5);
		num = 5;
		assert(falling_apart( num, Alice, Bob, test_vect1 ) == "11 8" );
		vector<int> test_vect2 (test2, test2 + 2);
		num = 2;
		assert(falling_apart( num, Alice, Bob, test_vect2 ) == "100 3" );
		vector<int> test_vect3 (test3, test3 + 4);
		num = 4;
		assert(falling_apart( num, Alice, Bob, test_vect3 ) == "4 4");
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
