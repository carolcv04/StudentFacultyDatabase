#include "SimpleDatabase.h"

SimpleDatabase::SimpleDatabase(){
    students = new LazyBST<int, Student>();
    faculty = new LazyBST<int, Faculty>();
}

SimpleDatabase::~SimpleDatabase(){}

void SimpleDatabase::printAllStudents(){
    std::cout << "ALL STUDENTS: " << std::endl;
    students->printTree();
}

void SimpleDatabase::printAllFaculty(){
    std::cout << "ALL FACULTY: " << std::endl;
    faculty->printTree();
}

void SimpleDatabase::searchStudent(int studentID){
    Student* student = students->getData(studentID);

    if(student == NULL){
        std::cout << "Student was NOT found." << std::endl;
        return;
    }
    student->printInfo();
}

void SimpleDatabase::searchFaculty(int facultyID){
    Faculty* faculty = this->faculty->getData(facultyID);

    if(faculty == NULL){
        std::cout << "Faculty was NOT found." << std::endl;
        return;
    }
    faculty->printInfo();
}

void SimpleDatabase::insertStudent(Student* student){
    students->insertNode(student->getIDNumber(), student);

    int advisorID = student->getAdvisorID();
    Faculty* faculty = this->faculty->getData(advisorID);

    if(faculty != NULL) {
        faculty->addAdvisee(student->getIDNumber());
    }
}

void SimpleDatabase::insertFaculty(Faculty* faculty){
    this->faculty->insertNode(faculty->getIDNumber(), faculty);
}

void SimpleDatabase::deleteStudent(int studentID){

    if(students->deleteNode(studentID)){
        std::cout << "Student deleted SUCESSFULLY." << std::endl;
        return;
    }
    std::cout << "Student was NOT found." << std::endl;
}

void SimpleDatabase::deleteFaculty(int facultyID){

    if(faculty->deleteNode(facultyID)){
        std::cout << "Faculty deleted SUCESSFULLY" << std::endl;
        return;
    }
    std::cout << "Faculty was NOT found" << std::endl;
}

void SimpleDatabase::changeStudentAdvisor(int studentIDNumber, int facultyIDNumber){
    Student* student = students->getData(studentIDNumber);
    if(student == NULL){
        return;
    } 
    int oldAdvisorID = student->getAdvisorID();

    //First removes the student advisee form the previous advior's list
    if(!removeAdvisee(studentIDNumber, oldAdvisorID)){
        return;
    }
    Faculty* newFaculty = this->faculty->getData(facultyIDNumber);

    if(faculty == NULL){
        return;
    }
    //then adds the student to the current advisor's list
    student->changeAdvisor(facultyIDNumber);
    newFaculty->addAdvisee(studentIDNumber);
}

bool SimpleDatabase::removeAdvisee(int studentID, int facultyID){
    Student* student = students->getData(studentID);
    Faculty* faculty = this->faculty->getData(facultyID);

    if(student == NULL){
        std::cout << "Student was NOT found" << std::endl;
        return false;
    }
    if(faculty == NULL){
        std::cout << "Faculty was NOT found" << std::endl;
        return false;
    }

    //If the student was sucessfully removed form the advisee list. 
    if(faculty->removeAdvisee(studentID)){
        student->changeAdvisor(-1);
        //std::cout << "Student was sucessfully removed." << std::endl;
        return true;
    }else{
        std::cout << "Student is NOT an advisee." << std::endl;
        return false;
    }
}

void SimpleDatabase::printToFile(ofstream &output){
    //Prints all the student & faculty info onto a file
    output << "ALL STUDENTS: " << std::endl;
    students->printTreeFile(output);

    output << std::endl;

    output << "ALL FACULTY: " << std::endl;
    faculty->printTreeFile(output);
}

bool SimpleDatabase::findStudent(int studentID){
    //checks if the student exists in the tree (database)
    if(students->contains(studentID)){
        return true;
    }
    return false;
}

bool SimpleDatabase::findFaculty(int facultyID){
    //checks if the student exists in the tree (database)
    if(faculty->contains(facultyID)){
        return true;
    }
    return false;
}


