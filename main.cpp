//
//  main.cpp
//  Bookstore
//
//  Created by Calvin Yin on 7/16/14.
//  Copyright (c) 2014 Calvin Yin. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
//#include <unistd.h>
//#include <term.h>
#include <ctime>

#include "Cashier.h"
#include "Inventory.h"
#include "Report.h"

#include "BaseMenu.h"
#include "ReportMenu.h"
#include "InventoryMenu.h"
#include "CashierMenu.h"

#define _CRT_SECURE_NO_WARNINGS



using namespace std;


// Operator overloading, overloading '<<' to display all members of the book object
ostream& operator <<(ostream& pout, const BookRecord& book)
{
    pout << "ISBN: " << book.ISBN << endl;
    pout << "Title: " << book.title << endl;
    pout << "Author: " << book.author << endl;
    pout << "Publisher: " << book.publisher << endl;
    pout << "Wholesale cost: " << book.wholesaleCost << endl;
    pout << "Retail price: " << book.retailPrice << endl;
    pout << "Quantity on hand: " << book.quantityOnHand << endl;
    pout << "Date Added: " << book.dateAdded << endl;
    return pout;
    
}

// Operator overloading, overloading '++' to decrement quantityOnHand
bool operator ++(BookRecord& books)
{
   books.quantityOnHand += 1;
    return NULL;
}


void Clear_Screen();
void Display_Main();
void Display_Inv();
void Display_Cash();
void Display_Rep();
void Book_Info();

Inventory Invent; // Create inventory

int main(){
    Invent.loadFile();

    Display_Main();
    return 0;
}

//******************************************************
// FUNC     :DISPLAY MAIN MENU (COMPLETE)
//******************************************************

void Display_Main(){
z:
    Clear_Screen();
    BaseMenu *baseMenuPtr;
    BaseMenu menu;
    baseMenuPtr = &menu;
    baseMenuPtr->printMenu();
    baseMenuPtr->displayOptions();
    cout << endl;
    int choice;
    cin >> choice;
    switch(choice){
            
        //**************************************************
        // Case 1   :Cashier Module
        //**************************************************
        case 1:{
            Clear_Screen();
            Display_Cash();
            cout << "Do you want to continue (y/n)?: ";
            char ans;
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
                goto z;
            else
                goto end;
        }
        
        //**************************************************
        // Case 2   :Inventory Database Module
        //**************************************************
        case 2:{
            Clear_Screen();
            Display_Inv();
            cout << "Do you want to continue (y/n)?: ";
            char ans;
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
                goto z;
            else
                goto end;
        }
            
        //**************************************************
        // Case 3   :Report Module
        //**************************************************
        case 3:{
            Clear_Screen();
            Display_Rep();
            cout << "Do you want to continue (y/n)?: ";
            char ans;
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
                goto z;
            else
                goto end;
        }
            
        //**************************************************
        // Case 4   :Exit
        //**************************************************
        case 4:{
        end:
            Clear_Screen();
            cout << "Thank you for visiting.\n";
            exit(0);
        }
            
            
    }
    
}


//******************************************************
// FUNC     :INVENTORY MENU SCREEN (COMPLETE)
//******************************************************

void Display_Inv(){
z:
    Clear_Screen();
    BaseMenu *baseMenuPtr;
    InventoryMenu invMenu;
    baseMenuPtr = &invMenu;
    baseMenuPtr->printMenu();
    cout << "\nEnter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        //**************************************************
        // Case 1   :Look Up Book
        //**************************************************
        case 1:{
            Clear_Screen();
            string ISBNTemp;
            cout << "Enter the ISBN for the Book: ";
            cin >> ISBNTemp;
            //int temp = Invent.searchBooks(ISBNTemp);
            Invent.listBookInformation(ISBNTemp);
            cout << "Do you want to continue (y/n)?: ";
            char ans;
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
                goto z;
            else
                goto end;
        }
        //**************************************************
        // Case 2   :Add a Book
        //**************************************************
        case 2:{
            Clear_Screen();
            Invent.addBook();
            cout << "Do you want to continue (y/n)?: ";
            char ans;
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
                goto z;
            else
                goto end;
        }
        //**************************************************
        // Case 3   :Edit a Book's Record
        //**************************************************
        case 3:{
            Clear_Screen();
            string ISBNTemp;
            cout << "Enter the ISBN for the Book: ";
            cin >> ISBNTemp;
            Invent.editBook(ISBNTemp);
            cout << "Do you want to continue (y/n)?: ";
            char ans;
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
                goto z;
            else
                goto end;
        }
        //**************************************************
        // Case 4   :Delete Book
        //**************************************************
        case 4:{
            Clear_Screen();
            string ISBNTemp;
            cout << "Enter the ISBN for the Book: ";
            cin >> ISBNTemp;
            Invent.deleteBook(ISBNTemp);
            cout << "Do you want to continue (y/n)?: ";
            char ans;
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
                goto z;
            else
                goto end;
        }
        //**************************************************
        // Case 5   :Update Database
        //**************************************************
        case 5:{
            Clear_Screen();
            cout << "You have updated the database." << endl;
            Invent.dumpFile();
            cout << "Do you want to continue (y/n)?: ";
            char ans;
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
                goto z;
            else
                goto end;
        }
        //**************************************************
        // Case 6   :Exit
        //**************************************************
        case 6:{
        end:
            Clear_Screen();
            Display_Main();
        }
            
    }
}
//******************************************************
// FUNC     :CASHIER SCREEN (INCOMPLETE)
//******************************************************
void Display_Cash(){
    vector<BookRecord>& rep = Invent.getBooks();
    Cashier BookStoreCashier(rep);
z:
    Clear_Screen();
    BaseMenu *baseMenuPtr;
    CashierMenu cashMenu;
    baseMenuPtr = &cashMenu;
    baseMenuPtr->printMenu();
    cout << "\nEnter your choice: ";
    int choice;
    cin >> choice;
    cout << endl;
    switch (choice) {
        case 3:{
            Clear_Screen();
            string ISBNTemp;
            cout << "Enter the ISBN for the Book: ";
            cin >> ISBNTemp;
            BookStoreCashier.lookupBook(ISBNTemp);
            cout << "Do you want to continue (y/n)?: ";
            char ans;
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
                goto z;
            else
                goto end;
        }
        case 2:{
            Clear_Screen();
            string ISBNTemp;
            cout << "Enter the ISBN for the Book: ";
            cin >> ISBNTemp;
            BookStoreCashier.returnBook(ISBNTemp);
            cout << "Do you want to continue (y/n)?: ";
            char ans;
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
                goto z;
            else
                goto end;
        }
        case 1:{
            const double Sales_Tax = 0.10;
            vector<BookRecord>& rep = Invent.getBooks();
            Cashier BookStoreCashier(rep);
            int counter = 0;
            vector<string> bookISBN;
            vector<double> bookQuantity;
            vector<double> subTotals;
            bool morebook = true;
            while (morebook){
                string x;
                long y;
                cout << "Enter ISBN of purchased book" << endl;
                cin >> x;
                cout << "Enter Quantity of books purchased" << endl;
                cin >> y;
                bookISBN.push_back(x); // Vector of book ISBNs
                bookQuantity.push_back(y); // Vector of book quantities 
                cout << "Do you have more books (y/n)?: ";
                char ans;
                cin >> ans;
                if (ans == 'y' || ans == 'Y'){
                    counter++;
                }else{
                    morebook = false;
                }
            }
            for (int i = 0; i < bookISBN.size(); i++){
                long j = BookStoreCashier.searchBooks(bookISBN[i]); // Search if ISBNS exist
                if (j < 0){
                    cout<<"ERROR: BOOK NOT FOUND"<<endl;
                    return;
                }
                long k = rep[j].quantityOnHand;
                // Check to see if quantity on hand is less than quantity requested 
                if (k<bookQuantity[i]){
                    cout << "Not Enough "<<rep[j].title<<" in Store, only "<< k << endl;
                    bookQuantity[i] = k;
                    rep[j].quantityOnHand = 0;
                }else{
                    cout << "Quanity decrease by "<<bookQuantity[i]<<" Current amount: "<<rep[j].quantityOnHand<<endl;
                    for(int i =0; i< bookQuantity[i]; i++)
                    rep[j].quantityOnHand -=  bookQuantity[i];
                }
            }
            for (int i = 0; i < bookISBN.size(); i++){
                long j = BookStoreCashier.searchBooks(bookISBN[i]);
                subTotals.push_back(rep[j].retailPrice * bookQuantity[i]);
            }
            
            Clear_Screen();
            cout << "Group 3's Bookstore" << endl<<endl;
            time_t t = time(0);
            struct tm * now = localtime( & t );
            cout << "Date: "<<(now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-'<<  now->tm_mday<< endl<<endl<<endl;
            cout <<setw(10) <<left << "QTY" <<setw(20) <<left << "ISBN" <<setw(30)  <<"Title"<<setw(20)<<left<<"Price($)"<<setw(10)<<left<<"Total($)"<<endl;
            cout<<"-----------------------------------------------------------------------------------------------"<<endl;
            double finalTotal_preTax = 0;
            for (int i = 0; i <bookISBN.size();i++){
                string title;
                for (int j = 0; j < rep.size(); j++){
                    int x = BookStoreCashier.searchBooks(bookISBN[i]);
                    title = rep[x].title;
                }
                cout <<setw(10) <<left << bookQuantity[i] <<setw(20) <<left << bookISBN[i];
                    if (title.size()>30){
                        cout << setw(30) << left << string(title.begin(),title.begin()+25);
                    }
                    else{
                        cout << setw(30) << left << title;
                    }

                cout<<setw(20)<<left<<setprecision(2)<<fixed<<subTotals[i]<<setw(10)<<left<<subTotals[i]*Sales_Tax+subTotals[i]<<endl;
                finalTotal_preTax += subTotals[i];
            }
            
            cout << endl<<endl;
            cout <<setprecision(2);
            cout << setw(30) <<right<<fixed<<setprecision(2)<<"SubTotal: $"<< finalTotal_preTax<<endl;
            cout << setw(30) <<right<<fixed<<setprecision(2)<<"Tax: $"<<finalTotal_preTax*Sales_Tax<<endl;
            cout << setw(30) <<right<<setprecision(2)<<fixed<<"Total: $"<< finalTotal_preTax+finalTotal_preTax*Sales_Tax;
            cout<<endl;
            cout << "Do you want to continue (y/n)?: ";
            char ans;
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
                goto z;
            else{
                bookISBN.clear();
                bookQuantity.clear();
                subTotals.clear();
                goto end;
            }
        }
        case 4:{
        end:
            Clear_Screen();
            Display_Main();
        }
    }
}

//******************************************************
// FUNC     :REPORT MENU SCREEN (COMPLETE)
//******************************************************
void Display_Rep(){
z:
    vector<BookRecord> Rep = Invent.getBooks();
    Report BookstoreReport(Rep);
    Clear_Screen();
    BaseMenu* baseMenuPtr;
    ReportMenu repMenu;
    baseMenuPtr = &repMenu;
    baseMenuPtr->printMenu();
    cout << endl;
    cout << "\nEnter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:{
            Clear_Screen();
            BookstoreReport.reportInventoryList();
            cout << "Do you want to continue (y/n)?: ";
            char ans;
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
                goto z;
            else
                goto end;
        }
        case 2:{
            Clear_Screen();
            BookstoreReport.reportWholesale();
            cout << "Do you want to continue (y/n)?: ";
            char ans;
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
                goto z;
            else
                goto end;
        }
        case 3:{
            Clear_Screen();
            BookstoreReport.reportRetail();
            cout << "Do you want to continue (y/n)?: ";
            char ans;
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
                goto z;
            else
                goto end;
        }
        case 4:{
            Clear_Screen();
            BookstoreReport.reportQuantity();
            cout << "Do you want to continue (y/n)?: ";
            char ans;
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
                goto z;
            else
                goto end;
        }
        case 5:{
            Clear_Screen();
            BookstoreReport.reportCost();
            cout << "Do you want to continue (y/n)?: ";
            char ans;
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
                goto z;
            else
                goto end;
        }
        case 6:{
            Clear_Screen();
            BookstoreReport.reportAge();
            cout << "Do you want to continue (y/n)?: ";
            char ans;
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
                goto z;
            else
                goto end;
        }
        case 7:{
        end:
            Rep.clear();
            Clear_Screen();
            Display_Main();
        }
            
    }
}

//******************************************************
// FUNC     :CLEAR SCREEN (COMPLETE)
//******************************************************

void Clear_Screen(){
    for (int i = 0; i<10; i++){
        cout<<"\n\n\n\n\n\n\n\n\n";
    }
}


