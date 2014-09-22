/* 
 * File:   BookRecord.h
 * Author: kim
 *
 * Created on July 27, 2014, 4:55 PM
 */

#ifndef BOOKRECORD_H
#define	BOOKRECORD_H
#include <string>
#include <iostream>

using namespace std;

class BookRecord 
{
public:
    string ISBN;
    long dateAdded;
    long quantityOnHand;
    string title;
    string author;
    string publisher;
    float wholesaleCost;
    float retailPrice;
    void printBook();
    
    // For friends and operator overloading
    // Friends allowed to access private member variables
    friend ostream& operator<<(ostream&, const BookRecord& );
    friend bool operator--(BookRecord& );
    friend bool operator++(BookRecord& );

public:
    BookRecord(){}
    BookRecord (string ISBN_, long dateAdded_, long quantityOnHand_, 
            string title_, string author_, string publisher_,
            float wholesaleCost_, float retailPrice_)
    { 
        ISBN = ISBN_;
        dateAdded = dateAdded_;
        quantityOnHand = quantityOnHand_;
        title = title_;
        author = author_;
        publisher = publisher_;
        wholesaleCost = wholesaleCost_;
        retailPrice = retailPrice_;
    }
    
    
   
};

#endif	/* BOOKRECORD_H */

