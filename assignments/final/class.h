#include <vector>
using namespace std;
void generateRandomNumbers(vector<int> &rands, int start, int end);
void BubbleSort(vector<int> v);
void SelectionSort(vector<int> v);
void InsertionSort(vector<int> v);
void insertionSort2(vector<int> &v, int start, int incr);
void ShellSort(vector<int> v);
int partition(vector<int> &v, int left, int right);
void QuickSort(vector<int> &v);
void call_QuickSort(vector<int> v, int left, int right);
void merge(vector<int> &v, int left, int mid, int right);
void MergeSort(vector<int> &v, int left, int right);
void call_MergeSort(vector<int> v, int left, int right);
void Swap(vector<int>& v, vector<int>::size_type i, vector<int>::size_type j);
void Sift(vector<int>& v, const vector<int>::size_type heapSize, const vector<int>::size_type siftNode);
void MakeInitialHeap(vector<int>& v);
void HeapSort(vector<int> v);
void AlgorithmHSort(vector<int> v);
void AlgorithmHStableSort(vector<int> v);

void SequentialSearch(const vector<int> & v, int key);
void BinarySearch(const vector<int> &v, int key);
void BinarySearchTree();
