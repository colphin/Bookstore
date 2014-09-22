//
//  Cashier.cpp
//  Bookstore
//
//  Created by Calvin Yin on 7/16/14.
//  Copyright (c) 2014 Calvin Yin. All rights reserved.
//

#include <iostream>
#include <iomanip>


#include "Cashier.h"
#include "Inventory.h"

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int Cashier::searchBooks(string ISBNinput) {
    
    int position = -1; // Position of book not found yet
    
    for (int index = 0; index < books.size(); index++) {
        if (books[index].ISBN == ISBNinput)
            position = index;
    };
    
    return position;
}

void Cashier::deleteBook(string ISBNinput)
{
    int searchedBook = -1;
    
    searchedBook = searchBooks(ISBNinput);
    
    try{
        if (searchedBook<0){
            string error;
            throw error;
        }
        books.erase(books.begin() + searchedBook);
    }catch(string strException){
        cout << "ERROR: Book Not Found."<<endl;
    }
}

//check for error EXCEPTION HANDLING - DONE

void Cashier::lookupBook(string ISBNinput) {
    int x = searchBooks(ISBNinput);
    try{
        if (x<0){
            string error;
            throw error;
        }
        books[x].printBook();
    }catch(string strException){
        cout << "ERROR: Book Not Found."<<endl;
    }
}

void Cashier::returnBook(string ISBNinput) {
    int x = searchBooks(ISBNinput);
    try{
        if (x<0){
            string error;
            throw error;
        }
        books[x].quantityOnHand++;
    }catch(string strException){
        cout << "ERROR: Book Not Found."<<endl;
    }
}
