#pragma once
#include <string>
#include <unordered_map>
using std::string;

//******************************
// Struct and classes
//******************************

// struct to store all the info about a particular pair of glasses
struct Item{
  string itemColor_;
  string itemShape_;
  string itemBrand_;
  unsigned int barcode_;
  Item(string itemColor="", string itemShape="", string itemBrand="",
	  unsigned int barcode=1000000);
};

// TO BE COMPLETED: unary function to return the hash value based on
// the first digit of some unique 7-digit key
unsigned int hashfct1(unsigned int);

// TO BE COMPLETED: unary function to return the hash value based on
// the second digit of some unique 7-digit key
unsigned int hashfct2(unsigned int);

// TO BE COMPLETED: unary function to return the hash value based on
// the third digit of some unique 7-digit key
unsigned int hashfct3(unsigned int);

// TO BE COMPLETED: unary function to return the hash value based on
// the fourth digit of some unique 7-digit key
unsigned int hashfct4(unsigned int);

// TO BE COMPLETED: unary function to return the hash value based on
// the fifth digit of some unique 7-digit key
unsigned int hashfct5(unsigned int);

// TO BE COMPLETED: unary function to return the hash value based on
// the sixth digit of some unique 7-digit key
unsigned int hashfct6(unsigned int);

// TO BE COMPLETED: unary function to return the hash value based on
// the seventh digit of some unique 7-digit key
unsigned int hashfct7(unsigned int);

//******************************
// Typedef for custom hash table
//******************************
typedef std::unordered_map<unsigned int, Item, decltype(&hashfct1)> CustomHashTable;


// class to store the bow collection
class ItemCollection {
public:
  // function that adds the specified pair of glasses to main display. TO BE COMPLETED
  void addItem(string itemColor, string itemShape, string itemBrand, unsigned int barcode);

  // removes a specified pair of glasses from the main display; if successful,
  // then it returns true; TO BE COMPLETED
  bool removeItem(unsigned int barcode);

  // identifies which hash function (among the seven provided, fct1 - fct7)
  // computes the most balanced hash table; TO BE COMPLETED
  unsigned int bestHashing();

  // Load information from a text file
  // with the given filename; THIS FUNCTION IS COMPLETE
  void readTextfile(string filename);

  // size of a hashtable. Throws exception if the sizes differ. Completed
  size_t size();

  // constructor that initializes seven hashtables with different hash functions
  ItemCollection():
    hT1{10,hashfct1},
    hT2{10,hashfct2},
    hT3{10,hashfct3},
    hT4{10,hashfct4},
    hT5{10,hashfct5},
    hT6{10,hashfct6},
    hT7{10,hashfct7}{ }

private:
  CustomHashTable hT1, hT2, hT3, hT4, hT5, hT6, hT7;
  // add other private member variables as needed
};
