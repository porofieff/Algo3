#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int _data)
    {
        data = _data;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class BIN_Tree
{
    public:
        Node* root;

        BIN_Tree()
        {
            root = nullptr;
        }
        BIN_Tree(int k)
        {
            root = new Node(k);
        }

        Node* addLeft(Node* curr, int new_k)
        {
            if (curr->left == nullptr)
            {
                Node* new_l_node = new Node(new_k);
                curr->left = new_l_node;
                new_l_node->parent = curr;
                return new_l_node;
            }
            return curr->left;
        }

        Node* addRight(Node* curr, int new_k)
        {
            if (curr->right == nullptr)
            {
                Node* new_r_node = new Node(new_k);
                curr->right = new_r_node;
                new_r_node->parent = curr;
                return new_r_node;
            }
            return curr->right;
        }

        void recursionInOrder(Node* curr, vector<int>& res)
        {
            if (curr == nullptr)
            {
                return;
            }
            recursionInOrder(curr->left, res);
            res.push_back(curr->data);
            recursionInOrder(curr->right, res);
        }

        void recursionPreOrder(Node* curr, vector<int>& res)
        {
            if (curr == nullptr) return;
            res.push_back(curr->data);
            recursionPreOrder(curr->left, res);
            recursionPreOrder(curr->right, res);
        }

        void recursionPostOrder(Node* curr, vector<int>& res)
        {
            if (curr == nullptr) return;
            recursionPostOrder(curr->left, res);
            recursionPostOrder(curr->right, res);
            res.push_back(curr->data);
        }

        void printInOrder()
        {
            if (root == nullptr)
            {
                cout << "Tree is empty." << endl;
                return;
            }
            vector<int> res;
            recursionInOrder(root, res);
            for (int i : res)
            {
                cout << i;
            }
            cout << endl;
        }

        void printPreOrder()
        {
            if (root == nullptr)
            {
                cout << "Tree is empty." << endl;
                return;
            }
            vector<int> res;
            recursionPreOrder(root, res);
            for (int i : res) {
                cout << i << " ";
            }
            cout << endl;
        }

        void printPostOrder()
        {
            if (root == nullptr)
            {
                cout << "Tree is empty." << endl;
                return;
            }

            vector<int> res;
            recursionPostOrder(root, res);

            for (int i : res)
            {
                cout << i << " ";
            }
            cout << endl;
        }

        Node* get_root()
        {
            return root;
        }

        Node* getParent(Node* node)
        {
            return node != nullptr ? node->parent : nullptr;
        }
};
