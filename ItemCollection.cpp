#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "ItemCollection.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int barcode) {
  // TO BE COMPLETED
    unsigned int d = barcode;
    d /= 1000000;
    return d;
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int barcode) {
  // TO BE COMPLETED
    unsigned int d = barcode;
    d %= 1000000;
    d /= 100000;
    return d;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int barcode) {
  // TO BE COMPLETED
    unsigned int d = barcode;
    d %= 100000;
    d /= 10000;
    return d;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int barcode) {
  // TO BE COMPLETED
    unsigned int d = barcode;
    d %= 10000;
    d /= 1000;
    return d;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int barcode) {
    // TO BE COMPLETED
    unsigned int d = barcode;
    d %= 1000;
    d /= 100;
    return d;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct6(unsigned int barcode) {
    // TO BE COMPLETED
    unsigned int d = barcode;
    d %= 100;
    d /= 10;
    return d;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct7(unsigned int barcode) {
    // TO BE COMPLETED
    unsigned int d = barcode;
    d %= 10;
    return d;
}


// Constructor for struct Item
Item::Item(string itemColor, string itemShape, string itemBrand,
		 unsigned int barcode):itemColor_(itemColor),itemShape_(itemShape), itemBrand_(itemBrand),
				       barcode_(barcode)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void ItemCollection::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string itemColor;
    string itemShape;
    string itemBrand;
    unsigned int barcode;
    while (myfile >> itemColor >> itemShape >> itemBrand >> barcode) {
			if (itemColor.size() > 0)
      	addItem(itemColor, itemShape, itemBrand, barcode);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void ItemCollection::addItem(string itemColor, string itemShape, string itemBrand, unsigned int barcode) {
  // TO BE COMPLETED
  // function that adds the specified pair of glasses to main display (i.e., to all hash tables)

  Item item = Item(itemColor, itemShape, itemBrand, barcode);

  hT1.insert({barcode, item});
  hT2.insert({barcode, item});
  hT3.insert({barcode, item});
  hT4.insert({barcode, item});
  hT5.insert({barcode, item});
  hT6.insert({barcode, item});
  hT7.insert({barcode, item});
}

bool ItemCollection::removeItem(unsigned int barcode) {
  // TO BE COMPLETED
  // function that removes the pair of glasses specified by the barcode from the display
  // if pair is found, then it is removed and the function returns true
  // else returns false
  if (hT1.find(barcode) != hT1.end())
  {
    hT1.erase(barcode);
    hT2.erase(barcode);
    hT3.erase(barcode);
    hT4.erase(barcode);
    hT5.erase(barcode);
    hT6.erase(barcode);
    hT7.erase(barcode);
    return true;
  }
  else
    return false;
}

unsigned int ItemCollection::bestHashing() {
  // TO BE COMPLETED
  // function that decides the best has function, i.e. the ones among
  // fct1-fct7 that creates the most balanced hash table for the current
  // ItemCollection data member allItems

	// Hints:
	// Calculate the balance of each hashtable, one by one.
	/*
	 for (unsigned i=0; i<10; ++i) {
    cout << hT1.bucket_size(i); // Call bucket_size() to get the size of each bucket
  }
	*/
	// Then, calculate the lowest balance
  unsigned int balance[8];
  balance[0] = 0;

  unsigned int min_loc, max_loc;

  min_loc = hT1.bucket_size(0);
  for (unsigned i=1; i<10; ++i) {
    if (min_loc >= hT1.bucket_size(i))
      min_loc = hT1.bucket_size(i);
    else if (max_loc <= hT1.bucket_size(i))
      max_loc = hT1.bucket_size(i);
  }
  balance[1] = max_loc - min_loc;

  min_loc = hT2.bucket_size(0);
  for (unsigned i=1; i<10; ++i) {
    if (min_loc >= hT2.bucket_size(i))
      min_loc = hT2.bucket_size(i);
    else if (max_loc <= hT2.bucket_size(i))
      max_loc = hT2.bucket_size(i);
  }
  balance[2] = max_loc - min_loc;

  min_loc = hT3.bucket_size(0);
  for (unsigned i=1; i<10; ++i) {
    if (min_loc >= hT3.bucket_size(i))
      min_loc = hT3.bucket_size(i);
    else if (max_loc <= hT3.bucket_size(i))
      max_loc = hT3.bucket_size(i);
  }
  balance[3] = max_loc - min_loc;

  min_loc = hT4.bucket_size(0);
  for (unsigned i=1; i<10; ++i) {
    if (min_loc >= hT4.bucket_size(i))
      min_loc = hT4.bucket_size(i);
    else if (max_loc <= hT4.bucket_size(i))
      max_loc = hT4.bucket_size(i);
  }
  balance[4] = max_loc - min_loc;

  min_loc = hT5.bucket_size(0);
  for (unsigned i=1; i<10; ++i) {
    if (min_loc >= hT5.bucket_size(i))
      min_loc = hT5.bucket_size(i);
    else if (max_loc <= hT5.bucket_size(i))
      max_loc = hT5.bucket_size(i);
  }
  balance[5] = max_loc - min_loc;

  min_loc = hT6.bucket_size(0);
  for (unsigned i=1; i<10; ++i) {
    if (min_loc >= hT6.bucket_size(i))
      min_loc = hT6.bucket_size(i);
    else if (max_loc <= hT6.bucket_size(i))
      max_loc = hT6.bucket_size(i);
  }
  balance[6] = max_loc - min_loc;

  min_loc = hT7.bucket_size(0);
  for (unsigned i=1; i<10; ++i) {
    if (min_loc >= hT7.bucket_size(i))
      min_loc = hT7.bucket_size(i);
    else if (max_loc <= hT7.bucket_size(i))
      max_loc = hT7.bucket_size(i);
  }
  balance[7] = max_loc - min_loc;

   unsigned int temp = balance[1];
   for (int i = 2; i < 8; i++)
   {
     if (temp > balance[i])
     {
        temp = balance[i];
        min_loc = i;
     }
   }

   return min_loc;
}

// ALREADY COMPLETED
size_t ItemCollection::size() {
    if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) || (hT1.size() != hT7.size()))
  	throw std::length_error("Hash table sizes are not the same");

	return hT1.size();
}
