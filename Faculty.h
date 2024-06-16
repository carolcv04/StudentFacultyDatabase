#ifndef FACULTY_H
#define FACULTY_H
#include "LinkedList.h"
#include "Student.h"
#include <iostream>
using namespace std;


class Faculty {
    public:
        Faculty();
        Faculty(std::string name, std::string level, std::string department);
        ~Faculty();
        void generateID();
        void printInfo();
        void printToFile(ofstream &output);
        int getIDNumber();
        void addAdvisee(int studentID);
        bool removeAdvisee(int studentID);

    private:
        LinkedList<int> adviseeIDNumbers;
        static int currentIDNumber;
        int m_IDNumber;
        std::string m_name;
        std::string m_level;
        std::string m_department;
};

#endif