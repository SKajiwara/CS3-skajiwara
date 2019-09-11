#include <iostream>
#include <string>
using namespace std;

int main()
{	
	bool state = true;
	string word, meaning;
	while(state)
	{
		getline(cin, word)
		if (!word.empty()||!meaning.empty())
			cout  << word << " " << meaning << endl;
		else
			cout << "empty" << endl;
			
   }  
 
	return 0;
}