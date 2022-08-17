//Υλοποίηση 4) δυαδικό δένδρο αναζήτησης AVL
#include "../Headers/avl.h"

AVL::AVL():BST() //λογικά δεν θα χρειαστεί κάπου
{
    h=0;
    left=right=nullptr;
}

AVL::AVL(string value):BST(value)
{
    h=1;
    left=right=nullptr;
}

//ύψος κόμβου
int AVL::getHeight(AVL* N)
{
    if (!N)
        return 0;
    return N->h;
}

// παράγοντας ισορροπίας κόμβου
int AVL::getBalance(AVL *N)
{
    if (!N)
        return 0;
    return (getHeight(N->left)) - getHeight(N->right);
}

//δεξιά περιστροφή
AVL* AVL::rightRotate(AVL* y)
{
    AVL *x = y->left;
    AVL *T2 = x->right;

    // εκτελούμε περιστροφή
    x->right = y;
    y->left = T2;

    // ενημερώνουμε τα ύψη
    y->h = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->h = max(getHeight(x->left), getHeight(x->right)) + 1;

    // επιστρέφουμε την νέα ρίζα
    return x;
}

//αριστερή περιστροφή
AVL* AVL::leftRotate(AVL* x)
{
    AVL *y = x->right;
    AVL *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->h = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->h = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Αναδρομική συνάρτηση εισαγωγής. Επιστρέφει την νέα ρίζα.
AVL* AVL::Insert(AVL* node, string key)
{
    if (!search(node, key)){
        // 1. Perform the normal BST insertion
        if (!node)
            return new (nothrow) AVL(key);

        if (key.compare(node->w) < 0)
            node->left = Insert(node->left, key);
        else if (key.compare(node->w) > 0)
            node->right = Insert(node->right, key);
        else // Equal keys are not allowed in BST δεν θα μπει ποτέ εδώ
            return node;

        /* 2. Update height of this ancestor node */
        node->h = 1 + max(getHeight(node->left), getHeight(node->right));

        /* 3. Get the balance factor of this ancestor
            node to check whether this node became
            unbalanced */
        int balance = getBalance(node);

        // If this node becomes unbalanced, then
        // there are 4 cases

        // Left Left Case
        if (balance > 1 && key.compare(node->left->w)<0)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key.compare(node->right->w) > 0)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key.compare(node->left->w) > 0)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key.compare(node->right->w) < 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    /* return the (unchanged) node pointer */
    return node;
}

int AVL::search2(AVL* root, string key)
{
    if (key.compare(root->w)==0) //αν το στοιχείο είναι στην ρίζα που ελέγχεται τώρα
        return root->t;

    if (key.compare(root->w)>0) //αν το στοιχείο είναι μεγαλύτερο από της ρίζας
        return search2(root->right, key);

    return search2(root->left, key); //αν το στοιχείο είναι μεγαλύτερο από της ρίζας
}

bool AVL::search(AVL* root, string key)
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

void AVL::Inorder(AVL* root, ofstream &a) //ενδοδιατεταγμένη διάσχιση
{
    if (!root) {return;}
    Inorder(root->left, a);
    a << root->w << " " << root->t << endl;
    Inorder(root->right, a);
}

void AVL::Postorder(AVL* root, ofstream &a) //προδιατεταγμένη διάσχιση
{
    if (!root) {return;}
    Postorder(root->left, a);
    Postorder(root->right, a);
    a << root->w << " " << root->t << endl;
}

void AVL::Preorder(AVL* root, ofstream &a) //μεταδιατεταγμένη διάσχιση
{
    if (!root) {return;}
    a << root->w << " " << root->t << endl;
    Preorder(root->left, a);
    Preorder(root->right, a);
}

AVL* AVL::minValue(AVL* node)
{
    AVL* current = node;

    // πηγαίνουμε τέρμα αριστερά
    while (current->left)
        current = current->left;

    return current;
}

// Αναδρομική συνάρτηση για διαγραφή κόμβου. Επιστρέφει την ρίζα του νέου δένδρου.
AVL* AVL::Delete(AVL* root, string key)
{

    // ΒΗΜΑ 1: ΑΝ ΡΙΖΑ ΕΙΝΑΙ NULL
    if (!root)
        return root;

    // αν η λέξη προς διαγραφή είναι μικρότερη από την λέξη της ρίζας, πάμε αριστερά
    if (key.compare(root->w) < 0)
        root->left = Delete(root->left, key);

        // αν η λέξη προς διαγραφή είναι μεγαλύτερη από την λέξη της ρίζας, πάμε δεξιά
    else if( key > root->w)
        root->right = Delete(root->right, key);

        // αν η λέξη προς διαγραφή είναι αυτή της ρίζας
    else
    {
        // κόμβος με ένα ή κανένα παιδί
        if(!root->left || !root->right)
        {
            AVL *temp = root->left ? root->left : root->right;

            // κανένα παιδί
            if (!temp)
            {
                temp = root;
                root = nullptr;
            }
            else // ένα παιδί
                *root = *temp; // αντιγράφουμε τα περιεχόμενα του όχι-άδειου παιδιού
            delete temp;
        }
        else
        {
            // κόμβος με δύο παιδιά: βρίσκουμε τον διάδοχο κόμβο από ενδοδιατεταγμένη
            AVL* temp = minValue(root->right);

            // αντιγράφουμε τα δεδομένα του διαδόχου
            root->w = temp->w;

            // διαγράφουμε τον διάδοχο
            root->right = Delete(root->right,	temp->w);
        }
    }

    // αν το δένδρο είχε ένα κόβμο τότε τον επιστρέφουμε
    if (!root)
        return root;

    // ΒΗΜΑ 2: ΕΝΗΜΕΡΩΝΟΥΜΕ ΤΟ ΤΡΕΧΟΝΤΟΣ ΚΟΜΒΟΥ
    root->h = 1 + max(getHeight(root->left), getHeight(root->right));

    // ΒΗΜΑ 3: ΒΡΙΣΚΟΥΜΕ ΤΟΝ ΠΑΡΑΓΟΝΤΑ ΙΣΟΡΡΟΠΙΑΣ (για να ελέγξουμε αν δεν είναι ισορροπημένο
    int balance = getBalance(root);

    // Αν αυτός ο κόμβος γίνει ανισόρροπος, τότε υπάρχουν 4 περιπτώσεις

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
