//Joseph Zeko

#include "hashing.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
int HT::hashing(const string& key) {
   return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
}

//GET ENTRY FUCNTION
Entry* get_entry(const string& line){
 Entry* parLine = new Entry; //create new entry called parLine

 parLine -> key = line.substr(2,3); //takes the item key addint it to parLine
 parLine -> description = line.substr(6,line.length() - 6); //takes the description adding it to parLine
 return parLine; //returns the new Entry with the key and description
}

//GET KEY FUNCTION
string get_key(const string& line){
 string Key = line.substr(2,3); //just geets the key from the line using the fact that
 return Key;                   // we know the key starts at the 2nd char
}




int main(int argc, char** argv ) {
    if ( argc < 2 ) {
        cerr << "argument: file-name\n";
        return 1;
    }

    HT ht;
    ifstream infile(argv[1], ios::in);
    string line;
    infile >> line;    
    while ( !infile.eof() ) {
        if ( line[0] == 'A' ) { 
            Entry* e = get_entry( line );
            ht.insert( *e );
            delete e;
        }
        else {
            string key = get_key(line);
            if ( line[0] == 'D' ) {
                cout << "Removing " << key << "...\n";
                bool removed = ht.remove( key );
                if ( removed )
                    cout << key << " is removed successfully...\n\n";
                else
                    cout << key << " does not exist, no key is removed...\n\n";
            }
            else if ( line[0] == 'S' ) {
                int found = ht.search( key );
                if ( found < 0 ) 
                    cout << key << " does not exit in the hash table ..." << endl << endl;
                else
                   cout << key << " is found at table position " << found << endl << endl;
            }
            else if ( line[0] == 'P' ) {
                cout << "\nDisplaying the table: " << endl;
                ht.print();
            }
            else
                cerr << "wrong input: " << line << endl;
        }
        infile >> line;
 
    }

    infile.close();
    return 0;
}
