#include "class.h"
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std::chrono;
auto getTime = [](auto&& func, auto&&... params) {
  const auto& start = high_resolution_clock::now();
  std::forward<decltype(func)>(func)(std::forward<decltype(params)>(params)...);
  const auto& stop = high_resolution_clock::now();
  duration<double> diff = stop - start;
  return diff;
};
void calculate(vector<int> &randNumbers,double &a, double &b, double &c, double &d, double &e, double &f, double &g, double &h, double &i, double &j, double &k, ofstream& answer) {
  for (int i = 0; i < 10; i ++){
    generateRandomNumbers(randNumbers, 0, 20);
    a+=getTime(BubbleSort, randNumbers).count();
    b+=getTime(SelectionSort, randNumbers).count();
    c+=getTime(InsertionSort, randNumbers).count();
    d+=getTime(ShellSort, randNumbers).count();
    e+=getTime(call_QuickSort, randNumbers, 0, randNumbers.size()-1).count();
    f+=getTime(call_MergeSort, randNumbers, 0, randNumbers.size()-1).count();
    g+=getTime(HeapSort, randNumbers).count();
    h+=getTime(AlgorithmHSort, randNumbers).count();
    i+=getTime(AlgorithmHStableSort, randNumbers).count();
    j+=getTime(SequentialSearch, randNumbers, rand() % 10 + 1).count();
    k+=getTime(BinarySearch, randNumbers, rand() % 10 + 1).count();
  }
  answer << "Bubble Sort: " << a/10 << endl;
  answer << "Selection Sort: " << b/10<< endl;
  answer << "Insertion Sort: " << c/10 << endl;
  answer << "Shell Sort: " << d/10 << endl;
  answer << "Quick Sort: " << e/10 << endl;
  answer << "Merge Sort: " << f/10 << endl;
  answer << "Heap Sort: " << g/10 << endl;
  answer << "Algorithm.h Sort: " << h/10 << endl;
  answer << "Algorithm.h Stable Sort: " << i/10 << endl;
  answer << "Sequential Search: " << j/10<< endl;
  answer << "Binary Search: " << k/10<< endl;
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ofstream answer("answer.txt");
  int sizes[3]= {1000, 5000, 10000};
  for ( int n=0; n<3; n++ ) {
    vector<int> randNumbers(sizes[n]);
    double a=0.0,b=0.0,c=0.0,d=0.0,e=0.0,f=0.0,g=0.0,h=0.0,i=0.0,j=0.0,k=0.0;
    calculate(randNumbers,a,b,c,d,e,f,g,h,i,j,k,answer);
  }
  return 0;
}
