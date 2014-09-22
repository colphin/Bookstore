/* 
 * File:   InventoryMenu.cpp
 * Author: kim
 * 
 * Created on July 30, 2014, 10:45 PM
 */

#include "InventoryMenu.h"
#define _CRT_SECURE_NO_WARNINGS

// Virtual function
void InventoryMenu::printMenu()
{
//    clearScreen();
    BaseMenu::printMenu();
    cout << "Inventory Database"<<endl;
    cout << "1. Look Up a Book" << endl;
    cout << "2. Add a Book" << endl;
    cout << "3. Edit a Book's Record" << endl;
    cout << "4. Delete a Book" << endl;
    cout << "5. Update database" << endl;
    cout << "6. Return to Main Menu"<< endl;
   
}