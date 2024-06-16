# Student Faculty Database

#### Overview
This project implements a database system using Lazily Balanced Binary Search Trees (LB-BSTs) to manage student and faculty records at a university. The system allows operations such as insertion, deletion, and querying of records while maintaining referential integrity between related data.

#### Project Structure
- **main.cpp**: Contains the main logic for user interaction, menu display, and command execution in the database system.
- **LazyBST.h, LazyBST.cpp**: Implement the LB-BST data structure with operations including insert, delete, find, and balance.
- **Student.h, Student.cpp**: Define and implement the `Student` class for storing student records, including necessary operator overloads for comparisons.
- **Faculty.h, Faculty.cpp**: Define and implement the `Faculty` class for storing faculty records, including necessary operator overloads.
- **runLog.txt**: Output file created upon program termination, containing the information of both student and faculty tables.
- **README.md**: Readme file providing an overview of the project, instructions for compiling and running the code, and additional information.

#### How to Run
To compile and run the program:

1. **Compile**: Use g++ to compile the `main.cpp`, `LazyBST.cpp`, `Student.cpp`, and `Faculty.cpp` files.
   ```bash
   g++ main.cpp LazyBST.cpp Student.cpp Faculty.cpp -o db_system
   ```

2. **Run**: Execute the compiled program.
   ```bash
   ./db_system
   ```
   Follow the on-screen menu to interact with the database system.

#### Database System Details
- **LB-BST Implementation**: `LazyBST` class supports operations like insert, delete, find, and balance using the lazy balancing technique.
- **Student Records**: Stored in `Student` class with fields for student ID, name, level, major, GPA, and advisor ID.
- **Faculty Records**: Stored in `Faculty` class with fields for faculty ID, name, level, department, and list of advisee IDs.
- **Operations**: Menu-driven interface allows users to perform operations such as adding/deleting students and faculty, querying information, changing advisor assignments, and maintaining referential integrity.
- **Referential Integrity**: Commands enforce constraints such as valid advisor relationships and correct advisee assignments.

#### Requirements
- C++ compiler (tested with g++)
- Text editor or IDE (e.g., VSCode) for code editing
- Terminal or command prompt for compiling and running the executable
- Adherence to C++ standards and course coding style guidelines
- Use of primitive data structures only; no STL usage allowed.

#### Additional Notes
- The implementation strictly adheres to assignment specifications regarding LB-BST usage and database operations.
- No external libraries or non-primitive data structures are used, as per project requirements.
