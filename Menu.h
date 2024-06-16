#ifndef MENU_H
#define MENU_H


#include "SimpleDatabase.h"
#include <iostream>
#include <fstream>

class Menu{
    public:
        Menu();
        ~Menu();
        void showMenu(SimpleDatabase* simpleDatabase);
        void outputFile();
        void printMenu();

    private:
        std::string option;
        SimpleDatabase *database;
};

#endif