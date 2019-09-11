#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>
#include <sstream>
#include <cassert>
#include <cstring>
#include <time.h>
#include <vector>
using namespace std;
string answer( unordered_map<string, string> &dict, const string word )
{
	if ( dict.count(word) == 1 )
		return dict[ word ];
	else 
		return "eh";
}
void test()
{
	unordered_map<string, string> test;
	test.insert(make_pair("Sune", "Shin"));
	test.insert(make_pair("Atama", "Head"));
	test.insert(make_pair("Onaka", "Stomach"));
	test.insert(make_pair("Ashi", "Legs"));
	test.insert(make_pair("Kusa", "Weed"));
	test.insert(make_pair("Shippo", "Tail"));
	test.insert(make_pair("Kitanai", "Dirty"));
	string word = "Shippo";
	assert(answer(test, word) == "Tail");
	word = "Onaka";
	assert(answer(test, word) == "Stomach");
	word = "Sune";
	assert(answer(test, word) == "Shin");
	cout << "All test cases passed" << endl;
}
void kattis()
{
	unordered_map<string, string> dict;
	string line, meaning, word;
	while(getline(cin, line))
	{
		if (!line.empty())
		{
			istringstream iss(line);
			iss >> meaning >> word;
			dict.insert( pair<string, string>(word, meaning) );
		}
		else
			break;
	}
	while( cin >> word )
		cout << answer( dict, word ) << endl;
}
int main(int argc, char *argv[])
{
	if (argc > 1 && strncmp(argv[1], "test", 4) == 0)
		test();
	else
		kattis();
	return 0;
}