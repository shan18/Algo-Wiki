#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* Create a new node */
struct Node *new_node(int key) {
    struct Node *temp = new Node;
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

/* Create BST */
struct Node *create_bst(int arr[], int start, int end) {
    if(start > end)
        return NULL;
    
    int mid = (start + end) / 2;
    struct Node *root = new_node(arr[mid]);
    
    root->left = create_bst(arr, start, mid-1);
    root->right = create_bst(arr, mid+1, end);
    
    return root;
}


/* Inorder Traversal */
void inorder_traversal(struct Node *node) {
    if(!node)
        return;
        
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
}

/* Search a node in BST */
struct Node *search(struct Node *root, int key) {
    if(root == NULL || root->data == key)
        return root;
    
    if(key < root->data)
        return search(root->left, key);
    
    return search(root->right, key);
}

/* Insert a new node in BST */
struct Node* insert(struct Node *node, int key) {
    if(node == NULL)
        return new_node(key);
    
    if(key < node->data)
        node->left = insert(node->left, key);
    else if(key > node->data)
        node->right = insert(node->right, key);
    
    return node;
}

/* Find the node with the smallest value */
struct Node *min_val_node(struct Node *node) {
    struct Node *temp = node;
    while(node->left != NULL)
        node = node->left;
    return node;
}

/* Delete a node from BST */
struct Node *delete_node(struct Node *root, int key) {
    if(root == NULL)
        return root;
    
    if(key < root->data)
        root->left = delete_node(root->left, key);
    else if(key > root->data)
        root->right = delete_node(root->right, key);
    else {
        if(root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if(root -> right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        
        struct Node *temp = min_val_node(root->right);
        root->data = temp->data;
        return delete_node(root->right, temp->data);
    }
}

int main() {
    int nodes[] = {1, 12, 3, 4, 5, 8, 10};
    int size = sizeof(nodes) / sizeof(nodes[0]);
    sort(nodes, nodes+size);
    
    struct Node *root = create_bst(nodes, 0, size-1);
    
    cout << "Inorder Traversal: ";
    inorder_traversal(root);
    cout << endl;
    
    int i_key = 6;
    insert(root, i_key);
    cout << "Inorder Traversal after inserting " << i_key << ": ";
    inorder_traversal(root);
    cout << endl;
    
    int s_key = 4;
    struct Node *found = search(root, s_key);
    if(!found)
        cout << "DNE" << endl;
    else
        cout << "Found" << endl;
    
    int d_key = 2;
    delete_node(root, d_key);
    cout << "Inorder Traversal after deleting " << d_key << ": ";
    inorder_traversal(root);
    cout << endl;
}
