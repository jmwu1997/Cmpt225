

/* File: basic_int_stack.cpp

  Implementation of functions for basic simple array-based implementation of a stack.

*/

#include "char_stack.h"// contains the declarations of the variables and functions.

char_stack::char_stack(){
  // the default constructor intitializes the private variables.
  top_index = -1; // top_index == -1 indicates the stack is empty.
} 

void char_stack::push( char item ){
  top_index = top_index + 1;
  A[top_index] = item ;
}

char char_stack::top(){
  return A[top_index];
}

char char_stack::pop(){
  top_index = top_index - 1 ;
  return A[ top_index + 1 ];
}


bool char_stack::empty(){
  return top_index == -1 ; 
}

