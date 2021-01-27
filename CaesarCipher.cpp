#include "CaesarCipher.h"
#include <iostream>
using namespace std;

const string CaesarCipher::ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

CaesarCipher::CaesarCipher(const string& key){
  this->size_ = 1; // Start at one size
  int integerkey = stoi(key); // Turn the key into an integer

  while(integerkey > 10){ // While you can increment the size
    this->size_++; // Increment size
    integerkey /= 10;
  }

  this->key_ = new int[this->size_]; // Create array

  // Use a for statement to get the index for the key
  for(int index = 0; index < this->size_; index++){
    cout << "Adding " << key[index] - 48 << "\n";
    this->key_[index] = (key[index] - 48);
  }
  cout << "Key created:\n";

}  //to create the key_

CaesarCipher::~CaesarCipher(){
  delete [] this->key_;

}  //to release the memory for key_

string CaesarCipher::cipher(const string& s){
  string cipherstr = ""; // Create a copy for modifying
  // D
  int cipherindex = 0;
  int chardiff;
  string letter;
  for(int counter = 0; counter < s.length(); counter++){
    // Access key array to create the code
    if(ALPHABET.find(s.substr(counter, 1)) == string::npos){ // If there is a space
      cipherstr += s.substr(counter, 1); // Add the unmodified char to the deciphered string
      //cout << s.substr(counter, 1) << ", ";
    }

    else{ // If there is not a space
    letter = s.substr(counter, 1); // Get one char in string form
    chardiff = ALPHABET.find(letter); // Find the letter in the cipher

    // (chardiff + this->key_[cipherindex]) % 26 = letter to add to cipher
    letter = ALPHABET[((chardiff + this->key_[cipherindex]) % 26)];

    cipherstr += letter;

    //ALPHABET[(this->key_[cipherindex])];

    cipherindex++; // Move to next spot in the array
    cipherindex %= this->size_; // Restart the index if passed the array size
    }
  }


  return cipherstr;
}  //to encrypt a message

string CaesarCipher::decipher(const string& s){
string decipherstr = ""; // Create a copy for modifying
  // D
  int decipherindex = 0;
  int chardiff;
  string letter;
  for(int counter = 0; counter < s.length(); counter++){
    // Access key array to create the code
    if(ALPHABET.find(s.substr(counter, 1)) == string::npos) // If there is a space
      decipherstr += s.substr(counter, 1); // Add the unmodified char to the deciphered string

    else{ // If there is not a space
    letter = s.substr(counter, 1); // Get one char in string form
    chardiff = ALPHABET.find(letter); // Find the letter in the alphabet

    // ((chardiff - this->key_[decipherindex]) + 26) % 26 = letter to add to cipher. The + 26 before the % 26 prevents any minus characters from showing up as well as loops the ALPHABET array
    letter = ALPHABET[((chardiff - this->key_[decipherindex]) + 26) % 26];

    decipherstr += letter;

    //ALPHABET[(this->key_[cipherindex])];

    decipherindex++; // Move to next spot in the array
    decipherindex %= this->size_; // Restart the index if passed the array size
    }
  }


  return decipherstr;
}  //to descrypt a message