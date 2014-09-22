/* 
 * File:   BaseMenu.cpp
 * Author: kim
 * 
 * Created on July 30, 2014, 10:44 PM
 */

#include "BaseMenu.h"
#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS


// Virtual function
void BaseMenu::printMenu()
{
    cout << "********************************************" << endl;
    cout << "*             Group 3's Bookstore          *" << endl;
    cout << "********************************************" << endl;
}

void BaseMenu::displayOptions(){
    
    cout << "Main Menu"<<endl;
    cout << "1. Cashier Module" << endl;
    cout << "2. Inventory Database Module" << endl;
    cout << "3. Report Module" << endl;
    cout << "4. Exit" << endl;
    cout << "\nEnter your choice: ";
}
