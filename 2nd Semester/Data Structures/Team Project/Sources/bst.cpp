//Υλοποίηση 3) δυαδικό δένδρο αναζήτησης
#include "../Headers/bst.h"


int BST::search2(BST* root, string key)
{
    if (key.compare(root->w)==0) //αν το στοιχείο είναι στην ρίζα που ελέγχεται τώρα
    {
        return root->t;
    }

    if (key.compare(root->w)>0) //αν το στοιχείο είναι μεγαλύτερο από της ρίζας
        return search2(root->right, key);

    return search2(root->left, key); //αν το στοιχείο είναι μεγαλύτερο από της ρίζας
}

//κατασκευαστές
BST::BST() //λογικά δεν θα χρειαστεί κάπου
{
    w="";
    t=0;
    left=right=nullptr;
}

BST::BST(string value)
{
    w=value;
    t=1;
    left=right=nullptr;
}

//εισαγωγή
BST* BST::Insert(BST* root, string value)
{
    if (!search(root, value))
    {if (!root) //Αν η ρίζα δείχνει στο NULL
        {
            return new BST(value); //κατασκευάζουμε το δένδρο με ρίζα το στοιχείο
        }

        if (value.compare(root->w)>0)
        {
            //πηγαίνουμε δεξιά να το εισάγουμε
            root->right = Insert(root->right, value);
        }
        else //αν το στοιχείο είναι μικρότερο από της ρίζας
        {
            //πηγαίνουμε αριστερά να το εισάγουμε
            root->left = Insert(root->left, value);
        }
        return root; //επιστρέφουμε την ρίζα
    }
}

bool BST::search(BST* root, string key)
{
    if (!root) //αν δεν το βρήκε
        return false;

    if (key.compare(root->w)==0) //αν το στοιχείο είναι στην ρίζα που ελέγχεται τώρα
    {
        root->t++;
        return true;
    }

    if (key.compare(root->w)>0) //αν το στοιχείο είναι μεγαλύτερο από της ρίζας
        return search(root->right, key);

    return search(root->left, key); //αν το στοιχείο είναι μεγαλύτερο από της ρίζας
}

BST* BST::Delete(BST* root, string k)
{
    if (!root) //αν το δένδρο είναι κενό, δεν διαγράφουμε κάτι
        return root;

    //Ψάχνουμε να βρούμε που είναι το στοιχείο
    if (root->w.compare(k)>0)
    {
        root->left = Delete(root->left, k);
        return root;
    }
    else if (root->w.compare(k)<0)
    {
        root->right = Delete(root->right, k);
        return root;
    }

    //Μόλις το βρούμε ερχόμαστε εδώ

    // Αν ένα από τα παιδιά είναι άδεια
    if (!root->left) //ελέγχουμε το αριστερό
    {
        BST* temp = root->right;
        delete root;
        return temp;
    }
    else if (!root->right) //ελέγχουμε το δεξί
    {
        BST* temp = root->left;
        delete root;
        return temp;
    }

        // Αν υπάρχουν και τα δύο παιδιά
    else
    {
        BST* succParent = root; //ορίζουμε τον γονέα του διάδοχου

        // ορίζουμε τον δεξί κόμβο διάδοχο
        BST* succ = root->right;
        //επαναληπτικά τσεκάρουμε αν έχει αριστερό παιδί, αν έχει κάνουμε τον διάδοχο -> γονέα και τον αριστερό παιδί -> διάδοχο.
        while (succ->left)
        {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root) //αν ο γονέας του διάδοχου δεν είναι η ρίζα, τότε ορίζουμε ως αριστερό του κόμβο, τον δεξί κόμβο του διαδόχου
            succParent->left = succ->right;
        else //αλλιώς, ορίζουμε ως δεξί κόμβο του γονέα του διαδόχου, τον δεξί κόμβο του διαδόχου
            succParent->right = succ->right;

        // αντιγράφουμε τα δεδομένα από τον διάδοχο στην νέα ρίζα
        root->w = succ->w;
        root->t = succ->t;

        // διαγράφουμε τον διάδοχο και επιστρέφουμε την νέα ρίζα
        delete succ;
        return root;
    }
}

void BST::Inorder(BST* root, ofstream &a) //ενδοδιατεταγμένη διάσχιση, μας δίνει ταξινομημένα τα στοιχεία
{
    if (!root) {return;}
    Inorder(root->left, a);
    a << root->w << " " << root->t << endl;

    Inorder(root->right, a);
}

void BST::Postorder(BST* root, ofstream &a) //προδιατεταγμένη διάσχιση
{
    if (!root) {return;}
    Postorder(root->left, a);
    Postorder(root->right, a);
    a << root->w << " " << root->t << endl;
}

void BST::Preorder(BST* root, ofstream &a) //μεταδιατεταγμένη διάσχιση
{
    if (!root) {return;}
    a << root->w << " " << root->t << endl;
    Preorder(root->left, a);
    Preorder(root->right, a);
}
