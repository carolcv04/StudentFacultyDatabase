#ifndef SIMPLEDATABASE_H
#define SIMPLEDATABASE_H
#include "Student.h"
#include "Faculty.h"
#include "LazyBST.h"

#include <iostream>

class SimpleDatabase {
    public:
        SimpleDatabase();
        ~SimpleDatabase();

        //print functions
        void printAllStudents();
        void printAllFaculty();
        void print();
        void printToFile(ofstream &output);

        //search functions
        void searchStudent(int studentID);
        void searchFaculty(int facultyID);

        //to find functions
        bool findStudent(int studentID);
        bool findFaculty(int facultyID);

        //to insert functions
        void insertStudent(Student* student);
        void insertFaculty(Faculty* faculty);

        //delete fuctions
        void deleteStudent(int studentID);
        void deleteFaculty(int facultyID);

        //remove or add an advisee
        void changeStudentAdvisor(int studentIDNumber, int facultyIDNumber);
        bool removeAdvisee(int studentID, int facultyID);
    private:
        LazyBST<int, Student> *students;
        LazyBST<int, Faculty> *faculty;

};

#endif