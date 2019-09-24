#include <iostream>
#include <cmath>
#include <cassert>// g++ -std=c++11 icpctutorial.cpp
#include <cstring>
using namespace std;
string calculation(const int &a, const double &b, const int &c)
{
	unsigned long int ans = 1;
	switch(c)
	{
		case 1:
			if (b>15) return "TLE";
    		for (int i = 2; i<=b; i++) ans*=i;
			break;
		case 2:
			ans = pow(2, b);
			break;
		case 3:
			ans = pow(b, 4);
			break;
		case 4:
			ans = pow(b, 3);
			break;
		case 5:
			ans = pow(b, 2);
			break;
		case 6:
			ans = static_cast<long double>(ans);
			ans = ceil ( static_cast<long double>(b) * log2(b));
			break;
		default:
			ans = b;
			break;
	}
	if (a<ans) 
		return "TLE";
	else
		return "AC";
}
void kattis()
{	
	int n, m, t;
	cin >> n >> m >>t;
	cout << calculation(n, m, t) << endl;
}
void test()
{
	assert(calculation(10000000, 50, 6) == "AC");
	assert(calculation(10000000, 10000001, 7) == "TLE");
	assert(calculation(1000000000, 15, 1) == "TLE");
}
int main(int argc, char* argv[])
{
	if (argc >1 && strncmp(argv[1], "test", 4) == 0) 
		test();
	else
		kattis();
	return 0;
}