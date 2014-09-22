/* 
 * File:   Inventory.h
 * Author: kim
 *
 * Created on July 23, 2014, 9:36 PM
 */

#ifndef INVENTORY_H
#define	INVENTORY_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "BookRecord.h"

using namespace std;

class Inventory

{
private:
    vector<BookRecord> books;
    
public:
    Inventory(){};
    virtual ~Inventory(){};
    
    // Accessor function
    // Allow other modules to get books from inventory
    vector<BookRecord>& getBooks() 
    { 
        return books; 
    }
    
    // Functions
    void loadFile();
    int searchBooks(string ISBNinput);
    void listBookInformation(string ISBNinput);
    void deleteBook(string ISBNinput);
    void sellABook(string ISBNinput);
    bool checkISBN(string ISBNinput);
    void editBook(string ISBNinput);
    void addBook();
    void dumpFile();
      

};

#endif	/* INVENTORY_H */

