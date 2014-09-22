/* 
 * File:   InventoryMenu.h
 * Author: kim
 *
 * Created on July 30, 2014, 10:45 PM
 */

#ifndef INVENTORYMENU_H
#define	INVENTORYMENU_H
#include "BaseMenu.h"

class InventoryMenu:public BaseMenu 
{
private:
public:

    // Virtual function
    virtual void printMenu(); // Will be used to demonstrate dynamic binding
    


};

#endif	/* INVENTORYMENU_H */
