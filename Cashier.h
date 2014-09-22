//
//  Cashier.h
//  Bookstore
//
//  Created by Calvin Yin on 7/16/14.
//  Copyright (c) 2014 Calvin Yin. All rights reserved.
//

#ifndef Bookstore_Cashier_h
#define Bookstore_Cashier_h

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "BookRecord.h"
using namespace std;

class Cashier{
private:
    vector<BookRecord>& books;
    double sales_tax;
    double book_price;
    double subtotal;
    double total_price;
public:
    Cashier(vector<BookRecord> &b):books (b){}
    
    vector<BookRecord> & getBooks(){
        return books;
    }
    
    int searchBooks(string ISBNinput);
    void deleteBook(string ISBNinput);
    void returnBook(string ISBNinput);
    void lookupBook(string ISBNinput);
    
};

#endif