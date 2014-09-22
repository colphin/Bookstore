/* 
 * File:   BookRecord.cpp
 * Author: kim
 * 
 * Created on July 27, 2014, 4:55 PM
 */

#include "BookRecord.h"
#define _CRT_SECURE_NO_WARNINGS

void BookRecord::printBook() {
    cout << "isbn: " << ISBN << endl;
    cout << "title: " << title << endl;
    cout << "author: " << author << endl;
    cout << "publisher: " << publisher << endl;
    cout << "wholesalecost: " << wholesaleCost << endl;
    cout << "retailprice: " << retailPrice << endl;
    cout << "quantityonhand: " << quantityOnHand << endl;
    cout << "date: " << dateAdded << endl;




}



