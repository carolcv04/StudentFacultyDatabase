#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>

using namespace std;

class Student {
    public:
        Student();
        Student(std::string name, std::string level, std::string major, int advisorID, double gpa);
        ~Student();
        void generateID();
        void printInfo();
        void printToFile(ofstream &output);
        int getIDNumber();
        int getAdvisorID();
        void changeAdvisor(int newAdvisorID);

    private:
        static int currentIDNumber;
        int m_IDNumber;
        std::string m_name;
        std::string m_level;
        std::string m_major;
        double m_gpa;
        int m_advisorIDNumber;
};

#endif