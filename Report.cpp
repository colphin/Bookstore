/* 
 * File:   Report.cpp
 * Author: kim
 * 
 * Created on July 27, 2014, 5:31 PM
 */

#include "Report.h"
#define _CRT_SECURE_NO_WARNINGS

void Report::reportInventoryList() {
    cout << setw(60) << left << "Title"
            << setw(30) << left << "ISBN"
            << setw(30) << left << "Quantity" << endl;
    cout << "--------------------------------------------------------------"
            "--------------------------------------------------" << endl;

    for (int i = 0; i < booksForReport.size(); i++) {
        if (booksForReport[i].title.size()>60){
            cout << setw(60) << left << string(booksForReport[i].title.begin(),booksForReport[i].title.begin()+59);
        }
        else{
            cout << setw(60) << left << booksForReport[i].title;
        }
        cout<< setw(30) << left << booksForReport[i].ISBN
                << setw(30) << left << booksForReport[i].quantityOnHand << endl;
        cout << endl;
    };

}

void Report::reportWholesale() {
    cout << setw(60) << left << "Title"
            << setw(30) << left << "ISBN"
            << setw(10) << left << "Quantity"
            << setw(10) << left << "Wholesale Cost" << endl;
    cout << "--------------------------------------------------------------"
            "--------------------------------------------------------------" << endl;

    for (int i = 0; i < booksForReport.size(); i++) {
        if (booksForReport[i].title.size()>60){
            cout << setw(60) << left << string(booksForReport[i].title.begin(),booksForReport[i].title.begin()+59);
        }
        else{
            cout << setw(60) << left << booksForReport[i].title;
        }
            cout<< setw(30) << left << booksForReport[i].ISBN
                << setw(10) << left << booksForReport[i].quantityOnHand
                << setw(10) << left << booksForReport[i].wholesaleCost << endl;
        cout << endl;
    };

    cout << endl;

    float totalWholesaleCost = 0;
    float wholesaleTemp;

    for (int i = 0; i < booksForReport.size(); i++) {
        wholesaleTemp = booksForReport[i].quantityOnHand * booksForReport[i].wholesaleCost;
        totalWholesaleCost += wholesaleTemp;
    }
    
    cout << "Total Wholesale Cost: $" << setprecision(2)<<fixed<<totalWholesaleCost << endl;


}


void Report::reportRetail() {
    cout << setw(60) << left << "Title"
            << setw(30) << left << "ISBN"
            << setw(10) << left << "Quantity"
            << setw(10) << left << "Retail Cost" << endl;
    cout << "--------------------------------------------------------------"
            "--------------------------------------------------------------" << endl;

    for (int i = 0; i < booksForReport.size(); i++) {
        if (booksForReport[i].title.size()>60){
            cout << setw(60) << left << string(booksForReport[i].title.begin(),booksForReport[i].title.begin()+59);
        }
        else{
            cout << setw(60) << left << booksForReport[i].title;
        }
            cout<< setw(30) << left << booksForReport[i].ISBN
                << setw(10) << left << booksForReport[i].quantityOnHand
                << setw(10) << left << booksForReport[i].retailPrice << endl;
        cout << endl;
    };

    cout << endl;

    float totalRetailCost = 0;
    float retailTemp;

    for (int i = 0; i < booksForReport.size(); i++) {
        retailTemp = booksForReport[i].quantityOnHand * booksForReport[i].retailPrice;
        totalRetailCost += retailTemp;
    }

    cout << "Total Retail Cost: $" <<setprecision(2)<<fixed<< totalRetailCost << endl;
}

// sort comparison
bool sortByQuantity(const BookRecord& left, const BookRecord& right) 
{
    return left.quantityOnHand > right.quantityOnHand;
}

void Report::reportQuantity() {
    cout << setw(60) << left << "Title"
            << setw(30) << left << "ISBN"
            << setw(10) << left << "Quantity" << endl;
    cout << "--------------------------------------------------------------"
            "--------------------------------------------------" << endl;

    // sort function from algorithm header file
    sort(booksForReport.begin(), booksForReport.end(), sortByQuantity);

    for (int i = 0; i < booksForReport.size(); i++) {
        if (booksForReport[i].title.size()>60){
            cout << setw(60) << left << string(booksForReport[i].title.begin(),booksForReport[i].title.begin()+59);
        }
        else{
            cout << setw(60) << left << booksForReport[i].title;
        }
            cout << setw(30) << left << booksForReport[i].ISBN
                << setw(10) << left << booksForReport[i].quantityOnHand << endl;
        cout << endl;
    };


}


bool sortByCost(const BookRecord& left, const BookRecord& right) 
{
    return left.wholesaleCost > right.wholesaleCost;
}

void Report::reportCost() {
    cout << setw(60) << left << "Title"
            << setw(30) << left << "ISBN"
            << setw(10) << left << "Wholesale Cost" << endl;
    cout << "--------------------------------------------------------------"
            "--------------------------------------------------" << endl;

    // sort function from algorithm header file
    sort(booksForReport.begin(), booksForReport.end(), sortByCost);
    
    for (int i = 0; i < booksForReport.size(); i++) {
        if (booksForReport[i].title.size()>60){
            cout << setw(60) << left << string(booksForReport[i].title.begin(),booksForReport[i].title.begin()+59);
        }
        else{
            cout << setw(60) << left << booksForReport[i].title;
        }
            cout << setw(30) << left << booksForReport[i].ISBN
                << setw(10) << left << setprecision(2)<<fixed<<booksForReport[i].wholesaleCost << endl;
        cout << endl;
    };   
        
   

}

// sort comparison
bool sortByAge(const BookRecord& left, const BookRecord& right) 
{
    return left.dateAdded < right.dateAdded;
}

void Report::reportAge() {
    cout << setw(60) << left << "Title"
            << setw(30) << left << "ISBN"
            << setw(10) << left << "Date Added" << endl;
    cout << "--------------------------------------------------------------"
            "--------------------------------------------------" << endl;
    
    // sort function from algorithm header file
    sort(booksForReport.begin(), booksForReport.end(), sortByAge);
    
    for (int i = 0; i < booksForReport.size(); i++) {
        if (booksForReport[i].title.size()>60){
            cout << setw(60) << left << string(booksForReport[i].title.begin(),booksForReport[i].title.begin()+59);
        }
        else{
            cout << setw(60) << left << booksForReport[i].title;
        }
            cout << setw(30) << left << booksForReport[i].ISBN
                << setw(10) << left <<
        booksForReport[i].dateAdded << endl;
        cout << endl;
    };

}