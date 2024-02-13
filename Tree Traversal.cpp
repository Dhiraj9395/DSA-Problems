#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node(int val) {

    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};
Node *createTree() {
  cout << "enter the value";
  int data;
  cin >> data;
  if (data == -1) {
    return NULL;
  }
  Node *root = new Node(data);
  root->left = createTree();
  root->right = createTree();
  return root;
}
void preorderTraversal(Node *root) {
  if(root == NULL){
    return;
  }
  cout<<root ->data<<" ";
  preorderTraversal(root ->left);
  preorderTraversal(root ->right);
}
void inorderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  inorderTraversal(root->left);
  cout << root->data<<" ";
  inorderTraversal(root->right);
}
void postordertraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  postordertraversal(root->left);
  postordertraversal(root->right);
  cout<<root ->data<<" ";
}
int main() {
  Node *root = createTree();
  
  preorderTraversal(root);
  cout << "printing preorder traversal"<<endl;
  
  inorderTraversal(root);
  cout << "printing inorder traversal"<<endl;
 
  postordertraversal(root);
   cout << "printing postorder traversal"<<endl;
}