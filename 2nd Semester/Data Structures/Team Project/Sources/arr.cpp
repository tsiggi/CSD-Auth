//Υλοποίηση 1) αταξινόμητος πίνακας
#include "../Headers/arr.h"

void arr::insert(string &s) //εισαγωγή νέας λέξης
{
    int p;

    if (!find(s,p))
    {
        if (c==size) //οι αυξήσεις που θα κάνουμε στον πίνακα θα είναι x2 θέσεις
        {
            word *temp= new (nothrow) word[2*size]; //ορίζουμε μεγαλύτερο πίνακα

            if(!temp)
            {
                cerr<<"!!!Memory Error!!!"<<endl;
            }

            for (int i=0; i<size; i++) //αντιγράφουμε τα δεδομένα
            {
                temp[i].w=b[i].w;
                temp[i].t=b[i].t;
            }

            delete [] b; //απελευθερώνουμε τον χώρο που έπιανε ο προηγούμενος πίνακας

            b = temp; //αντιγράφουμε την διεύθυνση του νέου πίνακα στον δείκτη μας
            size*=2; //αυξάνουμε το μέγεθος της size
        }
        b[c].w=s; //αντιγράφουμε συμβολοσειρά
        b[c].t=1; //αυξάνουμε επαναλήψεις
        //cout<<c<<endl;
        c++; //αυξάνουμε μετρητή
    }
    else
        increment(p);

}

void arr::increment(int p)
{
    b[p].t++;
}

bool arr::find(const string &s, int& pos) //αναζήτηση, δέχεται μία συμβολοσειρά για όρισμα
{
    for (int i=0; i<size; i++) //περνάει γραμμικά
    {
        if (b[i].w.compare(s)==0) //αν την βρει σε κάποιο κελί του πίνακα,
        {
            pos=i;
            return true;
        }
    }
    return false; //διαφορετικά επιστρέφει τιμή φρουρό
}

void arr::del(const string &s)
{
    int k;
    find(s,k);
    b[k].w=b[c-1].w;
    b[k].t=b[c-1].t;
    c--;
}


void arr::print()
{
    for (int i=0; i<c; i++)
        cout<<b[i].w<<" "<<b[i].t<<endl;
}
