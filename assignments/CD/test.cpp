#include <iostream>  
#include <vector>  
#include <algorithm>  
  
using namespace std;  
  
int main()  
{  
  vector<int> v = {3, 1, 4, 6, 5};  
  
  if (binary_search(v.begin(), v.end(), 4)) {  
    cout << "4 found" << endl;  
  }  
  else {  
    cout << "4 not found" << endl;  
  }  
    
  return 0;  
}  