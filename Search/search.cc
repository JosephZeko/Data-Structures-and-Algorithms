//Joseph Zeko

#include <vector>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
using namespace std;


const int DATA_SIZE = 100;
const int SEARCH_SIZE = 50;
const int DATA_SEED = 11;
const int SEARCH_SEED = 7;

void genRndNums( vector<int>& v, int seed ) {
 srand(seed);  //sets the seed for the rand function
 for(unsigned x = 0; x < v.size(); x++){  //loops thru the entire v vector
  v[x] = rand()% 100 + 1;  //sets each member of v to a random number between 100 and 1
 }
}

bool linearSearch( const vector<int>& inputVec, int x) {
vector<int>::const_iterator found; //sets a const iterator to found(where the value was found)
found = find(inputVec.begin(), inputVec.end(), x); //looks thru the vector using find()
if(found != inputVec.end())  //if found is not equal to last, the value was found
  return true;
else
  return false;  //else return false
}

bool binarySearch( const vector<int>& inputVec, int x) {
 if(binary_search(inputVec.begin(), inputVec.end(), x)) //if binary_search() returns true, return true
  return true;
 else
  return false;  //else return false
}

int search( const vector<int>& inputVec, const vector<int>& searchVec,
            bool (*p)( const vector<int>&, int) ){
int count = 0; //sets count to 0
  for(int x = 0; x < searchVec.size(); x++){ //loops thru searchVec
   if(p(inputVec,searchVec[x])){  //if p returns true, add 1 to count
    count++;
   }
  }
  return count; //returns count
}

void sortVector (vector<int>& inputVec) {
sort(inputVec.begin(), inputVec.end()); //sorts the passed in vector with the sort() function
}

void printStat (int totalSucCnt, int vec_size) {
double SucPercent = totalSucCnt*100 / vec_size; //sets the new double SucPercent to the total count times a huandred divided by the total size, giving us a percent
cout <<fixed <<setprecision(2) <<"successful searches: " << SucPercent << "%" << endl; //sets decimals to 2 points out then prints the percent
}

void print_vec( const vector<int>& vec ){
for(int x = 0; x < vec.size(); x++){ //loops thru the entire passed in vector
 if(x%10 == 0) //every ten numbers end the line
  cout << endl;
 cout << setw(6); //set width to 6
 cout << vec.at(x) << " "; //print
}
 cout << endl; 
}

int main() {
    vector<int> inputVec(DATA_SIZE);
    vector<int> searchVec(SEARCH_SIZE);
    genRndNums(inputVec, DATA_SEED);
    genRndNums(searchVec, SEARCH_SEED);

    cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
    print_vec( inputVec );
    cout << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
    print_vec( searchVec );

    cout << "\nConducting linear search on unsorted data source ..." << endl;
    int linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on unsorted data source ..." << endl;
    int binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    sortVector( inputVec );

    cout << "\nConducting linear search on sorted data source ..." << endl;
    linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on sorted data source ..." << endl;
    binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    return 0;
}

