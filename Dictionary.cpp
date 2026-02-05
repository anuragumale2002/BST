// ==========================================
// Name: Anurag Prashant Umale              =
// Student Id: 1887255                      =
// E-mail: aumale@ucsc.edu                  =
// File: Dictionary.cpp						=
// Class: CSE 101 Spring 2023               =
// ==========================================
#include "Dictionary.h"

Dictionary::Node::Node(keyType k, valType v)
{
    key = k;          // setting the key to the value k
    val = v;          // setting the val to the value v
    parent = nullptr; // setting the parent to nullptr
    left = nullptr;   // setting the left to nullptr
    right = nullptr;  // setting the right to nullptr
}

Dictionary::Dictionary()
{
    nil = new Node(" ", -1); // setting the nil to new Node with empty string and value is -1
    current = nil;           // setting the current pointer to nil
    root = nil;              // setting the root to nil
    num_pairs = 0;           // setting the number of pairs to 0
}

Dictionary::Dictionary(const Dictionary &D)
{
    nil = new Node(" ", -1);     // setting the nil to new Node with empty string and value is -1
    current = nil;               // setting the current  to nil
    root = nil;                  // setting the root to nil
    num_pairs = 0;               // setting the num_paires to 0
    preOrderCopy(D.root, D.nil); // creating the copy of the dictionary in preoder
}

Dictionary::~Dictionary()
{
    clear();    // clearing the dictionary
    delete nil; // delearing the nil pointer
}

void Dictionary::inOrderString(std::string &s, Node *R) const
{
    if (R == nil) // checking if R is equal to nil
    {
        return; // returning from the function
    }
    inOrderString(s, R->left);                           // resursive calling the function with params s and Left Node
    s += R->key + " : " + std::to_string(R->val) + '\n'; // concatinating the key with colon and value with it and concat with new line
    inOrderString(s, R->right);                          // resursive calling the function with params s and Right Node
}

void Dictionary::preOrderString(std::string &s, Node *R) const
{
    if (R == nil) // checking if R is equal to nil
    {
        return; // returning from the function
    }
    s += R->key + '\n';          // concat key with new line with s
    preOrderString(s, R->left);  // recrusive calling of function with params s and left node
    preOrderString(s, R->right); // recrusive calling of function with params s and right node
}

void Dictionary::preOrderCopy(Node *R, Node *N)
{
    if (R == N) // checkig if R is euqal to N
    {
        return; // returning from thr funtion
    }
    setValue(R->key, R->val);  // setting the key to the val of R
    preOrderCopy(R->left, N);  // recursive call on params left node and the node N
    preOrderCopy(R->right, N); // recursive call on params right node and the node N
}

void Dictionary::postOrderDelete(Node *R)
{
    if (R == nil) // checkig if R is euqal to nil
    {
        return; // returning from the funtion
    }
    postOrderDelete(R->left);  // recursive call on params left node of R
    postOrderDelete(R->right); // recursive call on params right node of R
    delete (R);                // deleting the node R
}

Dictionary::Node *Dictionary::search(Node *R, keyType k) const
{
    if (R == nil) // checkig if R is euqal to nil
    {
        return R; // returning R
    }
    if (R->key > k) // checking if the the key of R's node is gretater than k
    {
        return search(R->left, k); // returning recursive call on R's left node and k
    }
    else if (R->key < k) // checking if the the key of R's node is less than k
    {
        return search(R->right, k); // returning recursive call on R's right node and k
    }
    return R; // returning R
}

Dictionary::Node *Dictionary::findMin(Node *R)
{
    if (R == nil) // checking if R is equal to nil
    {
        return nil; // returning nil
    }
    Node *temp = R;           // assigning the themp node to R
    while (temp->left != nil) // checking if the left of temp node is equal to nil
    {
        temp = temp->left; // temp is assigned with temp's left value
    }
    return temp; // returning the temp node
}

Dictionary::Node *Dictionary::findMax(Node *R)
{
    if (R == nil) // checking if the R is equal to nil
    {
        return nil; // returning the nil
    }
    Node *temp = R;            // assigning the temp node with R
    while (temp->right != nil) // checking if the temp's right is not equal to nil
    {
        temp = temp->right; // temp is assigned to temp's right pointer
    }
    return temp; // returning the temp
}

Dictionary::Node *Dictionary::findNext(Node *N)
{
    if (N == nil) // checking if N equal to nil
    {
        return nil; // returning the nil
    }
    if (N->right != nil) // checking if the Node's right pointer is not equal to nil
    {
        return findMin(N->right); // returning the findMin on right suhb tree
    }
    Node *temp = N->parent;                 // assigning the temp variable to N's parent
    while (temp != nil && N == temp->right) // checking if temp is not equal to nil and N is equal to temp's right
    {
        N = temp;            // assigning N with temp node
        temp = temp->parent; // assigning temp node with temp's parent
    }
    return temp; // returning the temp
}

Dictionary::Node *Dictionary::findPrev(Node *N)
{
    if (N == nil) // checking if N equal to nil
    {
        return nil; // returning the nil
    }
    if (N->left != nil) // checking if the Node's left pointer is not equal to nil
    {
        return findMax(N->left); // returning the findMax on right suhb tree
    }
    Node *temp = N->parent;                // assigning the temp variable to N's parent
    while (temp != nil && N == temp->left) // checking if temp is not equal to nil and N is equal to temp's left
    {
        N = temp;            // assigning N with temp node
        temp = temp->parent; // assigning temp node with temp's parent
    }
    return temp; // returning the temp
}

int Dictionary::size() const
{
    return num_pairs; // returning the number of pains
}

bool Dictionary::contains(keyType k) const
{
    return this->search(root, k) != nil; // returning the boolean that is checking return value of search not equal to nil
}

valType &Dictionary::getValue(keyType k) const
{
    Node *searched = this->search(root, k); // seaching the node in the
    if (searched == nil)                    // checking if the searched value is equal to nil
    {
        throw std::logic_error("Dictionary: getValue(): key \"" + k + "\" does not exist"); // throwing the exception logic_error
    }
    return searched->val; // returning the searched node's value
}

bool Dictionary::hasCurrent() const
{
    return current != nil; // returning the current not equal to nil bool value
}

keyType Dictionary::currentKey() const
{
    if (current == nil) // checking if the current node is equal to nil
    {
        throw std::logic_error("Dictionary: currentKey(): current undefined"); // throwing the exception
    }
    return current->key; // returning the current node's key
}

valType &Dictionary::currentVal() const
{
    if (current == nil) // checking if the current node is equal to nil
    {
        throw std::logic_error("Dictionary: currentVal(): current undefined"); // throwing the exception
    }
    return current->val; // returning the current node's val
}

void Dictionary::clear()
{
    postOrderDelete(root); // calling the postOrderDelete function
    root = nil;            // setting root to nil
    current = nil;         // setting the current to nils
    num_pairs = 0;         // setting the num_pairs to 0
}

// Got help from section Amaan
void Dictionary::setValue(keyType k, valType v)
{
    Node *N = new Node(k, v); // new node is created with key val
    N->left = nil;            // setting the left node to nil
    N->right = nil;           // setting the right node to nil

    Node *parent = this->nil;        // setting the temp parent node to nil
    Node **currentptr = &this->root; // setting the current pointer to address of root of this pointer

    while (*currentptr != this->nil) // checking if the current pointer is not equal to nil
    {
        parent = *currentptr; // parent node is set to current pointer

        if (k < (*currentptr)->key) // checking if key value is less than currentpointer 's key
        {
            currentptr = &((*currentptr)->left); // current poinrer is set to address of current pointer's left node
        }
        else if (k > (*currentptr)->key) // checking if k is greater than current pointer's key
        {
            currentptr = &((*currentptr)->right); // current pointer us set to current poinrer's right node
        }
        else // else
        {
            (*currentptr)->val = v; // current pointer value is set to v
            delete N;               // deleting the node N
            return;                 // returning from the function
        }
    }

    N->parent = parent; // N's parent is set to parent
    *currentptr = N;    // current pointer is set to N
    num_pairs++;        // num_pairs incremented by 1
}

// Got help from section Amaan
void Dictionary::remove(keyType k)
{
    if (!contains(k)) // checking if the tree contains k
    {
        throw std::logic_error("Dictionary: remove(): key \"" + k + "\" does not exist"); // throwing exception
    }
    Node *deltemp = search(root, k);                   // searching the node k in tree for deleting
    if (deltemp->left == nil || deltemp->right == nil) // checking if the left node of deltemp is equal to nil or the right node of the deltemp is equal to nil
    {
        Node *child = deltemp->left == nil ? deltemp->right : deltemp->left; // the child of the del temp is checked by
        if (deltemp->parent == nil)                                          // checking if the deltemp's parent is equal to nil
        {
            root = child; // root is set to child
        }
        else if (deltemp == deltemp->parent->left) // checking if deltemp is equal to delptemp's parent's left
        {
            deltemp->parent->left = child; // deltemp's parent's left is set to the child
        }
        else
        {
            deltemp->parent->right = child; // deltemp's parent's right is set to child
        }
        if (child != nil) // checking if the child is not equal to nil
        {
            child->parent = deltemp->parent; // child's parent is set to deltemp's parent
        }
    }
    else // else
    {
        Node *successor = findMin(deltemp->right); // successor pointer is set to the min node in right sub tree
        if (successor->parent != deltemp)          // checking successor's parent is not equal to deltemp
        {
            if (successor->right != nil) // successor's right is equal to nil
            {
                successor->right->parent = successor->parent; // successor's right node's parent is assigned to successor's parent
            }
            successor->parent->left = successor->right; // successor's parent's left node is assigned to successor's right node
            successor->right = deltemp->right;          // successor's right node is assigned by deltemp's right node
            successor->right->parent = successor;       // successor's right node's parent is assigned to successor
        }
        if (deltemp == root) // checking if the deltemp is equal to root
        {
            root = successor; // root is assigned to successor
        }
        else if (deltemp->parent->left == deltemp) // checking deltemp's parent's left node is equal to deltemp
        {
            deltemp->parent->left = successor; // deltemp's parent's left node successor
        }
        else // else
        {
            deltemp->parent->right = successor; // deltemp's parent's right node successor
        }
        successor->parent = deltemp->parent; // successor's parent is set to deltemp's parent
        successor->left = deltemp->left;     // successor's left node is set to deltemp's left node
        successor->left->parent = successor; // successor's left node's parent is set to successor
    }
    if (current == deltemp) // checking if current is equal to deltemp
    {
        current = nil; // current is set to nil
    }
    delete deltemp;    // deleting the deltemp
    this->num_pairs--; // number of pairs is decremented
}

void Dictionary::begin()
{
    if (num_pairs <= 0) // chcking if num_pairs are less than or equal to 0
    {
        throw std::length_error("Dictionary: begin(): Dictionary is empty"); // throwing the exception
    }
    current = findMin(root); // current is assigned to the min val in the tree
}

void Dictionary::end()
{
    if (num_pairs <= 0) // chcking if num_pairs are less than or equal to 0
    {
        throw std::length_error("Dictionary: end(): Dictionary is empty"); // throwing the exception
    }
    current = findMax(root); // current is assigned to the max value in the tree
}

void Dictionary::next()
{
    if (current == nil) // checking the current value is equal to nil
    {
        throw std::logic_error("Dictionary: next(): current undefined"); // throwing the exception
    }
    current = findNext(current); // current value is set to the next calue of the after the current node
}

void Dictionary::prev()
{
    if (current == nil) // checking current value is equal to nil
    {
        throw std::logic_error("Dictionary: prev(): current undefined"); // throwing the exception
    }
    current = findPrev(current); // current is set to previous value of the current node
}

std::string Dictionary::to_string() const
{
    std::string s = "";     // empty string is assigned
    inOrderString(s, root); // inorder string function is called and s and the root is passed
    return s;               // returning the string
}

std::string Dictionary::pre_string() const
{
    std::string s = "";      // empty string is assigned
    preOrderString(s, root); // preorder string function is called and s and the root is passed
    return s;                // returning the string
}

bool Dictionary::equals(const Dictionary &D) const
{
    return (num_pairs == D.num_pairs) && (to_string() == D.to_string()); // returning the bool value of two condition num_pair equal to D.num_pairs and to_string values of both are equal
}

std::ostream &operator<<(std::ostream &stream, Dictionary &D)
{
    return stream << D.to_string(); // stream is writtem by the dictionary value and converted to string
}

bool operator==(const Dictionary &A, const Dictionary &B)
{
    return A.equals(B); // returning the boolean value A equal B function value
}

Dictionary &Dictionary::operator=(const Dictionary &D)
{
    if (this != &D)
    {
        Dictionary temp = D;                  // copy of parameter is created
        std::swap(nil, temp.nil);             // swaping this' nil pointer to copy's nil pointer
        std::swap(root, temp.root);           // swaping this' root pointer to copy's root pointer
        std::swap(current, temp.current);     // swaping this' current pointer to copy's current pointer
        std::swap(num_pairs, temp.num_pairs); // swaping this' num_pair pointer to copy's num_pair pointer
    }
    return *this; // returning this pointer
}