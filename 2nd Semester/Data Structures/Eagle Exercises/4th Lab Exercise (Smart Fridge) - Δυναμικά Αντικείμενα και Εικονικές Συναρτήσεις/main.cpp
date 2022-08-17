#include <iostream>
#include "PackedProduct.h"
#include "Product.h"
#include "Date.h"

#define MAX 50

using namespace std;


Product *readProduct()
{
    int year;
    int month;
    int day;
    char name[20];
    int grams;
    Date exp;
    bool packed;

    cout<<"\nGive product name: ";
    cin>>name;
    cout<<name;
    cout<<"\nGive weight in grams: ";
    cin>>grams;
    cout<<grams;
    cout<<"\nExpiry date (dd mm yyyy): ";
    cin>>day>>month>>year;
    cout<<day<<" "<<month<<" "<<year;
    exp = Date(day,month,year);

    cout<<"\nIs product packed (1-yes, 0-no): ";
    cin>>packed;
    cout<<packed;

    if (packed)
    {
        bool open;
        int lifetime;
        Date d;

        cout<<"\nWhat is the lifetime for an opened "<<name<<" in days: ";
        cin>>lifetime;
        cout<<lifetime;
        cout<<"\nThe packaging is open (1-yes, 0-no): ";
        cin>>open;
        cout<<open;

        if (open)
        {
            cout<<"\nWas the packaging opened today (1-yes, 0-no): ";
            int t;
            cin>>t;
            cout<<t;
            if (!t)
            {
                cout<<"\nOpening date (dd mm yyyy): ";
                cin>>day>>month>>year;
                cout<<day<<" "<<month<<" "<<year;
                d = Date(day,month,year);
            }
            else
            {
                d = Date(1,4,2021);
            }

        }

        PackedProduct *p = new PackedProduct(name,exp,grams,open,lifetime,d);
        return p;
    }

    Product *p = new Product(name,exp,grams);
    return p;
}


int main()
{
    Product *Fridge[50];
    int nof_products=0;
    char k;

    cout<<"Today is 1/4/2021.";
    do
    {
        cout<<"\n\nMenu:\n1. Insert Product\n2. Check for expired/expiring products\n3. Quit\n\nChoice:";
        cin>>k;
        cout<<k;

        switch (k)
        {
            case '1': if (nof_products<MAX)
                           Fridge[nof_products++] = readProduct();
                      break;
            case '2': cout<<"\n";
                      for (int i=0;i<nof_products;i++)
                      {
                          Date today = Date(1,4,2021);
                          Date e;
                          e = Fridge[i]->getExpiry();
                          int lt = today.diff(e);
                          if (lt<0 )
                              cout<<Fridge[i]->Getname()<<" expired!!!"<<endl;
                          else
                              cout<<Fridge[i]->Getname()<<" expires in "<<lt<<" days!"<<endl;
                      }
        }

    }
    while (k!='3');

}