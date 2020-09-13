#include "btree_set.h" // 
#include "btree_container.h" //
#include "btree.h" //
#include <iostream> // I/O library.
#include <algorithm> // Includes sort()
#include <ctime> // access to the system clock
#include <time.h> // access to "wall clock"
using namespace std;

double elapsed_time( clock_t start, clock_t finish){
   // returns elapsed time in milliseconds
   return (finish - start)/(double)(CLOCKS_PER_SEC/1000);
}
   

int main (int argc, char * const argv[]) {
   float runtime = 0;
   float nodes = 0;
   float height = 0;
   float avg_bytes = 0;
   int times = 10 ; // number of times to run - mean is reported.
   int node_size= 16;
   int SIZE = 5; // size of array to work on.
   srand( time(NULL) ); // seed the random number generator.

   clock_t start, finish ;// used to time function calls.
   cout << "Test start" << endl;
   cout << "Array size = " << SIZE<<", Node size = " << node_size <<", test start " << endl;
   
   for( int t = 0 ; t < times ; t++ ){
      btree::btree_set<int,std::less<int>,std::allocator<int>,16> S1 ;
      for(int i = 0 ; i < SIZE ; i++ ){
          int x = rand() % SIZE*10;
          start = clock();
	  S1.insert(x);
	  finish = clock();
	  runtime += elapsed_time(start,finish);
      }
 
	nodes += S1.nodes();

	height += S1.height();

	avg_bytes += S1.average_bytes_per_value();      
      

   }

   cout << "B tree nodes: " << nodes / times << endl ;
   cout << "B tree height: " << height / times << endl ;
   cout << "B tree bytes: " << avg_bytes / times << endl ;
   cout << "B tree runtime(ms): " << runtime/times << endl ;
   cout << "size of int"<< sizeof(int)<<endl;
   cout << "Test end" << endl;
   
   return 0;
}

