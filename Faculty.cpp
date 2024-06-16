#include "Faculty.h"

int Faculty::currentIDNumber = 1000;

Faculty::Faculty(){};

Faculty::Faculty(std::string name, std::string level, std::string department){ 
    //create a new faculty object
    generateID();
    m_name = name;
    m_level = level;
    m_department = department;
}

Faculty::~Faculty(){}

void Faculty::generateID(){
    //generates an ID number for  the faculty object
    m_IDNumber = currentIDNumber;
    ++currentIDNumber;
} 

void Faculty::printInfo(){
    //prints all the faculty information
    std::cout << "NAME: " << m_name << std::endl;
    std::cout << "LEVEL: " << m_level << std::endl;
    std::cout << "MAJOR: " << m_department << std::endl;
    std::cout << "ID NUM: " << m_IDNumber << std::endl;
    std::cout << "STUDENT ADVISEE: ";
    //if the list is empty, the faculty has no advisee
    if(adviseeIDNumbers.isEmpty()){
        std::cout << "No student advisee." << std::endl;
        return;
    }
    adviseeIDNumbers.printList(true);
    std::cout << std::endl;
}

int Faculty::getIDNumber(){
    return m_IDNumber;
}

void Faculty::addAdvisee(int studentID){

    //adds an advisee to the list of advisee's 
    if (adviseeIDNumbers.find(studentID) != -1) {
        std::cout << "Student " << studentID << " is already an advisee." << std::endl;
        return;
    }
    adviseeIDNumbers.insertBack(studentID);
}

bool Faculty::removeAdvisee(int studentID){
    //checks to see if the student is an advisee
    int IDToRemove = adviseeIDNumbers.find(studentID);

    if(IDToRemove == -1) {
        return false;
    }
    //if so, its removed from the list
    adviseeIDNumbers.removeNode(studentID);
    return true;
}

void Faculty::printToFile(ofstream &output){
    //prints all the faculty info to a file
    output << "NAME: " << m_name << std::endl;
    output << "LEVEL: " << m_level << std::endl;
    output << "MAJOR: " << m_department << std::endl;
    output << "ID NUM: " << m_IDNumber << std::endl;
}