#include <iostream>
#include <datetimeapi.h>
#include <string>

using namespace std;

class User {

    string _password;
    string _dateOfBirth;

public:

    string email;
    string userID;

    User() : _password(""), _dateOfBirth("") {
        email = "";
        userID = "";
    }
    User(string e, string dob, string id, string pass) : email(e), _dateOfBirth(dob), userID(id), _password(pass) {}
    
};

class Admin : private User {

    bool _admin = true;

public:

    string adminID = userID;

};

class Employee : private User {

public:

    string employeeID = userID;
    string firstName = "";
    string lastName = "";
    string department = "";
    string jobTitle = "";
    int status = -1;
    string gender = "";
    int payType = -1;
    string month,day,year;
    string dateHired = "";

    Employee() : User() {
        dateHired = __DATE__;
    }

    Employee(string e, string dob, string id, string pass, string hired) : User(e, dob, id, pass) {
        if(hired.empty())
            dateHired = __DATE__;
        else
            dateHired = hired;
    }
    void formatDate(int m, int d, int y) {
        dateHired = to_string(m) + " " + to_string(d) + " " + to_string(y);
    }
};

class Payroll {

public:

    string payrollID = "";
    int baseSalary = 0.0;
    int medicalCoverage = -1;
    int numDependents = 0;

};

class TimeEntry {

public:

    string entryID = "";
    string date = __DATE__;
    int hoursWorked = 0.0;
    bool isPTO = false;

};

class PayrollSystem {

public:

    int current_user = -1;
    int user_type = -1;

    void main_menu() {

        char choice;
    
        while(true) {
        cout << "1 - Login" << endl;
        cout << "2 - Exit" << endl;

        cout <<"Choose option: "; cin >> choice;

        if (choice == '1')
            this->login();
        else if (choice == '2')
            break;
        else
            cout << "Invalid, please try again" << endl;
        }
    }

    void login() {
        string email;
        string password;

        cout << "Email: "; cin >> email;
        cout << "Password: "; cin >> password;

        if ( email == "admin") {
            user_type = 3; // admin
            admin_menu();    
        }
        else {
            user_type = 2; // employee
            employee_menu();
        }
    }

    void admin_menu() {
    }

    void employee_management() {

    }

    void payroll_management() {

    }

    void create_employee_record() {

    }

    void manage_payroll_menu() {

    }

    void calculate_payroll() {

    }

    void employee_menu() {

    }

    void time_entry() {

    }


};
int main() {

    PayrollSystem system;
    system.main_menu();
    
    Employee emp1("email@company.com", "01/01/1990", "" , "password", "");

    emp1.formatDate(02, 06, 1982);

    emp1.firstName = "John";
    emp1.lastName = "Doe";
    emp1.department = "Engineering";
    emp1.jobTitle = "Software Engineer";
    emp1.status = 1;

    cout << emp1.firstName << endl;
    cout << emp1.lastName << endl;
    cout << emp1.department << endl;
    cout << emp1.jobTitle << endl;
    cout << emp1.status << endl;
    cout << emp1.dateHired << endl;


    return 0;
}