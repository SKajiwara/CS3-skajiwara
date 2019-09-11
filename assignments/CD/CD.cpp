#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int answer()
{
	
	
	

	int ans=0;
	return ans;
}
void kattis()
{
	int i, N, M, temp;
	cin >> N >> M;
	
	if (N<M) //SWAP FUNCTION
	{
		N = temp;
		N = M;
		M = temp;
	}
	
	for (i=0; i < N && cin >> temp; i++)
		
	



	answer();
}
void test()
{
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