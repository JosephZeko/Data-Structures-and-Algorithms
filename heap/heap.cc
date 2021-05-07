//Joseph Zeko


#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

//Prototypes

void build_heap(vector<int>& v, int heap_size,bool(*compar)(int,int));
void heapify(vector<int>& v, int heap_size, int r, bool(*compar)(int,int));
bool less_than(int e1, int e2);
bool greater_than(int e1, int e2);
void heap_sort(vector<int>& v, int heap_size, bool(*compar)(int,int));
int extract_heap(vector<int>& v, int& heap_size, bool(*compar)(int,int));
void print_vector(vector<int>& v,int pos, int size);







const int HEAP_SIZE = 50;

int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    for (int i=1; i<=HEAP_SIZE; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+HEAP_SIZE+1 );

    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, HEAP_SIZE, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, HEAP_SIZE, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    return 0;
}


void build_heap(vector<int>& v, int heap_size, bool(*compar)(int, int)){
	for(int x = heap_size; x >= 1; x--){
		heapify(v,heap_size, x , compar); //calls heapify for each leaf moving up the tree
}
}

void heapify(vector <int>& v, int heap_size, int r, bool (*compar)(int,int)){
	int right = 2*r+1;
	int left = 2*r;
	int larg;
	int t;
// This follows the logic provided in class to find the largest node
	if(left<= heap_size){
	 if(compar(v[left],v[r])){
	  larg = left;
	}
	}
	else
	  larg = r;

	if(right <= heap_size){
	  if(compar(v[right],v[larg])){
	    larg = right;
	}
	}
//The exhange values part
        if(larg != r){ //if the largest isnt r, call r for the new largest
	 t = v[r];
	 v[r] = v[larg];
	 v[larg] = t;
	 heapify(v,heap_size,larg,compar); //recursivly calls itself down the heap
	}
}

//returns true if e1 is less then e2 else return flase
bool less_than( int e1, int e2) {
	if(e1 < e2){
	 return true;
	}
        else{
	 return false;
	}
}

//returns true if e1 is greater else return false
bool greater_than(int e1, int e2){
	if(e1 > e2){
	 return true;
	}
	else{
	 return false;
	}
}

int extract_heap(vector <int>& v, int& heap_size, bool (*compar)(int, int)){
	int r;
	if(heap_size < 1){ //if the size is less then 1 error
	 cout <<  "Error: Heap Underflow";
	}
	r = v[1]; //sets r to the v[1]
	v[1] = v[heap_size];  //moves the bottem to the root
	heap_size -= 1; //decrease size of heap
	heapify(v,heap_size,1,compar); //heapify again
	return r;


}

void heap_sort(vector <int>& v, int heap_size, bool(*compar)(int, int)) {
	for(int x = heap_size; x >=2; x--){
	 //extract the heap
	  v[x] = extract_heap(v,heap_size,compar); 
	}
         //reverse it
	reverse(v.begin()+1, v.end());
}

void print_vector(vector <int>&v , int pos, int size){
	while(pos <= size){
	 cout << setw(5) << v[pos] << " ";
	 if((pos%8) == 0){
	 cout << endl;
	 }
	pos++;
	}
cout << endl;
}



