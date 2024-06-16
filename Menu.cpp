#include "Menu.h"

Menu::Menu(){

}
Menu::~Menu(){

}

void Menu::showMenu(SimpleDatabase* simpleDatabase){
    int userInput;
    std::string name;
    std::string level;
    std::string major;
    int facultyID;
    int studentID;
    double gpa;
    std::string idAdvisor;

    //while the user does not want to exit, loop continues
    while(userInput != 11){
        printMenu();

        std::cout << "Select a number 1 - 11 (EXIT): ";

        //checks to see if the input corresponds to the right type
        if (!(std::cin >> userInput)) {
            // Clear input stream
            std::cin.clear();
            // Discard invalid input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue; // Continue to the next iteration of the loop
        }

        
        switch(userInput){
            case 1:
                simpleDatabase->printAllStudents();
                break;
            case 2:
                simpleDatabase->printAllFaculty();
                break;
            case 3:
                std::cout << "Student ID Number, must be 4 digits (0000): ";

                //checks to see if the input corresponds to the right type
                if (!(std::cin >> userInput)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number." << std::endl;

                }else{
                    simpleDatabase->searchStudent(userInput);
                }
                break;
            
            case 4:
                std::cout << "Faculty ID Number, must be 4 digits (0000): ";
                //checks to see if the input corresponds to the right type
                if(!(std::cin >> userInput)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number." << std::endl;
                }else{
                    std::cout << std::endl;
                    simpleDatabase->searchFaculty(userInput);
                }
                break;

            case 5:
                std::cout << "Student name: ";
                //checks to see if the input corresponds to the right type
                if (!(std::cin >> name)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input." << std::endl;
                    break;
                }
                std::cout << std::endl;

                std::cout << "Student level (Freshman, Sophmore, Junior, Senior): ";
                //checks to see if the input corresponds to the right type
                if (!(std::cin >> level)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number." << std::endl;

                }
                std::cout << std::endl;

                std::cout << "Student major: ";
                //checks to see if the input corresponds to the right type
                if (!(std::cin >> major)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number." << std::endl;
                }
                std::cout << std::endl;

                std::cout << "Student GPA: ";
                //checks to see if the input corresponds to the right type
                if (!(std::cin >> gpa)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number." << std::endl;
                }
                std::cout << std::endl;

                simpleDatabase->insertStudent(new Student(name, level, major, 0, gpa));
                break;
            case 6:
                std::cout << "Student ID Number, must be 4 digits (0000): ";
                //checks to see if the input corresponds to the right type
                if(!(std::cin >> userInput)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number." << std::endl;
                }else{
                    simpleDatabase->deleteStudent(userInput);
                }
                break;
            case 7:
                std::cout << "Faculty name: ";
                //checks to see if the input corresponds to the right type
                if (!(std::cin >> name)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input." << std::endl;
                    break;
                }
                std::cout << std::endl;

                std::cout << "Faculty level (Professor, Associate Professor, Assistant Professor, Dean): ";
                //checks to see if the input corresponds to the right type
                if (!(std::cin >> level)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number." << std::endl;

                }
                std::cout << std::endl;

                std::cout << "Faculty department: ";
                //checks to see if the input corresponds to the right type
                if (!(std::cin >> major)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number." << std::endl;
                }
                std::cout << std::endl;

                simpleDatabase->insertFaculty(new Faculty(name, level, major));
                break;
            case 8:
                std::cout << "Faculty ID Number, must be 4 digits (0000): ";
                //checks to see if the input corresponds to the right type
                if(!(std::cin >> userInput)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number." << std::endl;
                }else{
                    simpleDatabase->deleteFaculty(userInput);
                }
                break;
            case 9:
                std::cout << "Faculty ID Number, must be 4 digits (0000): ";
                //checks to see if the input corresponds to the right type
                if(!(std::cin >> facultyID)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number." << std::endl;
                    break;
                }

                if(!simpleDatabase->findFaculty(facultyID)){
                    std::cout << "Could not find Faculty." << std::endl;
                    break;
                }

                std::cout << "Student ID Number, must be 4 digits (0000): ";
                //checks to see if the input corresponds to the right type
                if(!(std::cin >> studentID)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number." << std::endl;
                    break;
                }

                if(!simpleDatabase->findStudent(studentID)){
                    std::cout << "Could not find Student." << std::endl;
                    break;
                }

                simpleDatabase->changeStudentAdvisor(studentID, facultyID);
                break;
            case 10:
                std::cout << "Faculty ID Number, must be 4 digits (0000): ";
                //checks to see if the input corresponds to the right type
                if(!(std::cin >> facultyID)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number." << std::endl;
                    break;
                }

                if(!simpleDatabase->findFaculty(facultyID)){
                    std::cout << "Could not find Faculty." << std::endl;
                    break;
                }


                std::cout << "Student ID Number, must be 4 digits (0000): ";
                //checks to see if the input corresponds to the right type
                if(!(std::cin >> studentID)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number." << std::endl;
                    break;
                }

                if(!simpleDatabase->findStudent(studentID)){
                    std::cout << "Could not find Student." << std::endl;
                    break;
                }

                simpleDatabase->removeAdvisee(studentID, facultyID);
                break;
            case 11:
                break;

            default: 
                std::cout << "Invalid input, try again." << std::endl;
        }
    }
    //outputs all the student & faculty info onto a file "runLog.txt"
    ofstream outputFile;
    outputFile.open("runLog.txt");
    simpleDatabase->printToFile(outputFile);
    outputFile.close();
}

void Menu::printMenu(){

    //MENU!! :3
    std::cout << std::endl;
    std::cout << "===================================== MENU =======================================" << std::endl;
    std::cout << "1. Print all students and their information (sorted by ascending id #." << std::endl;
    std::cout << "2. Print all faculty and their information (sorted by ascending id #." << std::endl;
    std::cout << "3. Find and display student information given the student id." << std::endl;
    std::cout << "4. Find and display faculty information given the faculty id." << std::endl;
    std::cout << "5. Add a new student." << std::endl;
    std::cout << "6. Delete a student given the id." << std::endl;
    std::cout << "7. Add a new faculty member." << std::endl;
    std::cout << "8. Delete a faculty member given the id." << std::endl;
    std::cout << "9. Change a student’s advisor given the student id and the new faculty id." << std::endl;
    std::cout << "10. Remove an advisee from a faculty member given the ids." << std::endl;
    std::cout << "11. Exit." << std::endl;
    std::cout << "================================================================================" << std::endl;
    std::cout << std::endl;
}
