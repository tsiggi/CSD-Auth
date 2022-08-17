//Υλοποίηση 3) δυαδικό δένδρο αναζήτησης
#ifndef bst_h
#define bst_h
#include <string>
#include <fstream>
using namespace std;

class BST //BinarySearchTree, Δυαδικό Δένδρο Αναζήτησης
{
private:
    BST *left, *right; //οι δείκτες στο αριστερό και δεξί παιδί
protected:
    string w;
    int t;
public:
    //κατασκευαστές
    BST();
    BST(string);

    virtual bool search(BST*, string);
    virtual int search2(BST*, string);
    BST* Insert(BST*, string); //εισαγωγή
    BST* Delete(BST*, string);

    virtual void Inorder(BST*, ofstream&);
    virtual void Postorder(BST*, ofstream&);
    virtual void Preorder(BST*, ofstream&);
};
#endif
