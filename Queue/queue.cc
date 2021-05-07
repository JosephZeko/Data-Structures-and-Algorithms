//Joseph Zeko
#include <iomanip>
#include <iostream>
using std::setw;
using namespace std;

   bool Queue::empty() const{
     if(s1.empty() && s2.empty()){ //checks if both s1 and s2 are empty
       return true;              //return true if both are empty
     }
     else{
       return false;            //else return false
     }
   }

   int Queue::size() const{
     return s1.size() + s2.size(); //returns the size of s1 added to the size of s2
   }

   int Queue::front(){
     if(s2.size() == 0){         //if s2 is empty
       while(s1.size() != 0){     //while s1 isnt empty
         s2.push(s1.top());    //put the value of top of s1 onto s2
         s1.pop();             //delete value of top most s1 value
       }
      }
     return s2.top();     //return the top(or front of s1 since its upside down now) of s2
    }

   int Queue::back(){
     if(s1.size() == 0){   //if s1 is empty
       while(s2.size() != 0){ //while s2 isnt empty
          s1.push(s2.top());  //put the value of top of s2 onto s1
          s2.pop();             //delete the value top value of s2
        }
        }
       return s1.top();       //return the top of s1
     }

   void Queue::push(const int& val){     
      s1.push(val);             // push the value into s1 
   }

   void Queue::pop(){
      if(s2.size() == 0){  //this is identacle to the front() funtion
       while(s1.size() != 0){
         s2.push(s1.top());
          s1.pop();
         }
         }
      }



int main() {
    Queue q;
    string op;
    int val = 0;
 
   cout << "operation -- size front end" << endl;
   cin >> op;
   while ( !cin.eof() ) {
        if ( op == "push" ) {
            cin >> val;
            q.push( val );
            cout << op << " " << val << "    -- ";
        }
        else if ( op == "pop" ) {
            q.pop();
            cout << op << "       -- ";
        }
        else {
            cerr << "Error input: " << op << endl;
            return 1;
        }
        if ( q.size() > 0 )
            cout << setw(3) << q.size() << setw(5) << q.front() << setw(5) << q.back() << endl;
        else
            cout << setw(3) << q.size() << endl;

        cin >> op;
    }

    while ( !q.empty() )
        q.pop();

    return 0;
}
