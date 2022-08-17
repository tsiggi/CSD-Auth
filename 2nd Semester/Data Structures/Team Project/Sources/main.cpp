#include <iostream>
#include <fstream> //file stream, για να διαβάζεις αρχεία
#include <chrono>  // for high_resolution_clock
using namespace std;

#include "../Headers/clear.h" //εισάγει την συνάρτηση προεπεξερασίας string
#include "../Headers/sarr.h" //εισάγει την κλάση των 2 πινάκων //ΔΕΝ ΕΧΩ ΔΟΚΙΜΑΣΕΙ ΑΝ ΔΟΥΛΕΥΕΙ Η ΔΙΑΓΡΑΦΗ
#include "../Headers/avl.h" //εισάγει τα δύο δυαδικά δένδρα
#include "../Headers/HashTable.h"

const int Q_SIZE=5000;
int main()
{
    //ορισμός των δομών
    arr arrayF;
    sarr sortedArray;
    BST bintree, *root = nullptr;
    AVL avltree, *avlroot=nullptr;
    hashtable has;
    string s;

    ifstream File; //Το File είναι η μεταβλητή που έχει το αρχείο.
    File.open("small-file.txt"); //Ανοίγει το αρχείο

    string Q[Q_SIZE];
    int counter=0;

    if (!File) //Ελέγχεις ότι υπάρχει το αρχείο και κατάφερε να το ανοίξει
    {
        cerr << "Unable to open file";
        return 1;
    }

    //Έναρξη γεμίσματος δομών
    do
    {
        File >> s;
        s=clear(s);
    }
    while (s.empty());

    arrayF.insert(s);
    sortedArray.insert(s,0);
    root=bintree.Insert(root, s);
    avlroot=avltree.Insert(avlroot, s);
    has.insert(s);
    Q[counter]=s;
    counter++;

    int fa,fb,fc;

    while (File >> s) //Διαβάζεις από το αρχείο, λέξη λέξη
    {
        s=clear(s); //την καθαρίζεις από σκουπίδια (αφήνει μόνο τα γράμματα)
        if (!s.empty()) //αποκλείεις συμβολοσειρές αριθμών και συμβόλων
        {
            if (counter<Q_SIZE)
            {
                Q[counter]=s;
                counter++;
            }
            has.insert(s);

            arrayF.insert(s); //αν δεν το βρει, το εισάγει

            sortedArray.insert(s);

            bintree.Insert(root, s);

            avlroot=avltree.Insert(avlroot, s);
        }
    }
    File.close(); //Κλείνεις το αρχείο

    ofstream out;
    out.open("output.txt");

    out<<"1) Unsorted Array:"<<endl<<endl;
    auto start = chrono::high_resolution_clock::now();
    for (int i=0;i<counter;i++)
    {
        arrayF.find(Q[i],fa);
        out<<Q[i]<<" "<<arrayF.getT(fa)<<endl;
    }
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    out<<endl<<"Elapsed time: "<<elapsed.count()<<"s"<<endl<<endl;

    cout<<"1) Unsorted Array:         "<<"Elapsed time: "<<elapsed.count()<<"s"<<endl;

    out<<"2) Sorted Array:"<<endl<<endl;
    start = chrono::high_resolution_clock::now();
    for (int i=0;i<counter;i++)
    {
        sortedArray.find(Q[i],fb);
        out<<Q[i]<<" "<<sortedArray.getT(fb)<<endl;
    }
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    out<<endl<<"Elapsed time: "<<elapsed.count()<<"s"<<endl<<endl;

    cout<<"2) Sorted Array:           "<<"Elapsed time: "<<elapsed.count()<<"s"<<endl;

    out<<"3) Binary Search Tree:"<<endl<<endl;
    start = chrono::high_resolution_clock::now();
    for (int i=0;i<counter;i++)
    {
        out<<Q[i]<<" "<<bintree.search2(root, Q[i])<<endl;
    }
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    out<<endl<<"Elapsed time: "<<elapsed.count()<<"s"<<endl<<endl;

    cout<<"3) Binary Search Tree:     "<<"Elapsed time: "<<elapsed.count()<<"s"<<endl;

    out<<"4) AVL Binary Search Tree:"<<endl<<endl;
    start = chrono::high_resolution_clock::now();
    for (int i=0;i<counter;i++)
    {
        out<<Q[i]<<" "<<avltree.search2(avlroot, Q[i])<<endl;
    }
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    out<<endl<<"Elapsed time: "<<elapsed.count()<<"s"<<endl<<endl;

    cout<<"4) AVL Binary Search Tree: "<<"Elapsed time: "<<elapsed.count()<<"s"<<endl;

    out<<"5) Hash Array:"<<endl<<endl;
    start = chrono::high_resolution_clock::now();
    for (int i=0;i<counter;i++)
    {
        out<<Q[i]<<" "<<has.GetTimes(Q[i])<<endl;
    }
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    out<<endl<<"Elapsed time: "<<elapsed.count()<<"s"<<endl<<endl;

    cout<<"5) Hash Array:             "<<"Elapsed time: "<<elapsed.count()<<"s";


    out.close();


}
