/* 
 * File:   Report.h
 * Author: kim
 *
 * Created on July 27, 2014, 5:31 PM
 */

#ifndef REPORT_H
#define	REPORT_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm> // Needed for sort function

#include "BookRecord.h"

using namespace std;

class Report:public BookRecord
{
private:
vector<BookRecord> booksForReport;

public:
    
    // Constructor, take in book database from inventory class by reference
    // and store it into another vector for report
    Report(vector<BookRecord> b): booksForReport(b){}
    // Report functions
    void reportInventoryList();
    void reportWholesale(); 
    void reportRetail();
    void reportQuantity();
    void reportCost();
    void reportAge();

};

#endif	/* REPORT_H */

