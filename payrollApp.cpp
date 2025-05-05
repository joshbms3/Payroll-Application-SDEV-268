/*
    Student: Joshua Barroso
    Campus: IvyTech
    Course: SDEV268 Algorithms & Design Patterns
    Professor: Marlene Gordon
    Due Date: 05/11/2025
  ***************************************************************************************
]         Module 8: Course Project - Final Submission Instructions                        [
  ***************************************************************************************
  Introducing a new automated payroll system will eliminate errors in the payroll process
and ensure timely paycheck distribution. This software will be tailored to meet our
business needs and accounting workflow, ultimately saving time for our HR team. You
have been selected as our designer and developer for our new program. Your
responsibilities will involve showcasing competence in procedural and object-oriented
programming principles, exploring recursion to understand different algorithms, creating
programming, and testing software incorporating various design patterns. Please
ensure your project incorporates security measures to protect the data being gathered.
In your role as the developer, you will need to design user interfaces using JAVA,
establish the necessary databases for the application, and establish the necessary
connections between the interfaces and databases.
*/

#include <algorithm> // allows use of the .erase() and .remove() functions on line 590
#include <fstream> // allows use of the input and output operations with external fies and truncation like line 208
#include <functional> // permits access to the hash<> library for enhanced security
#include <iomanip> // currently not being used, but typically used for decimal formatting with cash formats
#include <iostream> // enables input output streams
#include <map> // allows use of the map<Type, Object> container call, which is sort of similar to a dictionary in python, see line 516
#include <sstream> //allows use of the istringstream iss() function which assists with parsing data from files
#include <string> // allows advanced operations to be done with strings and substrings such as at() and empty()
#include <vector> // allows us to make lists of various types and operations

using namespace std;

size_t my_first_stl_hash(const string& str) // my first stl hash! it also adds a little salt with the concatinated string to make passwords more difficult to predict
{
    hash<string> hasher;
    return hasher(str + "aLittleSpiceAndEverythingNice");
}

class PayrollSystem;

enum UserType { // usertype literals, used to determine access levels within the program
    UNDEFINED = -1,
    EMPLOYEE = 0,
    ADMIN = 1
};

class User { 
protected:
    size_t _passwordHashed; // size_t type is used to store long unsigned values for enhance password security in the loginData.txt file
    string _dateOfBirth;

public:
    string email;
    string userID;
    string firstName;
    string lastName;
    string surName;
    string department;
    string jobTitle;
    string dateHired;
    int status;
    int gender;
    int payType;
    UserType userType = UNDEFINED; // default value of UNDEFINED is used, in case a user is not assigned a type for any reason

    User() // default constructor for Users
        : _passwordHashed(0) // hashed pw initially set to 0
        , _dateOfBirth("")
        , status(0)
        , gender(-1)
        , payType(-1)
    {
        email = "";
        userID = "";
        firstName = "";
        lastName = "";
        surName = "";
        department = "";
        jobTitle = "";
    }

    User(
        string email, 
         string id, 
         string dob, 
         string firstName, 
         string lastName,
        string surName, 
         string dept, 
         string job, 
         int status, 
         int gender,
        int payType, 
         string hired, 
         UserType type
    )
        : email(email)
        , userID(id)
        , _dateOfBirth(dob) // _dateOfBirth is privately accessed through this parameterized constructor
        , firstName(firstName)
        , lastName(lastName)
        , surName(surName)
        , department(dept)
        , jobTitle(job)
        , status(status)
        , gender(gender)
        , payType(payType)
        , dateHired(hired)
        , userType(type)
    {
    }

    virtual ~User() { } // user class destructor

    void setPassword(const string& pass) { _passwordHashed = my_first_stl_hash(pass); }

    bool validatePassword(const string& inputPass) const // takes the pw input by the user, hashes it andcompares it to the hashed value for validation
    {
        return (my_first_stl_hash(inputPass) == _passwordHashed);
    }

    void setPasswordHash(const size_t hash) { _passwordHashed = hash; } // setPasswordHash() is called only after passing validation

    string getDateOfBirth() const { return _dateOfBirth; } // getter for private member variable _dateOfBirth

    size_t getPasswordHash() const { return _passwordHashed; } // getter for private member variable _passwordHashed
};

class Admin : public User { // class Admin inherits publicly from the previously defined User class
private:
    string getstatusString(int Status) // gets status from inherited class UserType in literal type and returns a string
    {
        switch (Status) {
        case -1:
            return "Terminated";
        case 0:
            return "Inactive";
        case 1:
            return "Active";
        default:
            return "Unknown";
        }
    }

    string getgenderString(int gender) // gets gender from inherited class UserType in literal type and returns a string
    {
        switch (gender) {
        case 0:
            return "Male";
        case 1:
            return "Female";
        case 3:
            return "Other";
        default:
            return "Unknown";
        }
    }

    string getpayTypeString(int payType) // gets payType from inherited class UserType in literal type and returns a string
    {
        switch (payType) {
        case 0:
            return "Hourly";
        case 1:
            return "Salary";
        default:
            return "Unknown";
        }
    }

public:
    Admin()
        : User() // default constructor for Admins
    {
    }

    Admin( // parameterized constructor for Admins
    
        string email, 
        string id, 
        string dob, 
        string firstName, 
        string lastName,
        string surName, 
        string dept, 
        string job, 
        int status, 
        int gender,
        int payType, 
        string hired, 
        UserType type)
    
        : User(
            email, 
            id, 
            dob, 
            firstName, 
            lastName, 
            surName, 
            dept, 
            job, 
            status, 
            gender, 
            payType, 
            hired, 
            type)
    {
    }

    void accessEmployeeDemographics(PayrollSystem* system); // pointer of the PayrollSystem type

    void searchEmployee(PayrollSystem* system); // pointer of the PayrollSystem type

    void managePayroll() // funct currently under development
    {
        cout << "Managing payroll:" << endl;
    }

    void addEditDeleteEmployee()
    {
        cout << "\nEmployee Management Options:\n";
        cout << "1 - Add New Employee\n";
        cout << "2 - Edit Existing Employee\n";
        cout << "3 - Delete Employee\n";
        cout << "4 - Return to Main Menu\n";

        int choice;
        cout << "Choose option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addNewEmployee();
            break;
        case 2:
            editEmployee();
            break;
        case 3:
            selectEmployee();
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    }

    void addNewEmployee() // the count in this function is used to allocate an appropriate number value in an employees ID
    {

        ifstream countFile("employeeData.txt");
        int employeeCount = 0; // first employee is 1001 see line 273
        int adminCount = 0; // first admin is 2001 see line 276
        string line;

        while (getline(countFile, line)) {
            if (line.find("EMPLOYEE") != string::npos) {
                employeeCount++;
            } else if (line.find("ADMIN") != string::npos) {
                adminCount++;
            }
        }
        countFile.close();

        ofstream file("employeeData.txt", ios::app);
        if (!file.is_open()) {
            cerr << "Error opening employee data file!" << endl;
            return;
        }

        if (employeeCount + adminCount > 0) {
            file << "\n";
        }

        cout << "\nEnter New Employee Details:\n";

        string email, dob, firstName, lastName, surName, dept, job, hired;
        int status, gender, payType;
        string userType;

        cout << "Email: ";
        getline(cin, email);

        string id;
        char choice;
        cout << "Is this an admin? (y/n): ";
        cin >> choice;
        cin.ignore();

        if (tolower(choice) == 'y') {
            userType = "ADMIN";
            id = "AID" + to_string(2000 + adminCount + 1);
        } else {
            userType = "EMPLOYEE";
            id = "EID" + to_string(1000 + employeeCount + 1);
        }

        cout << "Date of Birth (MM/DD/YYYY): ";
        getline(cin, dob);

        cout << "First Name: ";
        getline(cin, firstName);

        cout << "Last Name: ";
        getline(cin, lastName);

        do {
            cout << "Surname (required): "; // surname is required to reduce parsing bugs when loading data from employeeData.txt
            getline(cin, surName);
            if (surName.empty()) {
                cout << "Surname is required!\n";
            }
        } while (surName.empty());

        cout << "Department: ";
        getline(cin, dept);

        cout << "Job Title: ";
        getline(cin, job);

        do {
            cout << "Status (1 for Active, 0 for Inactive, -1 for Terminated): ";
            cin >> status;
        } while (status < -1 || status > 1);

        do {
            cout << "Gender (0 for Male, 1 for Female, 3 for Other): ";
            cin >> gender;
        } while (gender != 0 && gender != 1 && gender != 3);

        do {
            cout << "Pay Type (0 for Hourly, 1 for Salary): ";
            cin >> payType;
        } while (payType < 0 || payType > 1);

        cin.ignore();

        cout << "Date Hired (MM/DD/YYYY): ";
        getline(cin, hired);

        file << email << " " << id << " " << dob << " " << firstName << " " << lastName << " "
             << surName << " " << dept << " " << job << " " << status << " " << gender << " "
             << payType << " " << hired << " " << userType;

        file.close();

        if (id == "AID2002") {
            cout << "\nDefault admin removed because a new admin has been added!" << endl;
            deleteByEID("employeeData.txt", "AID0000");
        }

        cout << "\nEmployee added successfully!\n";
    }

    void editEmployee() // this funct is not yet complete
    {
        string employeeID;
        string line;
        vector<string> lines; // a list of "lines" is usesd to store each users information for edting
        string email, id, dob, fireName, lastName, surName, dept, job, hired, typeStr;
        int status, gender, payType;

        cout << "Enter the employee ID to edit: ";
    }

    void selectEmployee() // sends the chosen EID to the deleteByEID funct for deletion
    {
        cout << "Enter Employee by EID to delete: ";

        string employeeID;
        cin >> employeeID;

        cin.ignore();

        cout << "You have selected " << employeeID << ", are you sure? (y/n): ";
        char choice;
        cin >> choice;

        cin.ignore();

        if (choice == 'y') {
            cout << "Deleting employee..." << endl;
            deleteByEID("employeeData.txt", employeeID);
        } else {
            cout << "Returning to previous menu!" << endl;
            return;
        }
    }

    bool deleteByEID(const string& filename, const string& eid) // accesses the file directyl using the filename and eid parameter, bool is used to return operation success or not
    {
        int lineToDelete = searchByEID(filename, eid);
        if (lineToDelete == -1) {
            cout << "Employee with EID " << eid << " not found." << endl;
            return false;
        }

        ifstream inFile(filename);
        ofstream tempFile("temp_employeeData.txt");

        if (!inFile.is_open() || !tempFile.is_open()) {
            cerr << "Error: Could not open files for deletion." << endl;
            return false;
        }

        string line;
        int currentLine = 0;
        while (getline(inFile, line)) {
            if (currentLine != lineToDelete) {
                tempFile << line << endl;
            }
            currentLine++;
        }

        inFile.close();
        tempFile.close();

        remove(filename.c_str());
        rename("temp_employeeData.txt", filename.c_str());

        cout << "Employee with EID " << eid << " deleted successfully." << endl;
        return true;
    }

    int searchByEID(const string& filename, const string& eid) // works similarly to deleteByEID, except returns an int to demonstrate which line the emp was found on
    {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            return -1;
        }

        string line;
        int lineNumber = 0;
        while (getline(file, line)) {
            istringstream iss(line);
            string email, currentEid;
            iss >> email >> currentEid;

            if (currentEid == eid) {
                file.close();
                return lineNumber;
            }
            lineNumber++;
        }

        file.close();
        return -1;
    }

    void generateReports() // funct currently under development
    {
        cout << "generating reports:" << endl;
    }

    void viewAppInfo() // funct currently under development
    {
        cout << "Viewing application info:" << endl;
    }
};

class Employee : public User { // inherits public members from User class
    string _addressLine1;
    string _addressLine2;
    double _salary;
    string _city;
    string _statuse;
    string _zip;

public:
    string dateHired;

    Employee() // default constructor for Employee class
        : User()
    {
        dateHired = __DATE__;
    }

    Employee( // parameterized constructor for the Employee class
        string email, 
        string id, 
        string dob, 
        string firstName, 
        string lastName,
        string surName, 
        string dept, 
        string job, 
        int status, 
        int gender,
        int payType, 
        string hired, 
        UserType type)
    
        : User(
            email, 
            id, 
            dob, 
            firstName, 
            lastName, 
            surName, 
            dept, 
            job, 
            status, 
            gender, 
            payType, 
            hired, 
            type)
    {
        dateHired = hired.empty() ? __DATE__ : hired; // if dateHired is empty, today's date becomes their hire date, if not the date entered becomes it'
    }

    void formatDate(int m, int d, int y) // returns a concatinated string in an appropriate date format (currently not in use)
    {
        dateHired = to_string(m) + " " + to_string(d) + " " + to_string(y);
    }

    void enterHoursWorked() // funct currently under development
    { 
        cout << "Entering hours worked:" << endl;
    }

    void requestPTO() // funct currently under development
    {
        cout << "Requesting PTO:" << endl;
    }

    void calculatePayCheck() // funct currently under development
    {
        cout << "Calculating paycheck:" << endl;
    }
};

class Payroll { // payroll class used to perform calculations and output values, within a seperate class
    double _grossPay;
    double _netPay;
    double _statuseTax;
    double _federalTax;
    double _socialSecurityTax;
    double _medicareTax;
    bool _isLocked;

public:
    string payrollID = "";
    double baseSalary = 0.0;
    int medicalCoverage = -1;
    int numDependents = 0;

    double calculateGrossPay() // funct currently under development
    {
        cout << "Calculating gross pay:" << endl;
        return 0.0;
    }

    double calculateNetPay() // funct currently under development
    {
        cout << "Calculating net pay:" << endl;
        return 0.0;
    }

    void lockPayroll() // funct currently under development
    {
        cout << "Locking payroll:" << endl;
    }

    void generateHRReport() // funct currently under development
    {
        cout << "generating HR report:" << endl;
    }
};

class TimeEntry { // used to keep track of employee's time entry
    bool isOvertime;

public:
    string entryID = "";
    string date = __DATE__; // keeps track of today's date'
    double hoursWorked = 0.0; 
    bool isPTO = false; // by default false

    void addTimeEntry() // funct currently under development
    {
        cout << "Adding time entry:" << endl;
    }

    void editTimeEntry() // funct currently under development
    {
        cout << "Editing time entry:" << endl;
    }

    double calculateOvertime() // funct currently under development
    {
        cout << "Calculating overtime:" << endl;
        return 0.0;
    }
};

class PayrollSystem { // PayrollSystem class, which creates a map (key value set) and refers to getLoginData() as reference, returns accessed logindata
    map<string, User*> loginData;

public:
    const map<string, User*>& getloginData() const
    {
        return loginData;
    }

    User* current_user = nullptr; // User nullptr initalization 

    PayrollSystem() // by default calls the load all data function, which in the future will load data from multiple areas within the code
    {
        loadAllData();
    }

    ~PayrollSystem() // ensures when the destructor is called, all allocated heap memory from the map gets freed and reduce memory leak potential
    {
        for (auto& pair : loginData) {
            delete pair.second;
        }
    }

    void loadAllData() // as previously mentioned, calls functions by name to load data from files
    {
        loadEmployeeData();
    }

    void writeEmployeeData() // checks if employeeData.txt is currently open, and if it is empty or not, if it is, one is created with a default admin login
    {
        ifstream checkFile("employeeData.txt");

        if (!checkFile.is_open() || checkFile.peek() == ifstream::traits_type::eof()) {
            ofstream employeeData("employeeData.txt");
            cout << "------------------------------------\n";

            if (employeeData.is_open()) {
                employeeData << "defaultadmin AID0000 admin de fault none Administration Admin 1 0 0 00/00/0000 ADMIN";
                employeeData.close();

                cout << "Existing employeeData.txt not found, or was found empty!\nNew file created with default admin credentials!" << endl;

            } else {
                cerr << "Error creating the employeeData.txt file!" << endl;
            }
        } else {
            cout << "------------------------------------\n";
            cout << "Loading employee data..." << endl;
            checkFile.close();
        }
    }

    void loadEmployeeData() // loads employee data from text file, starting by clearing previously mapped allocated memory, essentially works as an update if any changes were made
    {

        for (auto& pair : loginData) { // free allocated memory in the map
            delete pair.second;
        }

        loginData.clear();
        writeEmployeeData(); // can either create a default admin, if none exists, or reference existing data

        ifstream dataFile("employeeData.txt");
        ofstream loginFile("loginData.txt", ios::trunc); // ios::trunc opens the file for output and truncates any existing data

        string line;
        while (getline(dataFile, line)) { // ensures all lines are read
            istringstream iss(line);
            string email, id, dob, firstName, lastName, surName, dept, job, hired, typeStr;
            int status, gender, payType;

            if (iss >> email >> id >> dob >> firstName >> lastName >> surName
                >> dept >> job >> status >> gender >> payType >> hired >> typeStr) {

                string cleanDob = dob; // default password is built by an employees first, last, and dateofbirth!
                cleanDob.erase(remove(cleanDob.begin(), cleanDob.end(), '/'), cleanDob.end()); // removes / symbols from date
                string password = firstName + lastName + cleanDob;

                UserType type = (typeStr == "ADMIN") ? ADMIN : EMPLOYEE;
                User* user;

                if (type == ADMIN) { // sets users to their appropriate user type based on the last word on the line "ADMIN" or "EMPLOYEE", also assigns them the literal form of the type so their type can be referenced by 0 or 1
                    user = new Admin(email, id, dob, firstName, lastName, surName, dept, job, status, gender, payType, hired, type);

                } else {
                    user = new Employee(email, id, dob, firstName, lastName, surName, dept, job, status, gender, payType, hired, type);
                }

                user->setPassword(password); // sets default password
                loginData[email] = user;

                loginFile << email << " " << user->getPasswordHash() << " " // stores hashed version of the password for validation in loginData.txt (loginFile)
                          << (type == ADMIN ? "admin" : "employee") << endl;
            }
        }
        cout << "------------------------------------\n";
    }

    void loadloginData() // opens and read the loginData.txt file, for login validation, exits with code 1 if failed
    {
        ifstream file("loginData.txt");
        if (!file.is_open()) {
            cerr << "Failed to open file" << endl;
            exit(1);
        }

        string email, type;
        size_t passwordHash;

        while (file >> email >> passwordHash >> type) {
            User* user = nullptr;
            if (type == "admin") {
                Admin* admin = new Admin();
                admin->email = email;
                admin->setPasswordHash(passwordHash);
                admin->userType = ADMIN;
                user = admin;
            } else if (type == "employee") {
                Employee* employee = new Employee();
                employee->email = email;
                employee->setPasswordHash(passwordHash);
                employee->userType = EMPLOYEE;
                user = employee;
            }

            if (user) {
                loginData[email] = user;
            }
        }

        file.close();
    }

    void main_menu() // frequently reference main menu of the program!
    {

        char choice;

        cout << "Welcome to ABC Company's Payroll Application!" << endl;
        cout << "Bare with us as the app is still in development, thank you!" << endl;

        while (true) {
            cout << "1 - Login" << endl;
            cout << "2 - Exit" << endl;

            cout << "Choose option: ";
            cin >> choice;

            if (choice == '1')
                this->login();
            else if (choice == '2')
                break;
            else
                cout << "Invalid, please try again" << endl;
        }
    }

    void login() // login menu 
    {
        string email;
        string password;
        string type;

        cout << "Enter your User Type (admin/employee): ";
        cin >> type;
        cout << "Email: ";
        cin >> email;
        cout << "Password: ";
        cin >> password;

        if (loginData.find(email) != loginData.end() && loginData[email]->validatePassword(password)) {
            current_user = loginData[email];
        // next if statement checks if the user logging in is an admin or employee this is to make sure the right user gets logged into the right place
            if ((type == "admin" && current_user->userType == EMPLOYEE) || (type == "employee" && current_user->userType == ADMIN)) {
                cout << "Invalid user type, try again!" << endl;
                return;
            } else if (type == "admin" && current_user->userType == ADMIN) {
                cout << "Login successful!" << endl;
                admin_menu(); // admins are passed to the admin menu
            } else if (type == "employee" && current_user->userType == EMPLOYEE) {
                cout << "Login successful!" << endl;
                employee_menu(); // employees are passed to the employee menu
            }
        } else {
            cout << "Invalid email or password." << endl;
        }
    }
 
    void admin_menu() // admin menu
    {
        char choice;
        cout << "Admin menu accessed:" << endl;

        Admin* admin = dynamic_cast<Admin*>(current_user); // current_user is casted as an Admin type, this is casted at run time, if it fails, program will silently log an error in the form of an exception

        if (!admin) {
            cout << "Current user is not an admin." << endl;
            return;
        }

        while (true) {
            cout << "1 - Employee demographics" << endl;
            cout << "2 - Payroll info / Calculate Payroll" << endl;
            cout << "3 - Add/Edit/Delete Employee" << endl;
            cout << "4 - Employee Search" << endl;
            cout << "5 - Reporting" << endl;
            cout << "6 - Application information" << endl;
            cout << "7 - Exit" << endl;

            cout << "Choose option: ";
            cin >> choice;

            if (choice == '1')
                admin->accessEmployeeDemographics(this); // obj->func(this) is used to access the values assosciated with the admin object
            else if (choice == '2')
                admin->managePayroll();
            else if (choice == '3')
                admin->addEditDeleteEmployee();
            else if (choice == '4')
                admin->searchEmployee(this);
            else if (choice == '5')
                admin->generateReports();
            else if (choice == '6')
                admin->viewAppInfo();
            else if (choice == '7')
                break;
            else
                cout << "Invalid, please try again" << endl;
        }
    }

    void employee_menu() // employee menu
    {
        char choice;
        cout << "Employee menu accessed:" << endl;

        Employee* employee = dynamic_cast<Employee*>(current_user);

        if (!employee) {
            cout << "Current user is not an employee!" << endl;
            return;
        }

        while (true) {
            cout << "1 - Timecard" << endl;
            cout << "2 - Add PTO" << endl;
            cout << "3 - Calculate paycheck" << endl;
            cout << "4 - Exit" << endl;

            cout << "Choose option: ";
            cin >> choice;

            if (choice == '1')
                employee->enterHoursWorked();
            else if (choice == '2')
                employee->requestPTO();
            else if (choice == '3') {
                employee->calculatePayCheck();
            } else if (choice == '4') {
                break;
            } else
                cout << "Invalid, please try again" << endl;
        }
    }

    void employee_management() // funct currently under development
    {
        cout << "Employee management accessed:" << endl;
    }

    void payroll_management() // funct currently under development
    {
        cout << "Payroll management accessed:" << endl;
    }

    void create_employee_record() // funct currently under development
    {
        cout << "Creating employee record:" << endl;
    }

    void manage_payroll_menu() // funct currently under development
    {
        cout << "Managing payroll menu:" << endl;
    }

    void calculate_payroll() // funct currently under development
    {
        cout << "Calculating payroll:" << endl;
    }
 
    void time_entry() // funct currently under development
    {
        cout << "Time entry accessed:" << endl;
    }
};

void Admin::searchEmployee(PayrollSystem* system) // Admin member function that searches for an employee by first updating current employeeData
{
    system->loadEmployeeData();

    cout << "\nSearch results:\n";
    const auto& users = system->getloginData();

    string firstSearch;
    string lastSearch;

    cout << "Please enter first name: ";
    cin >> firstSearch;
    cout << "Please enter last name: ";
    cin >> lastSearch;

    for (const auto& pair : users) {
        User* user = pair.second;

        if (user->firstName == firstSearch && user->lastName == lastSearch) {
            cout << "User Type: " << (user->userType == ADMIN ? "ADMIN" : "EMPLOYEE") << endl;
            cout << "User ID: " << user->userID << endl;
            cout << "First Name: " << user->firstName << endl;
            cout << "Last Name: " << user->lastName << endl;
            cout << "Sur Name: " << user->surName << endl;
            cout << "Email: " << user->email << endl;
            cout << "Date of Birth: " << user->getDateOfBirth() << endl;
            cout << "Department: " << user->department << endl;
            cout << "Job Title: " << user->jobTitle << endl;
            cout << "Status: " << getstatusString(user->status) << endl;
            cout << "Gender: " << getgenderString(user->gender) << endl;
            cout << "Pay Type: " << getpayTypeString(user->payType) << endl;

            if (user->userType == EMPLOYEE) {
                Employee* emp = dynamic_cast<Employee*>(user);
                cout << "Date Hired: " << emp->dateHired << "\n";
            } else {
                Admin* adm = dynamic_cast<Admin*>(user);
                cout << "Date Hired: " << adm->dateHired << endl;
            }
            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
            cout << "------>>>>Employee found!<<<<-------\n";
            cout << "------------------------------------\n";
            break;
        } else {

            cout << "[x] Employee \""<< firstSearch << " "<< lastSearch << "\" did not match any records, please try again! [x]" << endl;
            break;
        }
    }
}

void Admin::accessEmployeeDemographics(PayrollSystem* system) // Admin member function that prints all the current employees on payroll, admins included
{
    system->loadEmployeeData();
    cout << "\nEmployee Demographics:\n";
    const auto& users = system->getloginData();

    int employeeCount = 0;
    int adminCount = 0;

    for (const auto& pair : users) {
        if (pair.second->userType == EMPLOYEE)
            employeeCount++;
        else if (pair.second->userType == ADMIN)
            adminCount++;
    }

    cout << "Total Employees: " << employeeCount << "\n";
    cout << "Total Admins: " << adminCount << "\n\n";

    for (const auto& pair : users) {
        User* user = pair.second;

        if (user->userType == EMPLOYEE || user->userType == ADMIN) {
            cout << "User Type: " << (user->userType == ADMIN ? "ADMIN" : "EMPLOYEE") << endl;
            cout << "User ID: " << user->userID << endl;
            cout << "First Name: " << user->firstName << endl;
            cout << "Last Name: " << user->lastName << endl;
            cout << "Sur Name: " << user->surName << endl;
            cout << "Email: " << user->email << endl;
            cout << "Date of Birth: " << user->getDateOfBirth() << endl;
            cout << "Department: " << user->department << endl;
            cout << "Job Title: " << user->jobTitle << endl;
            cout << "Status: " << getstatusString(user->status) << endl;
            cout << "Gender: " << getgenderString(user->gender) << endl;
            cout << "Pay Type: " << getpayTypeString(user->payType) << endl;

            if (user->userType == EMPLOYEE) {
                Employee* emp = dynamic_cast<Employee*>(user);
                cout << "Date Hired: " << emp->dateHired << "\n";
            } else {
                Admin* adm = dynamic_cast<Admin*>(user);
                cout << "Date Hired: " << adm->dateHired << endl;
            }

            cout << "------------------------------------\n";
        }
    }
}

int main()
{
    PayrollSystem system;
    system.main_menu();
    return 0;
}
