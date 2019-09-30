#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
#define MAX 5000;
// Binary Tree - ADT
class BinaryTree {
    // vector to store binary tree data of char types
    private: vector<char> bt;
    // meta data
    private: int root, size, max_size;
    private: void inorder(int root) {
        if (root >= this->bt.size() || this->bt[root] == '\0') // base case
            return;
        // inorder left-subtree
        inorder(2*root+1);
        // visit the node
        cout << this->bt[root] << " ";
        // inorder right-subtree
        inorder(2*root+2);
    }

    private: void mirror(int node) {
        if (this->bt[node] == '\0')
            return;

        int left = 2 * node + 1;
        int right = 2 * node + 2;
        mirror(left); // left substree
        mirror(right); // right subtree
        // swap the left/right nodes
        swap(this->bt[left], this->bt[right]);
    }

    public: BinaryTree(int max_size) {
        this->root = 0;
        this->size = 0;
        this->bt.resize(max_size);
        this->max_size = max_size;
        // initialize bt with \0 null character
        fill(this->bt.begin(), this->bt.end(), '\0');
    }

public:
    int getSize() { return this->size; }
    int getMaxSize() { return this->max_size; }

    void updateRoot(char data) {
        if (bt[this->root] == '\0')
            this->size++;
        bt[this->root] = data;
    }

    void insertNode(char data) { // left to right level by level
        if (this->size == this->max_size) {
            cout << "Binary Tree is Full!" << endl;
            return;
        }
        bt[size++] = data;
    }

    void updateLeftNode(int parent, char data) {
        int leftChild = 2 * parent + 1;
        if (leftChild >= this->max_size || this->bt[parent] == '\0')
            cout << "parent index " << parent << " does NOT exist!";
        else {
            if (bt[leftChild] == '\0')
                size++;
            bt[leftChild] = data;
        }
    }

    void updateRightNode(int parent, char data) {
        int rightChild = 2 * parent + 2;
        if (rightChild >= this->max_size || this->bt[parent] == '\0')
            cout << "parent index " << parent << " does NOT exist!";
        else {
            if (bt[rightChild] == '\0')
                size++;
            bt[rightChild] = data;
        }
    }
    // print all nodes level by level
    void print() const {
        for(auto ch: this->bt)
            if (ch == '\0') cout << "- ";
            else cout << ch << " ";
        cout << endl;
    }

    // printInorder traversal
    void printInorder() {
        inorder(0);
    }
   // FIXME: Write printPreorder traversal function
   // FIXME: Write printPostorder traversal function
   /*
     Changes the tree into its mirror image.
     So the tree...
         4
        / \
       2   5
      / \
     1   3
     is changed to...
         4
        / \
       5   2
      / \
     3   1https://d2l.coloradomesa.edu/d2l/le/content/176833/Home?itemIdentifier=D2L.LE.Content.ContentObject.ModuleCO-2586145
     Uses a recursive helper that recurs over the tree,
     swapping the left/right pointers.
    */
    void mirror() {
         mirror(this->root); // call private mirror
    }
};
int main()
{
  ifstream inf("data.in");
  ofstream outf("answer.ot");
  BinaryTree test(10);

  test.updateRoot('A');
  char temp;
  while(!inf.eof()){
    inf >> temp;
    test.insertNode(temp);
  }

  test.print();
  return 0;
}
