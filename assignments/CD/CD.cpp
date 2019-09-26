#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
//g++ -std=c++11 CD.cpp // USE SET
int counter(vector<int>& ns, int& cd, int count)
{
	if( binary_search(ns.begin(), ns.end(), cd)) count++;
	return count;
}
//testing
void kattis()
{
	int i, N,M,cd, count;
    vector<int> ns;
    vector<int>::iterator n;
    while( cin >>N>>M && N!=0 && M!=0)
    {
        count = 0;
        ns.clear();
        for (i=0; i<N&&cin>>cd;i++) ns.push_back(cd);
        n= ns.begin();
        for (i=0; i<M&&cin>>cd;i++) count = counter(ns, cd, count);
        cout << count;
    }
}
void test()
{
	vector<int> test = {1, 5555, 6666, 99999, 100000, 1000000};
	int nums[3] = {5555, 99999, 200000};
	int count = 0;
	assert(counter(test, nums[0],count)==1);
	assert(counter(test, nums[1],count)==1);
	assert(counter(test, nums[2],count)==0);
	cout << "All test cases passed" << endl;

}
int main(int argc, char* argv[])
{
	if (argc > 1 && strncmp(argv[1], "test", 1) == 0)
		test();
	else
		kattis();
	return 0;
}
