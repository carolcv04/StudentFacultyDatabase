#include "Student.h"

int Student::currentIDNumber = 1000;

Student::Student(){}

Student::Student(std::string name, std::string level, std::string major, int advisorID, double gpa){
    //creates a student obj with all the information
    m_name = name;
    m_level = level;
    m_major = major;
    m_gpa = gpa;
    m_advisorIDNumber = advisorID;
    if(advisorID == 0){
        m_advisorIDNumber = -1;
    }
    generateID();
}

Student::~Student(){}

void Student::generateID(){
    //generates a new everytime a new object is created
    m_IDNumber = currentIDNumber;
    ++currentIDNumber;
} 

void Student::printInfo(){
    //prints all the student information
    std::cout << "NAME: " << m_name << std::endl;
    std::cout << "LEVEL: " << m_level << std::endl;
    std::cout << "MAJOR: " << m_major << std::endl;
    if(m_advisorIDNumber == -1){
        std::cout << "ADVISOR ID: No advisor." << std::endl;
    }else{
        std::cout << "ADVISOR ID: " << m_advisorIDNumber << std::endl;
    } 
    std::cout << "GPA: " << m_gpa << std::endl;
    std::cout << "ID NUM: " << m_IDNumber << std::endl;
}

int Student::getIDNumber(){
    return m_IDNumber;
}

void Student::changeAdvisor(int newAdvisorID){
    m_advisorIDNumber = newAdvisorID;
}

int Student::getAdvisorID(){
    return m_advisorIDNumber;
}

void Student::printToFile(ofstream &output){
    //prints all the student information onto a file
    output << "NAME: " << m_name << std::endl;
    output << "LEVEL: " << m_level << std::endl;
    output << "MAJOR: " << m_major << std::endl;
    if(m_advisorIDNumber == -1){
        output << "ADVISOR ID: No advisor." << std::endl;
    }else{
        output << "ADVISOR ID: " << m_advisorIDNumber << std::endl;
    } 
    output << "GPA: " << m_gpa << std::endl;
    output << "ID NUM: " << m_IDNumber << std::endl;
}



