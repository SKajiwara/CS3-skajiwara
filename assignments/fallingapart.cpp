#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <assert.h>


using namespace std;

/*
void print(vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		cout << input.at(i) << ' ';
	}
}
*/


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
void falling_apart(int &N, int &A, int &B)
{
	vector<int> vect;
	get_num(N);
	get_line(vect, N);
	sort_vector(vect);
	for(int i=0; i<N; i++)
	{
		if (i%2 == 0)
		{
			A += vect.back();	
		}
		else
		{
			B += vect.back();
		}
		vect.pop_back();
	}	
}
void test_falling_apart(int &N, int &A, int &B, int list_test[])
{
	// For assertion
	vector<int> vect(list_test, list_test + N);
	
	sort_vector(vect);
	
	for(int i=0; i<N; i++)
	{
		if (i%2 == 0)
		{
			A += vect.back();	
		}
		else
		{
			B += vect.back();
		}
		vect.pop_back();
	}	
}
void assertion()
{
	int num = 0;
	int A = 0;
	int B = 0;
	int test_list1[] = {5, 2, 4, 5, 3}; 
	num = 5;
	falling_apart(num, A, B, test_list1);
	
	assert(A == 11);
	assert(B == 8);
	A = B = 0;
	
	int test_list2[] = {3, 100};
	num = 2;
	falling_apart(num, A, B, test_list2);
	assert(A == 100);
	assert(B == 3);
	A = B = 0;
	
	int test_list3[] ={2, 2, 2, 2};
	num = 4;
	falling_apart(num, A, B, test_list3);
	assert(A == 4);
	assert(B == 4);
	A = B = 0;

}
int main(int argc, char *argv[])
{
	if (argc > 1 && strncmp(argv[1], "test", 4) == 0)
	{
		assert(answer() == "Hello World!");
		cout << "all test cases passed!\n";
	}
	
	assertion();

	
	int num = 0;
	int Alice = 0;
	int Bob = 0;
	falling_apart();
	cout << Alice << " " << Bob;
	return 0;
}