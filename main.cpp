#include <iostream>
#include <string>
#include <fstream>
#include "CaesarCipher.h"
#include "CharStack.h"
using namespace std;
/*
  Code segment for encrypting and decrypting a message has been provided for you in the main() function. You will need to implement related methods.
  
  You will need to add related statements to process the "message.txt" file one character at a time and use an undo and a redo stack to figure out what message is to be encrypted.
  g++ main.cpp CaesarCipher.cpp CharStack.cpp

*/

int main() {
  string message = ""; //This is to eventually store the message to be encrypted
  ifstream input;
  input.open("message.txt");
  string line;
  char userinput;
  CharStack undo, redo;
  // Input the message in first
  cout << "First, we will process from message.txt\n";
    // If file is open
  if(input.is_open())
    while(!(input.eof())){ // While file is not empty
      // Get the line then go through each char
      getline(input, line);
      for(int counter = 0; counter < line.length(); counter++){
          userinput = line[counter];

        // Compare the char to see what command it is performing
        if(userinput == '<'){ // if char is "undo" option
          if(!undo.isEmpty()){ // if undo is not empty
            redo.push(undo.top()); // Push the top of undo into redo
            undo.pop(); // Pop the undo
          }
        }
        else
          if(userinput == '>'){ // if char is "redo" option
            if(!redo.isEmpty()){ // if redo is not empty
              undo.push(redo.top()); // Push the top of redo into undo
              redo.pop(); // Pop the redo
            }
          }
          else{ // Char is not a redo or undo command
              undo.push(userinput); // Push the char onto the undo stack
              while(!redo.isEmpty()) // While redo is not empty
              redo.pop(); // Keep popping the stack
          }
      }
    }

    // The string is reversed in the charstack so we must reverse it using the redo
    for(undo.isEmpty(); undo.isEmpty() == false; undo.pop()){
      redo.push(undo.top());
    }
    // Now we can add it to the list
    for(redo.isEmpty(); redo.isEmpty() == false; redo.pop()){
      message += redo.top();
    }
    cout << "Message Processed.\n";

  string key; //This is to collect the multi-digit key from the user
  cout << "What is your key (digits only)? ";
  cin >> key;
  cin.ignore();
  CaesarCipher multiple_bits(key);

  //This code block is to help test your cipher and decipher methods
  string testing_message = "FREE PIZZA IN THE CAFETERIA";
  cout << "Testing cipher: " << endl;
  cout << testing_message << endl;
  cout << "====>" << endl;
  string encrypted_message = multiple_bits.cipher(testing_message);
  cout << encrypted_message << endl;
  cout << "Testing decipher: " << endl;
  cout << multiple_bits.decipher(encrypted_message) << endl << endl;

  //Now, you are ready to apply the cipher and decipher to the message
  cout << "Applying cipher to the message from the undo stack:" << endl;
  cout << message << endl;
  cout << "Encrpted to:" << endl;
  encrypted_message = multiple_bits.cipher(message);
  cout << encrypted_message << endl;
  cout << "Decrypted back to:" << endl;
  cout << multiple_bits.decipher(encrypted_message) << endl;

  return 0;

}