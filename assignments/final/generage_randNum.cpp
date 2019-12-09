#include <iostream>
#include <fstream>
#include <vector>
#include <random>
using namespace std;

void generateRandomNumbers(vector<int> &rands, int start, int end) {
    std::ios::sync_with_stdio(false);
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<> dis(start, end);
    generate(rands.begin(), rands.end(), bind(dis, ref(mt)));
}

int main(){
  ofstream outFile("randNum.file");
  vector<int> test(100), hundredK(100000), fivehundredK(500000), million(1000000);

  generateRandomNumbers(test, 0, 20);

  for (auto i = test.begin(); i != test.end(); ++i)
    outFile << *i << endl;

  return 0;
}
