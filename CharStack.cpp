#include "CharStack.h"
#include <iostream>
using namespace std;

CharStack::CharStack(){
  this->top_ = nullptr;
}  //create an empty stack

CharStack::~CharStack(){
  //to be implemented
  Node *deleteptr = nullptr;
  Node *currentptr = this->top_; // Start at beginning
  while(currentptr != nullptr){
    deleteptr = currentptr; // Go to the delete spot
    currentptr = currentptr -> next; // Move current to the next spot
    delete deleteptr; // Delete the spot current was at
  }
  cout << "LinkedStack Object Deleted\n";;
} //release all nodes

bool CharStack::isEmpty() const{
  return (this->top_ == nullptr);
} //return true for an empty stack, false otherwise

char& CharStack::top() const{
  char *retptr;
  if(this->top_ != nullptr) // If there is a top letter
    retptr = &this->top_->letter;
  else // If there not a top letter
    *retptr = '0';

  return *retptr;
}    //return the reference to the top character
void CharStack::push(char val){
Node *nodeptr = new Node {val, nullptr}; // Create new node
  Node *tempptr = nullptr; // Call a temp space to use if needed

  if(this->top_ != nullptr){ // If at least one value is stored

    tempptr = this->top_;
    this->top_ = nodeptr; // Place on top of the stack
    this->top_->next = tempptr; // Place the other parts below the stack
  }
  else{ // Stack is empty
  // Begin new stack
  this->top_ = nodeptr;
  }
}     //push a character to the top of the stack
void CharStack::pop(){
  Node *deleteptr = nullptr; // Used for deletion if needed
  if(this->top_ != nullptr){ // If stack is not empty 
    deleteptr = this->top_;
    this->top_ = this->top_->next;
    delete deleteptr;
  }
  else
    cout << "Can not pop from stack: Stack is empty\n";

}           //pop the top character from the stack
void CharStack::display() const{
  string retstr = "";
  Node *printerptr = this->top_;

  if(printerptr == nullptr)
    cout << "Can not print stack: Stack is empty";
  else
    while(printerptr != nullptr){
      cout << printerptr->letter; 
      cout << ", ";
      printerptr = printerptr -> next;  // Move to the next node
    }
  cout << "\n";

} //for testing purpose