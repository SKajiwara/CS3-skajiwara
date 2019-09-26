#include <iostream> // for the final project
#include <vector>
#include <random>
#include <iterator>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <functional>
using namespace std;
/*
template<class T> // worst case O(n). Best O(1). Average O(n/2)
int sequentialSearch(const vector<T> & v, T key) 
{
    int index = 0;
    while (index < v.size()) 
    {
        if (v[index] == key) // found our element; key comparison that controls the loop
            return index;
        else
            index ++;
    }
    return -1;
}
*/
void generateRandomNumbers(vector<int> &rands, int count, int start, int end)
{
	random_device rd;
	mt19937 mt(rd()); //create very random numbers
	uniform_int_distribution<> dis(start, end); // numbers between start and end inclusive
	generate(rands.begin(), rands.end(), bind( dis, ref(mt) ) );
}
int main()
{
	vector<int> nums(20);
	generateRandomNumbers(nums, 20, 0, 20);
	cout << nums << endl;

	return 0;
}

//binary_search() - use sort(v.begin(), v.end()) first to sort.