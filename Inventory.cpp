/* 
 * File:   Inventory.cpp
 * Author: kim
 * 
 * Created on July 23, 2014, 9:36 PM
 */
#include <sstream>

#include "Inventory.h"
#define _CRT_SECURE_NO_WARNINGS

// This function loads the book database from a file and stores all book
// information into a vector of book objects
void Inventory::loadFile() {

    ifstream inputFile;

    inputFile.open("/Users/Calvin/Desktop/CODE/C++/Bookstore/Bookstore/450booksdb.csv"); // Open file
    if (!inputFile.is_open()) // Validate if file can be opened
    {
        cout << "The file could not be opened. Program is terminating." << endl;
        exit(1);
    }

    char buffer[1024]; // Buffer to hold a field of data

    //int count = 0;
    string token;
    string title, ISBN, author, publisher, dateAdded, wholesaleCost, retailPrice, quantityOnHand;

    while (inputFile.getline(buffer, 1024)) {
        istringstream line(buffer);

        getline(line, title, ',');
        getline(line, ISBN, ',');
        getline(line, author, ',');
        getline(line, publisher, ',');
        getline(line, dateAdded, ',');
        getline(line, wholesaleCost, ',');
        getline(line, retailPrice, ',');
        getline(line, quantityOnHand, ',');

        long date = atol(dateAdded.c_str());
        float wsc = atof(wholesaleCost.c_str());
        float rp = atof(retailPrice.c_str());
        long qoh = atol(quantityOnHand.c_str());

        // Create a BookRecord object
        BookRecord book(ISBN, date, qoh, title, author, publisher, wsc, rp);
        // Push object into books vector
        books.push_back(book);
    }

}

// This function takes in ISBN input and searches for the location of the book
// in the vector
int Inventory::searchBooks(string ISBNinput) {

    int position = -1; // Position of book not found yet

    for (int index = 0; index < books.size(); index++) {
        if (books[index].ISBN == ISBNinput)
            position = index;
    };

    return position;
}

// This function searches for a book using ISBN and displays the book's 
// information if found
void Inventory::listBookInformation(string ISBNinput) {
    int searchedBook = -1;

    searchedBook = searchBooks(ISBNinput); // Search for book

    if (searchedBook < 0) {
        cout << "ERROR: Book is not found" << endl;
    } else {
        cout << books[searchedBook] << endl; // Operator overloading

    }

}

// This function searches for a book using ISBN and deletes the book if found
void Inventory::deleteBook(string ISBNinput) {
    int searchedBook = -1; // Book not found yet

    searchedBook = searchBooks(ISBNinput); // Search for book

    if (searchedBook < 0) {
        cout << "ERROR: Book is not found" << endl;
    }
    else {
        books.erase(books.begin() + searchedBook);
    }

}

// This function searches for a book using ISBN and allows the user to edit 
// the book if found
void Inventory::editBook(string ISBNinput) {
    // Variables to hold book information
    string ISBN;
    long dateAdded;
    long quantityOnHand;
    string title;
    string author;
    string publisher;
    float wholesaleCost;
    float retailPrice;

    char option;

    int searchedBook = -1; // Book not found yet
 
    searchedBook = searchBooks(ISBNinput); // Search for book

    if (searchedBook < 0) {
        cout << "ERROR: Book is not found" << endl;
    }
    else {
        cout << "You chose to edit the book with ISBN " << ISBNinput << ". The "
                "current information is displayed:" << endl;

        cout << "1. ISBN: " << books[searchedBook].ISBN << endl;
        cout << "2. Date added: " << books[searchedBook].dateAdded << endl;
        cout << "3. Quantity: " << books[searchedBook].quantityOnHand << endl;
        cout << "4. Title: " << books[searchedBook].title << endl;
        cout << "5. Author: " << books[searchedBook].author << endl;
        cout << "6. Publisher: " << books[searchedBook].publisher << endl;
        cout << "7. Wholesale cost: " << books[searchedBook].wholesaleCost << endl;
        cout << "8. Retail price: " << books[searchedBook].retailPrice << endl;

        do {
            // Get user choice for mode of editing
            cout << "Enter the number you would like to edit or press 0 to exit: " << endl;
            cin >> option;
            
            // Switches for options
            switch (option) {
                case('1'):
                    cout << "Modify The ISBN to: " << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> ISBN;
                    books[searchedBook].ISBN = ISBN;
                    cout << "You have modified the ISBN to " << books[searchedBook].ISBN << "." << endl;
                    break;
                case ('2'):
                    cout << "Modify the date added to:" << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> dateAdded;
                    books[searchedBook].dateAdded = dateAdded;
                    cout << "You have modified the date added to " << books[searchedBook].dateAdded << "." << endl;
                    break;
                case('3'):
                    cout << "Modify quantity on hand to: " << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> quantityOnHand;
                    books[searchedBook].quantityOnHand = quantityOnHand;
                    cout << "You have modified the quantity on hand to: " << books[searchedBook].quantityOnHand << "." << endl;
                    break;
                case('4'):
                    cout << "Modify the title to: " << endl;
                    cin.clear();
                    cin.ignore();
                    getline(cin, title);
                    //                    cin >> title;
                    books[searchedBook].title = title;
                    cout << "You have modified the title to " << books[searchedBook].title << "." << endl;
                    break;
                case('5'):
                    cout << "Modify the author to: " << endl;
                    cin.clear();
                    cin.ignore();
                    getline(cin, author);
                    //                    cin >> author;
                    books[searchedBook].author = author;
                    cout << "You have modified the author to " << books[searchedBook].author << "." << endl;
                    break;
                case('6'):
                    cout << "Modify the publisher to: " << endl;
                    cin.clear();
                    cin.ignore();
                    getline(cin, publisher);
//                    cin >> publisher;
                    books[searchedBook].publisher = publisher;
                    cout << "You have modified the publisher to " << books[searchedBook].publisher << "." << endl;
                    break;
                case('7'):
                    cout << "Modifty the wholesale cost to: " << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> wholesaleCost;
                    books[searchedBook].wholesaleCost = wholesaleCost;
                    cout << "You have modified the wholesale cost to " << books[searchedBook].wholesaleCost << "." << endl;
                    break;
                case('8'):
                    cout << "Modify the retail price to: " << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> retailPrice;
                    books[searchedBook].retailPrice = retailPrice;
                    cout << "You have modified the retail price to " << books[searchedBook].retailPrice << "." << endl;
                    break;
            } // switch

        } while (option != '0'); // do-while
    } // else
}

// This function checks to see if a book already exists in the database
// before adding it
bool Inventory::checkISBN(string ISBNinput) {
    int searchedBook = -1; // Book not found yet

    searchedBook = searchBooks(ISBNinput); // Search for book

    if (searchedBook < 0) return false; // Book doesn't exit, continue to add book
    else 
    {
        cout << "Book already exists. Quantity increased by one." << endl;
        ++books[searchedBook]; // Overloading ++ operator
    } return true;

}

void Inventory::addBook() {
    string ISBN;
    string title;
    string author;
    string publisher;
    long date;
    float wsc;
    float rp;
    long qoh;

    // Get information of new book
    cout << "Enter ISBN: " << endl;
    cin >> ISBN;
    if (checkISBN(ISBN)) return; // Return if book already exists
    cout << "Enter date added: " << endl;
    cin >> date;
    cout << "Enter quantity on hand: " << endl;
    cin >> qoh;
    cout << "Enter title: " << endl;
    cin.clear();
    cin.ignore();
    getline(cin, title);
    cout << "Enter author: " << endl;
    getline(cin, author);
    cout << "Enter publisher: " << endl;
    getline(cin, publisher);
    cout << "Enter wholesale cost: " << endl;
    cin.clear();
    cin >> wsc;
    cout << "Enter retail price: " << endl;
    cin >> rp;

    // Create a new object book of BookRecord structure
    BookRecord book(ISBN, date, qoh, title, author, publisher, wsc, rp);
    // Store the new book object into vector of book objects
    books.push_back(book);
}


// This function dumps book database stored in the vectors into an updated file
void Inventory::dumpFile() {
    ofstream outputFile;
    int count = 0;

    outputFile.open("updatedDatabase.txt"); // Open file
    if (!outputFile.is_open()) // Validate if file can be opened
    {
        cout << "The file could not be opened. Program is terminating." << endl;
        exit(1);
    }

    for (int i = 0; i < books.size(); i++) {
        outputFile << books[i].ISBN << endl;
        outputFile << books[i].dateAdded << endl;
        outputFile << books[i].quantityOnHand << endl;
        outputFile << books[i].title << endl;
        outputFile << books[i].author << endl;
        outputFile << books[i].publisher << endl;
        outputFile << books[i].wholesaleCost << endl;
        outputFile << books[i].retailPrice << endl;
        count++;
    }

    cout << count << " books have been dumped into the file." << endl;

    outputFile.close(); // Close file

}



