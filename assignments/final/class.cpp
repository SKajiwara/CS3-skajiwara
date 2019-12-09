#include "class.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <iterator>
#include <chrono>
#include <algorithm>
using namespace std;
void generateRandomNumbers(vector<int> &rands, int start, int end) {
    std::ios::sync_with_stdio(false);
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<> dis(start, end);
    generate(rands.begin(), rands.end(), bind(dis, ref(mt)));
}
void BubbleSort(vector<int> v) {
  bool sorted;
  for(int pass=0; pass<v.size()-1; pass++) {
    sorted = true;
    for (int i=1; i<v.size()-pass; i++) {
      if (v[i-1] > v[i]) {
        swap(v[i-1], v[i]);
        sorted = false;
      }
    }
    if (sorted)
      break;
  }
}
void SelectionSort(vector<int> v) {
  for (int i=0; i<v.size()-1; i++) {
    int minIndex = i;
    for(int j=i+1; j < v.size(); j++) {
      if (v[j] < v[minIndex])
        minIndex = j;
    }
    if (v[minIndex] != v[i])
      swap(v[minIndex], v[i]);
  }
}
void InsertionSort(vector<int> v){
  for(int i=1; i< v.size(); i++) {
    for(int j=i; (j > 0) && (v[j] < v[j-1]); j--)
      swap(v[j], v[j-1]);
    }
}
void insertionSort2(vector<int> &v, int start, int incr) {
    for(int i=start+incr; i<v.size(); i+=incr)
        for(int j=i; (j >=incr) && v[j] < v[j-incr]; j-=incr)
            swap(v[j], v[j-incr]);
}
void ShellSort(vector<int> v) {
  for (int i=v.size()/2; i>2; i/=2)
    for(int j=0; j<i; j++)
      insertionSort2(v, j, i);
  insertionSort2(v, 0, 1);
}
int partition(vector<int> &v, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = v[pivotIndex];
    int i = left, j = right;
    int temp;
    while(i <= j) {
        while(v[i] < pivotValue) {
            i++;
        }
        while(v[j] > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}
void QuickSort(vector<int> &v, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(v, left, right);
        QuickSort(v, left, pivotIndex - 1);
        QuickSort(v, pivotIndex, right);
    }
}
void call_QuickSort(vector<int> v, int left, int right){
  QuickSort(v, left, right);
}
void merge(vector<int> &v, int left, int mid, int right) {

    int i, j, k;
    int n1 = mid - left + 1;
    int n2 =  right - mid;

    vector<int> L(n1); // auxiliary vector
    vector<int> R(n2); // auxiliary vector

    // copy data to temp Left and Right vectors
    for(i=0; i<n1; i++)
        L[i] = v[left+i];

    for (j=0; j<n2; j++)
        R[j] = v[mid+1+j];

    // merge the temp vectors back into v
    i = 0;
    j = 0;
    k = left; // initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        }
        else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
    // copy the remaining elements of L vector if there's any
    while(i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }
    // copy the remaining elements of R vector if there's any
    while(j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}
void MergeSort(vector<int> &v, int left, int right){
  if (left < right) { // general case
    int mid = left+(right-left)/2; // same as (left+right)/2 but avoid overflow
    MergeSort(v, left, mid);
    MergeSort(v, mid+1, right);
    // merge two sorted list
    merge(v, left, mid, right);
  }
}
void call_MergeSort(vector<int> v, int left, int right){
  MergeSort(v, left, right);
}
void Swap(vector<int>& v, vector<int>::size_type i, vector<int>::size_type j) {
    if(i == j) return;
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
void Sift(vector<int>& v, const vector<int>::size_type heapSize, const vector<int>::size_type siftNode) {
    vector<int>::size_type i, j;
    j = siftNode;
    do
    {
        i = j;
        if(((2*i + 1) < heapSize) && v[j] < v[2*i + 1])
            j = 2*i + 1;
        if(((2*i + 2) < heapSize) && v[j] < v[2*i + 2])
            j = 2*i + 2;
        Swap(v, i, j);
    }
    while(i != j);
}
void MakeInitialHeap(vector<int>& v) {
    for(int i = v.size() - 1; i >= 0; --i)
      Sift(v, v.size(), i);
}
void HeapSort(vector<int> v) {
    MakeInitialHeap(v);
    for(vector<int>::size_type i = v.size()-1; i > 0; --i) {
        Swap(v, i, 0);
        Sift(v, i, 0);
    }
}
void AlgorithmHSort(vector<int> v){
  sort(v.begin(), v.end());
}
void AlgorithmHStableSort(vector<int> v){
  stable_sort(v.begin(), v.end());
}
void SequentialSearch(const vector<int> & v, int key) {
    int index = 0;
    while (index < v.size()) {
        if (v[index] == key) // found our element; key comparison that controls the loop
            return;
        else
            index ++;
    }
}
void BinarySearch(const vector<int> &v, int key) {
    int low = 0;
    int high = v.size()-1;
    while (low <= high) { // stop when low and high cross
        int mid = (low+high)/2; // check middle of sequence
        if (v[mid] == key) // found it
            return; // return the index
        else if (v[mid] > key) // check in left half
            high = mid - 1;
        else // check in right half
            low = mid + 1;
    }
    return;
}
void BinarySearchTree() {
}
