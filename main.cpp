
#include "SimpleDatabase.h"
#include "Menu.h"

int main(){

    SimpleDatabase* database = new SimpleDatabase();

    //sets all the faculty and student object values
    Faculty* faculty_one = new Faculty("Jeb", "Advisor", "Art"); //1000
    database->insertFaculty(faculty_one);
     
    Faculty* faculty_two = new Faculty("Carolina", "Professor", "Computer Science"); //1001
    database->insertFaculty(faculty_two);

    Faculty* faculty_three = new Faculty("Mama", "Advisor", "Computer Science"); //1002
    database->insertFaculty(faculty_three);

    Student* student_one = new Student("Kaye", "Sophmore", "Computer Science", 1002, 3.6); //1000
    database->insertStudent(student_one);

    Student* student_two = new Student("Mimi", "Freshman", "Computer Science", 1002, 3.0); //1001
    database->insertStudent(student_two);

    Student* student_three = new Student("Jeb Jr.", "Freshman", "Art", 1000, 3.8); //1002
    database->insertStudent(student_three);

    Student* student_four = new Student("Poopoo", "Freshman", "Computer Science", 1002, 3.5); //1003
    database->insertStudent(student_four);

    Student* student_five = new Student("Jeb", "Freshman", "Art", 1002, 2.5); //1004
    database->insertStudent(student_five);

    //prints the menu
    Menu *menu = new Menu();
    menu->showMenu(database);

    return 0;
}