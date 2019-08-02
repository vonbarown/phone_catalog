#include <iostream>

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Name {
public:
    string company;
    string cellName;
};

class Phone {
public:
    Name nm;
    int productnumber;
    double price;
    int quantityAvail;
};

void readdata (Phone [], int);
void printdb (Phone [], int);
void printphone(Phone []);
int findprice ( Phone [], int , double );

int main()
{
    //creating integer database
    Phone phonesale[10];
    Phone mn[10];
    int n=10,m;
    double searchprice;


    readdata(phonesale,n);
    printdb(phonesale,n);

    cout<< "Enter the price to be searched. ";
    cin >> searchprice;
   m=findprice(phonesale,n,searchprice);
    cout<<endl;
  if (m!=-1){
    cout<< "The phone is "<<phonesale[m].nm.cellName<<", made by " <<phonesale[m].nm.company<<". The product number is ", cout <<phonesale[m].productnumber<<"."<<endl;
    cout<< "The price is "<<"$"<< phonesale[m].price<< " and there are"<<phonesale[m].quantityAvail<<" units left in stock."<<endl;
    cout<<endl;
  }
  else
    cout<< "The price you entered is not on record.";
    return 0;
}


/**
I: data read in from a text file
P: data that s read in gets placed into array class objects
O: the data is read into the class object array
**/
void readdata (Phone cell [], int n)
{
    ifstream myInfile("Phones.txt");
    int product=0;
    while (product<n && !myInfile.eof()){
            myInfile>> cell[product].nm.cellName>> cell[product].nm.company>> cell[product].productnumber;
            myInfile>> cell[product].price>> cell[product].quantityAvail;
      product++;;
    }

}
/**
I: the array of class objects
P: calls the function to print items in object
O: the items in the object are printed to the screen
**/
void printdb (Phone cellprint[], int n)
{
    for (int i=0;i<n;i++)
        printphone(cellprint);

}

/**
I: object array is sent to the function
P: the different objects are called using their name is the object class
O: the values in the objects are printed to the screen
**/
void printphone(Phone cellprint[])
{
      int i;
        cout<< "The phone is "<<cellprint[i].nm.cellName<<", made by " <<cellprint[i].nm.company<<". The product number is ",
        cout <<cellprint[i].productnumber<<"."<<endl;
        cout<< "The price is "<<"$"<< cellprint[i].price<< " and there are "<<cellprint[i].quantityAvail<<" units left in stock."<<endl;
        cout<<endl;
        i++;
}
/**
I: object array and key to be searched is passed to the function
P: the key is compared to the value at the current index
O: the index of the key
**/
int findprice ( Phone cell [], int n, double searchprice)
{
    int f;
    for (int i=0; i<n; i++){
    if (cell[i].price==searchprice){
        return i;
        }
  }
return -1;

}
