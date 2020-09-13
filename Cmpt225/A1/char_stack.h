

/* File: basic_int_stack.h       

  Header file for a very basic array-based implementation of a stack.

*/

class char_stack
{
  public:
    // This part should be implementation independent.
    char_stack(); // constructor
    void push( char item );
    char pop(); 
    char top();
    bool empty();

  private:
    static const int capacity = 1000 ; // the array size 
    int A[capacity] ; // the array.
    int top_index ; // this will index the top of the stack in the array
};
