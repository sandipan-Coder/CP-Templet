#include <iostream>
#include <vector>
using namespace std;

// Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

vector<int> inOrder(Node* root) {
    vector<int> res;
    Node* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
          
            // If no left child, visit this node 
            // and go right
            res.push_back(curr->data);
            curr = curr->right;
        }
        else {
          
            // Find the inorder predecessor of curr
            Node* prev = curr->left;
            while (prev->right != nullptr &&
                                 prev->right != curr) {
                prev = prev->right;
            }

            // Make curr the right child of its 
            // inorder predecessor
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } 
            else {
              
                // Revert the changes made in 
                // the tree structure
                prev->right = nullptr;
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return res;
}


// This traversal have Complexity :
//    Time Complexity :- O(N).
//    Space Complexity :- O(1).
