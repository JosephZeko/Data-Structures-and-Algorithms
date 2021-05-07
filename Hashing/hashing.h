//Joseph Zeko
//Z1797401
//4.19.2019
//CSCI 340

#ifndef HASHING_H
#define HASHING_H
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

struct Entry {
    std::string key;
    std::string description;
    Entry() { key = "---"; }
};

class HT {
    private:
        std::vector<Entry>* hTable;
        int table_size;
        int item_count;
        int hashing(const std::string&);
    public:
        HT(int size);
        ~HT();
        bool insert(const Entry&);
        int search(const std::string&);
        bool remove(const std::string&);
        void print();
};

//DEFUALT CONSTRUCTOR
HT :: HT (int s = 11){
//Initilizes the values
hTable = new vector<Entry>(s);
table_size = s;
item_count = 0;
}

//DECONSRUCTOR
HT :: ~HT (){
delete hTable;
}

//SEARCH FUNCTION
int HT :: search ( const string& key ) {
int index = hashing(key);
 for(int x = 0; x < table_size; x++){
  if((*hTable)[index +1].key == key){
     return index;
  }
   index = (index +1)% table_size;
 }
return -1;
}


//INSERT FUNCTION
bool HT :: insert(const Entry& e) {
int index = hashing(e.key);

 if(search(e.key) != -1){ //Checks to make sure the key isnt already in the table
  cerr << "Key is already found, Cannot insert" << endl; //error message
  return false;
  }

 else if(item_count == table_size){ //Checks to make sure the table isnt already full
   cerr << "The table is already full :( " << endl;//error message
   return false;
   }

 else{
  unsigned int x;
  for(x = 0; x < table_size; x++){ //loops thru the table
    if((*hTable)[index].key == "---" || (*hTable)[index].key == "+++"){ //if the key is empty
      (*hTable)[index] = e;                                             //put the e in table
      item_count = item_count + 1; //increment the table by 1

      return true;
     }
   index = index + 1 & table_size;
}
}
return false;
}


//REMOVE FUNCTION
bool HT :: remove(const string& s){
 if(search(s) == -1){ //checks to see if the key is in the index
   return false;
   }

 else{
  int index = search(s); //index is equal to where s is found

 (*hTable)[index].key = "+++"; //sets the key = to +++ meaning it had a value removed
  item_count = item_count - 1; //reduce the item count
  return true;
 }
}

//PRINT FUNCTION
void HT :: print(){
 cout << endl << " ----Hash Table----" << endl; //prints the header

 for(int x = 0; x < table_size; x++){
  if((*hTable)[x].key != "---" && (*hTable)[x].key != "+++"){ //if the key isnt empty print the value
    cout << right << setw(2) << x << ":" << (*hTable)[x].key << " " << (*hTable)[x].description << endl; //prints the number then the key then the description
  }
 }
cout << "----------------" << endl << endl;
}

#endif
