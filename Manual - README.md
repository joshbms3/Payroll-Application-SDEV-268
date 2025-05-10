---------------------------------------------------------------------------------------------------
                                                                           
  ;:=-.,_-*^*-_,.-= Welcome to Joshua's Payroll App Readme! =-.,_-*^*-_,.-=:;
                                                                          
---------------------------------------------------------------------------------------------------
                                                                        
Course: SDEV 268                                      
Professor: Marlene Gordon                        
Assignment: ABC Company Payroll Application           
Due Date: 5/11/2025                                   
Student: Joshua Barroso                              
Programming Language: C++                                
Database Architecture: .txt files                        
                                                                           
---------------------------------------------------------------------------------------------------
                                                                              
  When launching the payrollApp.exe, a terminal will be launched the first  
  message that prints is a description of whether or not employee data 
  has been successfully loaded or not, if the file loaded successfully, the    
  user will see:                                                            
                                                                           
    ------------------------------------
    Loading employee data...
    ------------------------------------

---------------------------------------------------------------------------------------------------

  If the file does not load successfully and a default file must be created
  the following message will appear:

    ------------------------------------
    Existing employeeData.txt not found, or was found empty!      
    New file created with default admin credentials!
    ------------------------------------

---------------------------------------------------------------------------------------------------

  When a default employeeData.txt file is made, a default admin login will
  be made in the following format, and is saved in a seperate file called
  loginData.txt

      login id        hashed password     employee type
         |                   |                  |
    defaultadmin    1686552567726710310       admin

---------------------------------------------------------------------------------------------------

   This default password for all employees (unless changes) is generated
   from the employee-
  -Data.txt file by taking the first name, last name (case sensitive), and
   numerical values in their date of birth, so the previous login id and pass
  -word were generated from the following default data: (made because no file
   was found when the app was launched)

        (default values)
       login id         unique id  hire date  first name last name   nick      department    title    status  gender paytype   dob    employee type
           |                |         |           |         |        |            |           |        |       |       |       |          |
     defaultadmin        AID0000     none         de       fault    none    Administration   Admin     1      -1       0   00/00/0000   ADMIN

       (actual data example)
       login id         unique id  hire date  first name last name  nick       department      title     status    gender  paytype    dob      employee type
           |                |          |          |         |        |            |              |          |         |         |         |            |
    joshuabarroso@msn.com AID2002 06/29/1993   Joshua    Barroso     Josh        IT     SoftwareDeveloper   1         0         1     05/05/2025  ADMIN
  

---------------------------------------------------------------------------------------------------

  After this is done, the welcome message and main menu system is accessed to display options so
  a user can select from the following options:

    Welcome to ABC Company's Payroll Application!
    Bare with us as the app is still in development, thank you!
    1 - Login
    2 - Exit
    Choose option:

                                                                           
---------------------------------------------------------------------------------------------------

  When logging in with option 1: for example using default login credentials:

    Enter your User Type (admin/employee):
    is displayed to the screen, when using the defaul login creditions, "admin"
    would need to be entered

---------------------------------------------------------------------------------------------------
  
  After entering "admin" the user will have to login providing an email and
  password, in this case the default id and password are listed above,
  (id = defaultadmin, pw = defaultadmin)

---------------------------------------------------------------------------------------------------

  Once the login is successful the user is greeted with the following information

    Login successful!
    Admin menu accessed:
    1 - Employee demographics
    2 - Payroll info / Calculate Payroll
    3 - Add/Edit/Delete Employee
    4 - Employee Search
    5 - Reporting
    6 - Application information
    7 - Exit
    Choose option: 

  When selecting option 3 the user can add/edit/delete any employee or admin,
  depending on current user access (admin or employee)

---------------------------------------------------------------------------------------------------

  After selecting option 3 the following menu displays:

    Employee Management Options
    1 - Add New Employee
    2 - Edit Existing Employee
    3 - Delete Employee
    4 - Return to Main Menu
    Choose option:

  By using option 3 you can add a new admin or employee,
  and once a new admin is added the default admin will be deleted and a message will
  be printed to the terminal for the user:

    Enter New Employee Details:
    Email: joshuabarroso@msn.com
    Is this an admin? (y/n): y
    Date of Birth (MM/DD/YYYY): 06/29/1993
    First Name: Joshua
    Last Name: Barroso
    Surname (required): Josh
    Department: IT
    Job Title: SoftwareDeveloper
    Status (1 for Active, 0 for Inactive, -1 for Terminated): 1
    Gender (0 for Male, 1 for Female, 3 for Other): 0
    Pay Type (0 for Hourly, 1 for Salary): 1
    Date Hired (MM/DD/YYYY): 05/10/2025

---------------------------------------------------------------------------------------------------


  Once a new admin is added the default admin will be deleted and a message will
  be printed to the terminal for the user:

    Default admin removed because a new admin has been added!
    Employee with EID AID0000 deleted successfully.

    Employee added successfully!
    1 - Employee demographics
    2 - Payroll info / Calculate Payroll
    3 - Add/Edit/Delete Employee
    4 - Employee Search
    5 - Reporting
    6 - Application information
    7 - Exit
    Choose option:

---------------------------------------------------------------------------------------------------

  Admin users can then print employee demographics, which prints out a list of all admins and employees and their information
  and records!
  
    ------------------------------------
    Loading employee data...
    ------------------------------------
    
    Employee Demographics:
    Total Employees: 0
    Total Admins: 1
    
    User Type: ADMIN
    User ID: AID2002
    First Name: Joshua
    Last Name: Barroso
    Sur Name: Josh
    Email: joshuabarroso@msn.com
    Date of Birth: 06/29/1993
    Department: IT
    Job Title: SoftwareDeveloper
    Status: Active
    Gender: Male
    Pay Type: Salary
    Date Hired: 05/10/2025
    ------------------------------------
    1 - Employee demographics
    2 - Payroll info / Calculate Payroll
    3 - Add/Edit/Delete Employee
    4 - Employee Search
    5 - Reporting
    6 - Application information
    7 - Exit
    Choose option:

---------------------------------------------------------------------------------------------------

  I hope this brief explanation for how my app works help you navigate your way to
  building, managing, and profiting greatly with ABC company!
  If you have any comments, questions, concerns with the application and any future
  ideas or just want to chat, feel free to email me at jbarroso1@ivytech.edu!

                  ;:=-.,_-*^*-_,.-= THANK YOU! =-.,_-*^*-_,.-=:;

---------------------------------------------------------------------------------------------------
