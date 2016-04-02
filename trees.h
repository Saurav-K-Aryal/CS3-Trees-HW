#include<iostream>

using namespace std;
 
// A BTree node
class BTreeNode
{
    int *keys;  // An array of keys
    int t;      // Minimum degree (defines the range for number of keys)
    BTreeNode **C; // An array of child pointers
    int n;     // Current number of keys
    bool leaf; // Is true when node is leaf. Otherwise false
 
public:
 
    BTreeNode(int _t, bool _leaf);   // Constructor
 
    // A function to traverse all nodes in a subtree rooted with this node
    void traverse();
 
    // A function to search a key in subtree rooted with this node.
    BTreeNode *search(int k);   // returns NULL if k is not present.
 
    // A function that returns the index of the first key that is greater
    // or equal to k
    int findKey(int k);
 
    // A utility function to insert a new key in the subtree rooted with
    // this node. The assumption is, the node must be non-full when this
    // function is called
    void insertNonFull(int k);
 
    // A utility function to split the child y of this node. i is index
    // of y in child array C[].  The Child y must be full when this
    // function is called
    void splitChild(int i, BTreeNode *y);
 
    // A wrapper function to remove the key k in subtree rooted with
    // this node.
    void remove(int k);
 
    // A function to remove the key present in idx-th position in
    // this node which is a leaf
    void removeFromLeaf(int idx);
 
    // A function to remove the key present in idx-th position in
    // this node which is a non-leaf node
    void removeFromNonLeaf(int idx);
 
    // A function to get the predecessor of the key- where the key
    // is present in the idx-th position in the node
    int getPred(int idx);
 
    // A function to get the successor of the key- where the key
    // is present in the idx-th position in the node
    int getSucc(int idx);
 
    // A function to fill up the child node present in the idx-th
    // position in the C[] array if that child has less than t-1 keys
    void fill(int idx);
 
    // A function to borrow a key from the C[idx-1]-th node and place
    // it in C[idx]th node
    void borrowFromPrev(int idx);
 
    // A function to borrow a key from the C[idx+1]-th node and place it
    // in C[idx]th node
    void borrowFromNext(int idx);
 
    // A function to merge idx-th child of the node with (idx+1)th child of
    // the node
    void merge(int idx);
 
    // Make BTree friend of this so that we can access private members of
    // this class in BTree functions
    friend class BTree;
};
 
class BTree
{
    BTreeNode *root; // Pointer to root node
    int t;  // Minimum degree
public:
 
    // Constructor (Initializes tree as empty)
    BTree(int _t)
    {
        root = NULL;
        t = _t;
    }
 
    void traverse()
    {
        if (root != NULL) root->traverse();
    }
 
    // function to search a key in this tree
    BTreeNode* search(int k)
    {
        return (root == NULL)? NULL : root->search(k);
    }
 
    // The main function that inserts a new key in this B-Tree
    void insert(int k);
 
    // The main function that removes a new key in thie B-Tree
    void remove(int k);
 
};

/* AVL Tree Definition */
class AVLTree {
    private:
        /*
         * Node class represents nodes in the AVL tree.
         */
        class Node {
            private:
                int v; // value
                int h; // height
                Node* l; // pointer to left-child
                Node* r; // pointer to right-child
                Node* p; // pointer to parent node
            public:
                Node(int val){ v = val; h = 0; p = NULL; r = NULL; l = NULL;} // Constructor
                // getters
                int get_v(){ return v;}
                int get_h(){ return h;}
                Node* get_l(){ return l;}
                Node* get_r(){return r;}
                Node* get_p(){return p;}
                // setters
                void remove_p(){p = NULL;}
                Node* set_l(Node* new_left)
                {
                    if(new_left != 0) new_left->p = this;
                    l = new_left;
                    update_h();
                    return l;
                }
                Node* set_r(Node* new_right)
                {
                    if(new_right != 0) new_right->p = this;
                    r = new_right;
                    update_h();
                    return r;
                }
                // function to update height of node.
                int update_h(){
                    if(l != 0 && r != 0)
                    {
                        if(l->get_h() > r->get_h())
                            h = l->get_h() + 1;
                        else
                            h = r->get_h() + 1;
                    }
                    else if(l != 0)
                        h = l->get_h() + 1;
                    else if(r != 0)
                        h = r->get_h() + 1;
                    else
                        h = 0;
                    return h;
                }
                // get the difference of heights to find balance.
                int getBalance()
                {
                    Node * n = this;
                    if(n->get_l() != 0 && n->get_r() !=0)
                        return n->get_l()->get_h() - n->get_r()->get_h();
                    else if(n->get_l() != 0)
                        return n->get_l()->get_h() + 1;
                    else if(n->get_r() != 0)
                        return (-1) * (n->get_r()->get_h() + 1);
                    else
                        return 0;
                }
        };
        /*
         * Pointer pointing to root node of AVL Tree.
         */
        Node* root;

        void setRoot(Node* n)
        {
            root = n;
            if(root != 0) root->remove_p();
        }

        // find a node containing a particular value.
        Node* findNode(int val)
        {
            Node* temp = root;
            while(temp != 0)
            {
                if(val == temp->get_v())
                    return temp;

                else if(val < temp->get_v())
                    temp = temp->get_l();

                else
                    temp = temp->get_r();
            }
            return NULL;
        }
        void rotateLeft(Node * n)
        {
            Node * p = n->get_p();
            enum {left, right} side;
            if(p != 0)
            {
                if(p->get_l() == n)
                    side = left;
                else
                    side = right;
            }
            Node * temp = n->get_r();
            n->set_r(temp->get_l());
            temp->set_l(n);
            if(p != 0)
            {
                if(side == left)
                    p->set_l(temp);
                if(side == right)
                    p->set_r(temp);
            }
            else
            {
                setRoot(temp);
            }
        }
        void rotateRight(Node * n)
        {
            Node * p = n->get_p();
            enum {left, right} side;
            if(p != 0)
            {
                if(p->get_l() == n)
                    side = left;
                else
                    side = right;
            }
            Node * temp = n->get_l();
            n->set_l(temp->get_r());
            temp->set_r(n);
            if(p != 0)
            {
                if(side == left)
                    p->set_l(temp);
                if(side == right)
                    p->set_r(temp);
            }
            else
            {
                setRoot(temp);
            }
        }
        void balanceAtNode(Node* n)
        {
            int bal = n->getBalance();
            if(bal > 1)
            {
                if(n->get_l()->getBalance() < 0)
                    rotateLeft(n->get_l());
                rotateRight(n);
            }
            else if(bal < -1)
            {
                if(n->get_r()->getBalance() > 0)
                    rotateRight(n->get_r());
                rotateLeft(n);
            }
        }

    public:
        AVLTree(){
            root=NULL;
        }
        AVLTree(int val){
            root = new Node(val);
        }
        AVLTree* findSubtree(int val){
            Node* target;
            target = findNode(val);

            if(target != 0)
            {
                AVLTree* subtree = new AVLTree();
                subtree->root = target;
                return subtree;
            }
            else
                return NULL;
        }
        int getHeight() { return root->get_h(); }
        bool InsertNode(int val){
            Node* add_n;
            if(root == 0){
                root = new Node(val);
                return true;
            }else{
                Node* temp = root;

                while(true)
                {
                    if(temp->get_v() > val)
                    {
                        if((temp->get_l()) == 0)
                        {
                            add_n = temp->set_l(new Node(val));
                            break;
                        }
                        else
                        {
                            temp = temp->get_l();
                        }

                    }
                    else if(temp->get_v() < val)
                    {
                        if((temp->get_r()) == 0)
                        {
                            add_n = temp->set_r(new Node(val));
                            break;
                        }
                        else
                        {
                            temp = temp->get_r();
                        }

                    }
                    else
                    {
                        return false;
                    }
                }
                temp = add_n;
                while(temp != 0)
                {
                    temp->update_h();
                    balanceAtNode(temp);
                    temp = temp->get_p();
                }
            }
        }
        bool RemoveNode(int val){
            if(root == 0) return false;
            Node *rep_n, *new_p, *temp_node;
            Node * rem_n = findNode(val);
            if(rem_n == 0) return false;

            Node * p = rem_n->get_p();

            enum {left, right} side;
            if(p != 0)
            {
                if(p->get_l() == rem_n) side = left;
                else side = right;
            }

            int bal = rem_n->getBalance();

            if(rem_n->get_l() == 0 && rem_n->get_r() == 0)
            {
                if(p != 0)
                {
                    if(side == left) p->set_l((Node*)0);
                    else p->set_r((Node*)0);

                    delete rem_n;
                    p->update_h();
                    balanceAtNode(p);
                }
                else
                {
                    setRoot((Node*)0);
                    delete rem_n;
                }

            }
            else if(rem_n->get_r() == 0)
            {
                if(p != 0)
                {
                    if(side == left) p->set_l(rem_n->get_l());
                    else p->set_r(rem_n->get_l());

                    delete rem_n;
                    p->update_h();
                    balanceAtNode(p);
                }
                else
                {
                    setRoot(rem_n->get_l());
                    delete rem_n;
                }
            }

            else if(rem_n->get_l() == 0)
            {
                if(p != 0)
                {
                    if(side == left) p->set_l(rem_n->get_r());
                    else p->set_r(rem_n->get_r());

                    delete rem_n;
                    p->update_h();
                    balanceAtNode(p);
                }
                else
                {
                    setRoot(rem_n->get_r());
                    delete rem_n;
                }
            }
            else
            {
                if(bal > 0)
                {
                    if(rem_n->get_l()->get_r() == 0)
                    {
                        rep_n = rem_n->get_l();
                        rep_n->set_r(rem_n->get_r());

                        temp_node = rep_n;


                    }
                    else
                    {
                        rep_n = rem_n->get_l()->get_r();
                        while(rep_n->get_r() != 0)
                        {
                            rep_n = rep_n->get_r();
                        }
                        new_p = rep_n->get_p();
                        new_p->set_r(rep_n->get_l());

                        temp_node = new_p;

                        rep_n->set_l(rem_n->get_l());
                        rep_n->set_r(rem_n->get_r());
                    }
                }
                else
                {
                    if(rem_n->get_r()->get_l() == 0)
                    {
                        rep_n = rem_n->get_r();
                        rep_n->set_l(rem_n->get_l());

                        temp_node = rep_n;


                    }
                    else
                    {
                        rep_n = rem_n->get_r()->get_l();
                        while(rep_n->get_l() != 0)
                        {
                            rep_n = rep_n->get_l();
                        }
                        new_p = rep_n->get_p();
                        new_p->set_l(rep_n->get_r());

                        temp_node = new_p;

                        rep_n->set_l(rem_n->get_l());
                        rep_n->set_r(rem_n->get_r());
                    }
                }
                if(p != 0)
                {
                    if(side == left) p->set_l(rep_n);
                    else p->set_r(rep_n);

                    delete rem_n;
                }
                else
                {
                    setRoot(rep_n);
                    delete rem_n;
                }

                balanceAtNode(temp_node);
            }
        }
};

/* ClasS definition of BST. */

class BinarySearchTree
{
    public:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           int data;
        };
        tree_node* root;
        BinarySearchTree()
        {
           root = NULL;
        }
        bool isEmpty() const { return root==NULL; }
        void insert(int);
        void remove(int);
};