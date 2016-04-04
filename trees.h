#include <iostream>

#include <string>

#include <stack>

#include <iomanip>

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



/* Red Black Tree Definition */
 

static const int RED = 0;
static const int BLACK = 1;

template <class T>
class RedBlackTreeNode
{
public:
    RedBlackTreeNode() :key(T()), parent(NULL), left(NULL), right(NULL), color(BLACK) {}
    T key;
    RedBlackTreeNode<T>* parent;
    RedBlackTreeNode<T>* left;
    RedBlackTreeNode<T>* right;
    int color;
};

template <class T>
class RedBlackTree
{
public:
    RedBlackTree();
    int search_element(const T& k) const;
    int get_minmum(T& retmin)const;
    int get_maxmum(T& retmax)const;
    int get_successor(const T& k, T& ret) const;
    int get_predecessor(const T& k, T& ret) const;
    int insert_key(const T& k);
    int delete_key(const T& k);
    void inorder_tree_walk()const;
    RedBlackTreeNode<T>* get_root() const;
    ~RedBlackTree();
private:
    RedBlackTreeNode<T>* root;
    static  RedBlackTreeNode<T> *NIL;
    RedBlackTreeNode<T>* get_parent(RedBlackTreeNode<T>* pnode) const;
    RedBlackTreeNode<T>* get_left(RedBlackTreeNode<T>* pnode) const;
    RedBlackTreeNode<T>* get_right(RedBlackTreeNode<T>* pnode) const;
    T get_key(RedBlackTreeNode<T>* pnode) const;
    int get_color(RedBlackTreeNode<T>* pnode) const;
    void set_color(RedBlackTreeNode<T>* pnode, int color);
    void left_rotate(RedBlackTreeNode<T> *pnode);
    void right_rotate(RedBlackTreeNode<T> *pnode);
    void rb_insert_fixup(RedBlackTreeNode<T> *pnode);
    void rb_delete_fixup(RedBlackTreeNode<T> *pnode);
    RedBlackTreeNode<T>* get_maxmum(RedBlackTreeNode<T> *root) const;
    RedBlackTreeNode<T>* get_minmum(RedBlackTreeNode<T> *root) const;
    RedBlackTreeNode<T>* get_successor(RedBlackTreeNode<T> *pnode) const;
    RedBlackTreeNode<T>* get_predecessor(RedBlackTreeNode<T> *pnode) const;
    RedBlackTreeNode<T>* search_tree_node(const T& k)const;
    void make_empty(RedBlackTreeNode<T>* root);
};

template <class T>
RedBlackTreeNode<T>* RedBlackTree<T>::NIL = new RedBlackTreeNode<T>;

template <class T>
RedBlackTree<T>::RedBlackTree()
{
    root = NULL;
}

template <class T>
int RedBlackTree<T>::search_element(const T& k) const
{
    return (NIL != search_tree_node(k));
}

template <class T>
int RedBlackTree<T>::get_minmum(T& retmin)const
{
    if (root)
    {
        retmin = get_minmum(root)->key;
        return 0;
    }
    return -1;
}

template <class T>
int RedBlackTree<T>::get_maxmum(T& retmax)const
{
    if (root)
    {
        retmax = get_maxmum(root)->key;
        return 0;
    }
    return -1;
}

template <class T>
int RedBlackTree<T>::get_successor(const T& k, T& ret) const
{
    RedBlackTreeNode<T>* pnode = search_tree_node(k);

    if (pnode != NIL)
    {
        pnode = get_successor(pnode);
        if (pnode != NIL)
        {
            ret = pnode->key;
            return 0;
        }
        return -1;
    }
    return -1;
}
template <class T>
int RedBlackTree<T>::get_predecessor(const T& k, T& ret) const
{
    RedBlackTreeNode<T>* pnode = search_tree_node(k);
    if (pnode != NIL)
    {
        pnode = get_predecessor(pnode);
        if (pnode != NIL)
        {
            ret = pnode->key;
            return 0;
        }
        return -1;
    }
    return -1;
}

template <class T>
int RedBlackTree<T>::insert_key(const T& k)
{
    RedBlackTreeNode<T> *newnode = new RedBlackTreeNode<T>;
    newnode->key = k;
    newnode->color = RED;
    newnode->left = NIL;
    newnode->right = NIL;
    newnode->parent = NIL;

    if (NULL == root)
        root = newnode;
    else
    {
        RedBlackTreeNode<T>* pnode = root;
        RedBlackTreeNode<T>* qnode = root;
        while (pnode != NIL)
        {
            qnode = pnode;
            if (pnode->key > newnode->key)
                pnode = pnode->left;
            else
                pnode = pnode->right;
        }
        newnode->parent = qnode;
        if (qnode->key > newnode->key)
            qnode->left = newnode;
        else
            qnode->right = newnode;
    }
    rb_insert_fixup(newnode);
    return 0;
}

template <class T>
int RedBlackTree<T>::delete_key(const T& k)
{
    RedBlackTreeNode<T>* pnode = search_tree_node(k);//pnode指向要删除的节点
    if (NIL != pnode)
    {
        RedBlackTreeNode<T>* qnode, *tnode;//
        if (get_left(pnode) == NIL || get_right(pnode) == NIL)//左节点，或右节点为空,或者全为空；
            qnode = pnode;
        else//左、右节点均不为空
            qnode = get_successor(pnode);//qnode指向继承者

        if (get_left(qnode) != NIL)//左节点不为空时
            tnode = get_left(qnode);
        else//右节点不为空时
            tnode = get_right(qnode);

        //tnode的父节点为qnode
        tnode->parent = get_parent(qnode);

        if (get_parent(qnode) == NIL)
            root = tnode;
        else if (qnode == get_left(get_parent(qnode)))
            qnode->parent->left = tnode;
        else
            qnode->parent->right = tnode;

        if (qnode != pnode)
            pnode->key = get_key(qnode);

        if (get_color(qnode) == BLACK)
            rb_delete_fixup(tnode);

        delete qnode;
        return 0;
    }
    return -1;
}

template <class T>
RedBlackTree<T>::~RedBlackTree()
{
    make_empty(root);
}
template <class T>
RedBlackTreeNode<T>* RedBlackTree<T>::get_root() const
{
    return root;
}
template <class T>
RedBlackTreeNode<T>* RedBlackTree<T>::get_parent(RedBlackTreeNode<T>* pnode) const
{
    return pnode->parent;
}
template <class T>
RedBlackTreeNode<T>* RedBlackTree<T>::get_left(RedBlackTreeNode<T>* pnode) const
{
    return pnode->left;
}
template <class T>
RedBlackTreeNode<T>* RedBlackTree<T>::get_right(RedBlackTreeNode<T>* pnode) const
{
    return pnode->right;
}
template <class T>
T RedBlackTree<T>::get_key(RedBlackTreeNode<T>* pnode) const
{
    return pnode->key;
}
template <class T>
int RedBlackTree<T>::get_color(RedBlackTreeNode<T>* pnode) const
{
    return pnode->color;
}

template <class T>
void RedBlackTree<T>::set_color(RedBlackTreeNode<T>* pnode, int color)
{
    pnode->color = color;
}

template <class T>
void RedBlackTree<T>::left_rotate(RedBlackTreeNode<T> *pnode)
{
    RedBlackTreeNode<T>* rightnode = pnode->right;
    pnode->right = rightnode->left;
    if (rightnode->left != NIL)
        rightnode->left->parent = pnode;
    rightnode->parent = pnode->parent;
    if (pnode->parent == NIL)
        root = rightnode;
    else if (pnode == pnode->parent->left)
        pnode->parent->left = rightnode;
    else
        pnode->parent->right = rightnode;
    rightnode->left = pnode;
    pnode->parent = rightnode;
}

template <class T>
void RedBlackTree<T>::right_rotate(RedBlackTreeNode<T> *pnode)
{
    RedBlackTreeNode<T>* leftnode = pnode->left;
    pnode->left = leftnode->right;
    if (leftnode->right != NIL)
        leftnode->right->parent = pnode;
    leftnode->parent = pnode->parent;
    if (pnode->parent == NIL)
        root = leftnode;
    else if (pnode == pnode->parent->left)
        pnode->parent->left = leftnode;
    else
        pnode->parent->right = leftnode;
    leftnode->right = pnode;
    pnode->parent = leftnode;
}
template <class T>
void RedBlackTree<T>::rb_insert_fixup(RedBlackTreeNode<T>*pnode)
{
    RedBlackTreeNode<T> *qnode, *tnode;
    //当pnode的父节点为红色时，破坏性质4
    while (get_color(get_parent(pnode)) == RED)
    {
        qnode = get_parent(get_parent(pnode));//祖父结点
        if (get_parent(pnode) == get_left(qnode))
        {
            tnode = get_right(qnode);//pnode的叔叔结点
            if (get_color(tnode) == RED) //case1 叔叔结点为红色
            {
                set_color(get_parent(pnode), BLACK);
                set_color(tnode, BLACK);
                set_color(qnode, RED);
                pnode = qnode;
            }
            else  //case 2 or case 3
            {
                if (pnode == get_right(get_parent(pnode)))  //case2 pnode为右孩子
                {
                    pnode = get_parent(pnode);
                    left_rotate(pnode);
                }
                //case3 pnode为左孩子
                set_color(get_parent(pnode), BLACK);
                qnode = get_parent(get_parent(pnode));
                set_color(qnode, RED);
                right_rotate(qnode);
            }
        }
        else
        {
            tnode = get_left(qnode);
            if (get_color(tnode) == RED)
            {
                set_color(get_parent(pnode), BLACK);
                set_color(tnode, BLACK);
                set_color(qnode, RED);
                pnode = qnode;
            }
            else
            {
                if (pnode == get_left(get_parent(pnode)))
                {
                    pnode = get_parent(pnode);
                    right_rotate(pnode);
                }
                set_color(get_parent(pnode), BLACK);
                qnode = get_parent(get_parent(pnode));
                set_color(qnode, RED);
                left_rotate(qnode);
            }
        }
    }
    set_color(root, BLACK);
}

template <class T>
void RedBlackTree<T>::rb_delete_fixup(RedBlackTreeNode<T> *pnode)
{
    while (pnode != root && get_color(pnode) == BLACK)
    {
        RedBlackTreeNode<T> *qnode, *tnode;
        if (pnode == get_left(get_parent(pnode)))//X为左子树
        {
            qnode = get_right(get_parent(pnode));
            if (get_color(qnode) == RED)  //case1
            {
                set_color(qnode, BLACK);
                set_color(get_parent(pnode), RED);
                left_rotate(get_parent(pnode));
                qnode = get_right(get_parent(pnode));
            }

            //case2
            if (get_color(get_left(qnode)) == BLACK && get_color(get_right(qnode)) == BLACK)
            {
                set_color(qnode, RED);
                pnode = get_parent(pnode);
            }
            else
            {
                //case3，旋转结束后变成case4
                if (get_color(get_right(qnode)) == BLACK)
                {
                    set_color(get_left(qnode), BLACK);
                    set_color(qnode, RED);
                    right_rotate(qnode);
                    qnode = get_right(get_parent(pnode));
                }
                //case4
                set_color(qnode, get_color(get_parent(pnode)));
                set_color(get_parent(pnode), BLACK);
                set_color(get_right(qnode), BLACK);
                left_rotate(get_parent(pnode));
                pnode = root;
            }
        }
        else//X为右子树
        {
            qnode = get_left(get_parent(pnode));
            if (get_color(qnode) == RED)
            {
                set_color(qnode, BLACK);
                set_color(get_parent(pnode), RED);
                right_rotate(get_parent(pnode));
                qnode = get_left(get_parent(pnode));
            }
            if (get_color(get_right(qnode)) == BLACK && get_color(get_left(qnode)) == BLACK)
            {
                set_color(qnode, RED);
                pnode = get_parent(pnode);
            }
            else
            {
                if (get_color(get_left(qnode)) == BLACK)
                {
                    set_color(get_right(qnode), BLACK);
                    set_color(qnode, RED);
                    left_rotate(qnode);
                    qnode = get_left(get_parent(pnode));
                }
                set_color(qnode, get_color(get_parent(pnode)));
                set_color(get_parent(pnode), BLACK);
                set_color(get_left(qnode), BLACK);
                right_rotate(get_parent(pnode));
                pnode = root;
            }
        }
    }
    set_color(pnode, BLACK);
}

template <class T>
RedBlackTreeNode<T>* RedBlackTree<T>::get_maxmum(RedBlackTreeNode<T> *root) const
{
    RedBlackTreeNode<T> *pnode = root;
    while (pnode->right != NIL)
        pnode = pnode->right;
    return pnode;
}

template <class T>
RedBlackTreeNode<T>* RedBlackTree<T>::get_minmum(RedBlackTreeNode<T> *root) const
{
    RedBlackTreeNode<T> *pnode = root;
    while (pnode->left != NIL)
        pnode = pnode->left;
    return pnode;
}

template <class T>
RedBlackTreeNode<T>* RedBlackTree<T>::get_successor(RedBlackTreeNode<T> *pnode) const
{
    if (pnode->right != NIL)
        return get_minmum(pnode->right);
    RedBlackTreeNode<T>* parentnode = get_parent(pnode);
    while (parentnode != NIL && get_right(parentnode) == pnode)
    {
        pnode = parentnode;
        parentnode = get_parent(pnode);
    }
    return parentnode;
}

template <class T>
RedBlackTreeNode<T>* RedBlackTree<T>::get_predecessor(RedBlackTreeNode<T> *pnode) const
{
    if (pnode->left != NIL)
        return get_maxmum(pnode->left);
    RedBlackTreeNode<T>* parentnode = get_parent(pnode);
    while (parentnode != NIL && get_left(parentnode) == pnode)
    {
        pnode = parentnode;
        parentnode = get_parent(pnode);
    }
    return parentnode;
}

template <class T>
RedBlackTreeNode<T>* RedBlackTree<T>::search_tree_node(const T& k)const
{
    RedBlackTreeNode<T>* pnode = root;
    while (pnode != NIL)
    {
        if (pnode->key == k)
            break;
        else if (pnode->key > k)
            pnode = pnode->left;
        else
            pnode = pnode->right;
    }
    return pnode;
}

template <class T>
void RedBlackTree<T>::make_empty(RedBlackTreeNode<T>* root)
{
    if (root)
    {
        RedBlackTreeNode<T> *pleft = root->left;
        RedBlackTreeNode<T>* pright = root->right;
        delete root;
        if (pleft != NIL)
            make_empty(pleft);
        if (pright != NIL)
            make_empty(pright);
    }
}
template <class T>
void RedBlackTree<T>::inorder_tree_walk()const
{
    if (NULL != root)
    {
        stack<RedBlackTreeNode<T>* > s;
        RedBlackTreeNode<T> *ptmpnode;
        ptmpnode = root;
        while (NIL != ptmpnode || !s.empty())
        {
            if (NIL != ptmpnode)
            {
                s.push(ptmpnode);
                ptmpnode = ptmpnode->left;
            }
            else
            {
                ptmpnode = s.top();
                s.pop();
                cout << ptmpnode->key << ":";
                if (ptmpnode->color == BLACK)
                    cout << "Black" << endl;
                else
                    cout << "Red" << endl;
                ptmpnode = ptmpnode->right;
            }
        }
    }
}







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