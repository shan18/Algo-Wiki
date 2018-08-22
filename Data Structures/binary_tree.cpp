/* The following code uses C++ to implement an binary tree along with the following operations:
 * 1. Inorder Traversal
 * 2. Preorder Traversal
 * 3. Postorder Traversal
 * 4. Insertion
 * 5. Deletion
*/

#include <bits/stdc++.h>
using namespace std;


struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

/* Create a new node */
struct Node *new_node(int key) {
    struct Node *temp = new Node;
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* Create Binary Tree */
struct Node *create_tree() {
    struct Node *root = new_node(10);
    root->left = new_node(11);
    root->left->left = new_node(7);
    root->right = new_node(9);
    root->right->left = new_node(15);
    root->right->right = new_node(8);
    return root;
}

/* Inorder Traversal */
void inorder_traversal(struct Node *node) {
    if(!node)
        return;
        
    inorder_traversal(node->left);
    cout << node->key << " ";
    inorder_traversal(node->right);
}

/* Preorder Traversal */
void preorder_traversal(struct Node *node) {
    if(!node)
        return;
        
    cout << node->key << " ";
    preorder_traversal(node->left);
    preorder_traversal(node->right);
}

/* Postorder Traversal */
void postorder_traversal(struct Node *node) {
    if(!node)
        return;
        
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    cout << node->key << " ";
}

/* Insert a new node in the binary tree */
void insert(struct Node *root, int key) {
    queue <struct Node *> q;
    q.push(root);
    while(!q.empty()) {
        struct Node *temp = q.front();
        q.pop();
        
        if(!temp->left) {
            temp->left = new_node(key);
            break;
        } else
            q.push(temp->left);
        
        if(!temp->right) {
            temp->right = new_node(key);
            break;
        } else
            q.push(temp->right);
    }
}

/* Delete the deepest rightmost node from the tree */
void delete_deepest(struct Node *root, struct Node *node) {
    queue <struct Node *> q;
    q.push(root);
    while(!q.empty()) {
        struct Node *temp = q.front();
        q.pop();
        
        if(temp->right) {
            if(temp->right == node) {
                temp->right = NULL;
                delete(node);
                break;
            } else
                q.push(temp->right);
        }
        
        if(temp->left) {
            if(temp->left == node){
                temp->left = NULL;
                delete(node);
                break;
            } else
            q.push(temp->left);
        }
    }
}

/* Delete a node from the binary tree */
void delete_node(struct Node *root, int key) {
    
    struct Node *temp;
    struct Node *key_node = NULL;
    
    queue <struct Node *> q;
    q.push(root);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        
        if(temp->key == key)
            key_node = temp;
        
        if(temp->left)
            q.push(temp->left);
        
        if(temp->right)
            q.push(temp->right);
    }
    
    key_node->key = temp->key;
    delete_deepest(root, temp);
}

int main() {
    struct Node *root = create_tree();
    
    cout << "Inorder Traversal: ";
    inorder_traversal(root);
    cout << endl;
    
    cout << "Preorder Traversal: ";
    preorder_traversal(root);
    cout << endl;
    
    cout << "Postorder Traversal: ";
    postorder_traversal(root);
    cout << endl;
    
    int i_key = 12;
    insert(root, i_key);
    cout << "Inorder Traversal after inserting " << i_key << ": ";
    inorder_traversal(root);
    cout << endl;
    
    int d_key = 12;
    delete_node(root, d_key);
    cout << "Inorder Traversal after deleting " << d_key << ": ";
    inorder_traversal(root);
    cout << endl;
}
