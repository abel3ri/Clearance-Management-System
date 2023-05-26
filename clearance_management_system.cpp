#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

// ! Data structures

// LinkeList Implementation with insertData()(at the back of the linked list), search() and display() operations

struct lsNode{
    string userID;
    lsNode *next;
};
struct LinkedList{
    lsNode *head = NULL, *tail = NULL;

    // inserting data at the end of the linked list
    void insertData(string userID){
        lsNode *newNode = new lsNode;
        newNode->userID = userID;
        newNode->next = NULL;
        if(head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    bool search(string value){
        lsNode *temp = head;
        while(temp != NULL){
            if(temp->userID == value){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void display(){
        lsNode *temp = head;
        while(temp != NULL){
            cout << temp->userID << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Stack Implemntation with push(), pop(), and search() operations

struct StackNode{
    string data;
    StackNode *next;
};
struct Stack{
    StackNode *top = NULL;

    void push(string value){
        StackNode *newNode = new StackNode;
        newNode->data = value;
        newNode->next = NULL;
        if(top == NULL){
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }
    void pop(){
        if(top == NULL){
            // cout << "The stack is empty!\n";
            return;
        } else {
            StackNode *temp = top;
            top = top->next;
            delete temp;
        }
    }
     bool search(string value){
        StackNode *temp = top;
        if(top == NULL){
            // cout << "The stack is empty\n";
            return false;
        }
        else {
            while(temp != NULL){
                if(temp->data == value){
                    return true;
                }
                temp = temp->next;
            }
        }
        return false;
    }
    void display(){
        if(top == NULL){
            // cout << "The stack is empty!\n";
            return;
        } else {
            StackNode *temp = top;
            while(temp != NULL){
                cout << temp->data << endl;
                temp = temp->next;
            }

        }
    }
};

// Queue implementation with enque(), dequeue(), display(), clearQueue(), and length() operations

struct queueNode{
    string data;
    queueNode *next;
};
struct Queue{
    queueNode *rear = NULL, *front = NULL;

    void enQueue(string data){
        queueNode *newNode = new queueNode;
        newNode->data = data;
        newNode->next = NULL;
        if(front == NULL){
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void deQueue(){
        if(front  == NULL){
            // cout << "The queue is empty!\n";
            return;
        } else {
           queueNode *temp = front;
            if(temp == NULL){
                // cout << "Empty Queue";
                return;
            } else {
                front = front->next;
                delete temp;
            }
        }
    }
    void display(){
        queueNode *temp = front;
        if(temp == NULL){
            // cout << "Empty Queue";
            return;
        } else {
            while(temp != NULL){
                cout << " " <<  temp->data << "\n\n";
                temp = temp->next;
            }
        }
    }
    void clearQueue(){
        queueNode *temp = front;
        if(temp != NULL){
            while(front != NULL){
                temp = front;
                front = front->next;
                delete temp;
            }
        }
    }
    int length(){
        int counter = 0;
        queueNode *temp = front;
        if(front == NULL){
            counter = 0;
        } else {
            while(temp != NULL){
                temp = temp->next;
                ++counter;
            }
        }
        return counter;
    }
};

// ! Function declarations

void registerS();
void registerCA();
void loginS(string inputID, string inputPassword);
void loginCA(string inputID, string inputPassword);
void loginSA(string id, string password);
void checkClearanceStatus(string fName, string ID);
void manageStudents();
void manageClearanceApprovers();
void loading();
// Main function
int main(){

    int chMain, chRegister, chLogin;
    while(chMain != 5){

    // Welcome screen
    welcomeScreen:
    cout << "\n";
    cout << "       ************** Welcome to DBU Clearance Management System *****************\n\n";
    cout << "       *                          1. Create new account                          *\n\n";
    cout << "       *                          2. Login to the system                         *\n\n";
    cout << "       *                          3. Check clearance status                      *\n\n";
    cout << "       *                          4. About the project                           *\n\n";
    cout << "       *                          5. Exit                                        *\n\n";
    cout << "       ***************************************************************************\n";
    cin >> chMain;
    if(chMain == 1){
        system("cls");
        cout << " ********************** 1. Create new account **************************\n";
        cout << "\n 1. Register as a Student\n\n";
        cout << " 2. Register as a Clearance Approver\n\n";
        cout << " 3. Back\n\n";
        cin >> chRegister;
        if(chRegister == 1) {
            system("cls");
            cout << " ********************** 1. Register as a Student **************************\n";
            registerS();
        }
        else if(chRegister == 2){
            system("cls");
            cout << " ********************** 2. Register as a Clearance Approver **************************\n";
            registerCA();
        }
        else if(chRegister == 3) {
            system("cls");
            goto welcomeScreen;
        }
    } else if(chMain == 2){
        system("cls");
        cout << " ********************** 2. Login to the system  **************************\n\n";
        cout << " 1. Login as a Student\n\n";
        cout << " 2. Login as a Clearance Approver\n\n";
        cout << " 3. Login as a System Admin\n\n";
        cout << " 4. Back\n\n";
        cin >> chLogin;
        if(chLogin == 1){
            system("cls");
            cout << " ********************** 1. Login as a Student  **************************\n\n";
            string ID, password;
            cout << " Please enter your ID number: ";
            cin >> ID;
            cout << "\n Please enter your password: ";
            cin >> password;
            loginS(ID, password);
        }
        else if(chLogin == 2){
            system("cls");
            cout << " ********************** 2. Login as a Clearance Approver  **************************\n\n";
            string ID, password;
            cout << " Please enter your ID number: ";
            cin >> ID;
            cout << "\n Please enter your password: ";
            cin >> password;
            loginCA(ID, password);
        }
        else if(chLogin == 3){
            
            system("cls");
            cout << " ********************** 1. Login as a System Admin  **************************\n\n";
            string id, password;
            cout << " Please enter your id number(sa/1): ";
            cin >> id;
            cout << "\n Please enter your password(password = 123): ";
            cin >> password;
            loginSA(id, password);
        }
        else if(chLogin == 4) {
            system("cls");
            goto welcomeScreen;
        };
    } else if(chMain == 3){
        string fName, ID;
        system("cls");
        cout << " ********************** 3. Check clearance status  **************************\n\n";
        cout << " Please enter your first name: ";
        cin >> fName;
        cout << "\n Please enter your ID: ";
        cin >> ID;
        checkClearanceStatus(fName, ID);
    }
    else if(chMain == 4){
        system("cls");
        cout << "\033[1;32m**********  Clearance management system ***************\033[0m\n\n";
        cout << "**********  Developed by Group two members ************\n\n";
        cout << "   --Name--                                 --ID Number--\n\n";
        cout << "\033[1;36m  Abel Merete                               DBUR/0032/13\n";
        cout << "  Samuel Kifle                              DBUR/0698/13\n";
        cout << "  Abdulaziz Musa                            DBUR/0597/13\n";
        cout << "  Yohannes Tamirat                          DBUR/0786/13\n";
        cout << "  Mikias Bayle                              DBUR/0262/13\n";
        cout << "  Fikade Tibebe                             DBUR/1400042\n";
        cout << "  Tarik Dabot                               DBUR/1400100\n";
        cout << "  Dawit Bekele                              DBUR/0952/13\n";
        cout << "  Muse Madalcho                             DBUR/3720/13\033[0m\n\n";
        break;
    }
    }
    return 0;
}

// ! Function definitions

void registerS(){
    bool isRegistered = false;
    LinkedList ls;
    // int userID;
    string fName, lName, ID, password, rePassword, IDCopy, isApproved = "NotApproved", isAppr;
    ofstream oStudents("students.txt", ios::app);
    ifstream iStudents("students.txt", ios::in);
    if(iStudents.is_open()){
        while(iStudents >> fName >> lName >> IDCopy >>  password >> isAppr){
            ls.insertData(IDCopy);
        }
        // assigning user id to 1 if the linked list is empty otherwise last element plus 1.
        // userID = ls.head == NULL ? 1 : ls.tail->id + 1;
        iStudents.close();
    } else {
        cout << " Error opennig students.txt for reading!\n";
    }
    cout << "\n Please enter your first name(e.g. Abebe): ";
    cin >> fName;
    cout << "\n Please enter your last name(e.g. Kebede): ";
    cin >> lName;
    cout << "\n Please enter your ID number(e.g. DBUR/1234/13): ";
    cin >> ID;
    // Converting the ID to its upper case equivalent
    for(int i = 0; i < ID.length(); i++){
        ID[i] = toupper(ID[i]);
    }
    bool isFound = ls.search(ID);
    if(isFound){
        cout << "\n\033[1;31m This account is already registered!\033[0m" << "\n\n";
        system("pause");
        system("cls");
        return;
    }
    label:
    cout << "\n Please enter your password: ";
    cin >> password;
    cout << "\n Please re-enter your password: ";
    cin >> rePassword;
    if(password != rePassword){
       cout << "\n\033[1;31m Password do not match!\033[0m\n";
        goto label;
    }
    // ofstream oStudents("students.txt", ios::app);
    if(oStudents.is_open()){
        oStudents << fName << " " << lName << " " << ID << " " << password <<  " " << isApproved << "\n";
        isRegistered = true;
        oStudents.close();
    } else {
        cout << " Error openning students.txt for writing!\n";
    }
    if(isRegistered == true){
        cout << "\n";
        loading();
        system("cls");
      cout << "\n\033[1;32m Hello, " << fName << " you're " <<"successfuly registered as a student!\033[0m\n\n";
    } else {
        cout << "\n\033[1;32m Error registering!\033" << "\n\n";
    }
    system("pause");
    system("cls");
}
void registerCA(){

    bool isRegistered = false;
    LinkedList ls;
    // int userID;
    string fName, lName, ID, password, rePassword, IDCopy;
    ofstream oClearanceApprovers("clearanceApprovers.txt", ios::app);
    ifstream iClearanceApprovers("clearanceApprovers.txt", ios::in);
    if(iClearanceApprovers.is_open()){
        while(iClearanceApprovers >> fName >> lName >> IDCopy >>  password){
            ls.insertData(IDCopy);
        }
        // assigning user id to 1 if the linked list is empty otherwise to last element plus 1.
        // userID = ls.head == NULL ? 1 : ls.tail->id + 1;
        iClearanceApprovers.close();
    } else {
        cout << "Error opennig clearanceApprovers.txt\n";
    }
    cout << "\n Please enter your first name(e.g. Abebe): ";
    cin >> fName;
    cout << "\n Please enter your last name(e.g. Kebede): ";
    cin >> lName;
    cout << "\n Please enter your ID number(e.g. DBUCA/1234): ";
    cin >> ID;
    // Converting the ID to its upper case equivalent
    for(int i = 0; i < ID.length(); i++){
        ID[i] = toupper(ID[i]);
    }
    bool isFound = ls.search(ID);
    if(isFound){
        cout << "\n\033[1;31m This account is already registered!\033[0m" << endl << endl;
        system("pause");
        system("cls");
        return;
    }
    label:
    cout << "\n Please enter your password: ";
    cin >> password;
    cout << "\n Please re-enter your password: ";
    cin >> rePassword;
    if(password != rePassword){
       cout << "\n\033[1;31m Password do not match!\033[0m\n";
        goto label;
    }
    if(oClearanceApprovers.is_open()){
        oClearanceApprovers << fName << " " << lName << " " << ID << " " << password << "\n";
        isRegistered = true;
        oClearanceApprovers.close();
    } else {
        cout << "Error openning the file.\n";
    }
    if(isRegistered == true){
        cout << "\n";
        loading();
        system("cls");
      cout << "\n\033[1;32m Hello, " << fName << " you're " <<"successfuly registered as a clearance approver!\033[0m\n\n";
    } else {
        cout << "\033[1;32mError registering!\033" << "\n\n";
    }
    system("pause");
    system("cls");
}

// Loging students to the system
void loginS(string inputID, string inputPassword){

    bool userFound = false;
    // int userID;
    string fName, lName, ID, password, IDCopy, isApproved;
    for(int i = 0; i < inputID.length(); i++){
        inputID[i] = toupper(inputID[i]);
    }
    fstream iStudents("students.txt", ios::in | ios::app);
    if(iStudents.is_open()){
        while(iStudents >> fName >> lName >> ID >> password >> isApproved){
            if(ID == inputID){
                if(inputPassword == password){
                userFound = true;
                break;
                } else {
                    system("cls");
                    cout << " Please check your password and try again.\n\n";
                    system("pause");
                    system("cls");
                    return;
                }
            }
        }
        if(!userFound){
            system("cls");
            cout << "\033[1;31mUser not found!\033[0m\n\n";
            system("pause");
            system("cls");
            return;
        }

        iStudents.close();
    } else {
        cout << " Error opening students.txt for reading!\n";
    }
    int choice;
    if(userFound){
        label:
        ofstream oClearance("clearances.txt", ios::app);
        ifstream iClearance("clearances.txt", ios::in);
        Stack st;
        // cout << "\n\n";
        // loading();
        system("cls");
        cout << "\033[1;32mHello, " << fName << "\033[0m"<< "\n\n";
        cout << " 1. Request clearance: \n\n";
        cout << " 2. Check clearance status: \n\n";
        cout << " 3. Logout: \n\n";
        cin >> choice;
        if(choice == 1){
            if(isApproved == "Approved"){
                system("cls");
                cout << "\n You're already approved by the clearance approver.\n\n";
                system("pause");
                system("cls");
                goto label;
            } else {
                if(iClearance.is_open()){
                while(iClearance >> IDCopy){
                    st.push(IDCopy);
                }
                iClearance.close();
                } else cout << " Error opening clearances.txt for reading!\n";
                // bool isFound = st.search(ID);
                if(st.search(ID)){
                    system("cls");
                    cout << "\n\033[1;33m You have already submitted a request before.\033[0m\n\n";
                   system("pause");
                    goto label;
                } else {
                    if(oClearance.is_open()){
                    oClearance << ID << "\n";
                    system("cls");
                    cout << "\n\033[1;32m Your clearance request is successfully submitted!\033[0m\n\n";
                    system("pause");
                    oClearance.close();
                    goto label;
                } else {
                    cout << "Error opening clearances.txt for writing!\n";
                }
                }
            }
        }
        else if(choice == 2){
            checkClearanceStatus(fName, ID);
            goto label;
        }
        else if(choice == 3){
            system("cls");
            return;
        }
    }
    system("cls");
}
void loginCA(string inputID, string inputPassword){
    system("cls");
     Queue qu;

    bool userFound = false;
    string fName, lName, ID, password, IDCopy;
    for(int i = 0; i < inputID.length(); i++){
        inputID[i] = toupper(inputID[i]);
    }
    fstream iClearanceApprovers("clearanceApprovers.txt", ios::in | ios::app);
    if(iClearanceApprovers.is_open()){
        while(iClearanceApprovers >> fName >> lName >> ID >> password){
            if(ID == inputID){
            if(inputPassword == password){
            userFound = true;
            break;
            } else {
                system("cls");
                cout << "Please check your password and try again.\n\n";
                system("pause");
                system("cls");
                return;
            }
            }
        }
        if(!userFound){
            system("cls");
            cout << "\n\033[1;31m User not found!\033[0m\n\n";
            system("pause");
            system("cls");
            return;
        }
        iClearanceApprovers.close();
    } else {
        cout << "Error opening clearanceApprovers.txt!\n";
    }
    if(userFound){
        int choice;
        label:
        Queue qu;
        // cout << "\n";
        // loading();
        system("cls");
        cout << "\033[1;32mHello, " << fName << "\033[0m"<< endl << endl;
        cout << " 1. Display all submitted requests\n\n";
        cout << " 2. Approve clearance requests\n\n";
        cout << " 3. Logout\n";
        cin >> choice;
        ofstream oClearances("clearances.txt", ios::app);
        ifstream iClearances("clearances.txt");
        if(choice == 1){
            string studID;
            if(iClearances.is_open()){
                while(iClearances >> studID){
                    qu.enQueue(studID);
                }
                system("cls");
                int length = qu.length();
                string s, are;
                if(length != 1){
                    s = "s";
                    are = "are";
                } else {
                    s = "";
                    are = "is";
                }
                cout << "There " << are << " currently " << length << " student" << s << " waiting for their approval.\n\n";
                qu.display();
                system("pause");
                iClearances.close();
                goto label;
            } else {
                cout << " Error opening clearances.txt!\n";
            }
        } else if(choice == 2){
            system("cls");
            Stack st;
            ifstream iStudents("students.txt", ios::in);
            ofstream oTemp("temp.txt", ios::app);
            if(iStudents.is_open() && oTemp.is_open()){
                string sfName, slName, sID, sPass, sisApproved;
                // int id;
                string cStudID;
                while(iClearances >> cStudID){
                    st.push(cStudID);
                }
                while(iStudents >> sfName >> slName >> sID >> sPass >> sisApproved){
                    bool isApproved = st.search(sID);
                    isApproved ? sisApproved = "Approved" : sisApproved;
                    oTemp << sfName << " " << slName << " " << sID << " " << sPass << " " << sisApproved << "\n";
                };
                ofstream oClearances("clearances.txt", ios::trunc);
                 cout << "\n";
                loading();  
                system("cls");
                cout << " All students waiting for clearance approval are now approved!\n\n";
                system("pause");

            } else cout << " Error opening students.txt";

            iStudents.close();
            oTemp.close();

            // Replace original file with the temporary one
            remove("students.txt");
            rename("temp.txt", "students.txt");
            goto label;
        } else if(choice == 3){
            system("cls");
            return;
        }
    }
}
void loginSA(string id, string password){

    ofstream oSystemAdmins("systemAdmin.txt", ios::trunc);
    ifstream iSystemAdmins("systemAdmin.txt", ios::in);
    if(oSystemAdmins.is_open()){
        oSystemAdmins << "Abebe" << " " << "sa/1" << " " << "123";
        oSystemAdmins.close();
    } else cout << " Error opening systemAdmin.txt for writing!\n";

    Stack st;
    bool userFound = false;
    string nameCopy, idCopy, passwordCopy;
    if(iSystemAdmins.is_open()){
        while(iSystemAdmins >> nameCopy >> idCopy >> passwordCopy){
            if(id == idCopy){
                if(password == passwordCopy){
                    userFound = true;
                } else {
                    system("cls");
                    cout << "\n\033[1;31m Password do not match. Please try again later!\033[0m\n\n";
                    system("pause");
                    system("cls");
                    return;
                }
            }
        }
    } else cout << " Error opening System Admins for reading! \n";
    
    if(userFound){
        system("cls");
        int ch;
        cout << "\n";
        loading();
        system("cls");
        cout << "\033[1;32m Hello, " << nameCopy << "\033[0m\n\n";
        cout << " 1. Manage Students\n\n";
        cout << " 2. Manage Clearance Approvers\n\n";
        cout << " 3. Log out\n\n";
        cin >> ch;

        if(ch == 1){
            // system("cls");
            manageStudents();
        } else if(ch == 2){
            // system("cls");
            manageClearanceApprovers();
        } else if(ch == 3){
            system("cls");
            return;
        }

    } else {
        system("cls");
        cout << "\033[1;31m User not found!\033[0m\n\n";
        system("pause");
        system("cls");
        return;
    }
}
void checkClearanceStatus(string fName, string ID){
    for(int i = 0; i < ID.length(); i++){
        ID[i] = toupper(ID[i]);
    }
    string name, lName, studID, pass, isApproved;
    ofstream oStudents("students.txt", ios::app);
    ifstream iStudents("students.txt", ios::in);
    bool userFound = false;
    if(iStudents.is_open()){
        while(iStudents >> name >> lName >> studID >> pass >> isApproved){
            if(ID == studID){
                userFound = true;
                break;
            }
        }
        if(userFound){
            if(isApproved == "NotApproved"){
            system("cls");
            cout << "\033[1;31mHello " << fName << ", if you have requested a clearance before, please wait patiently till you're approved.\n\nif not please request for a clearance first.\n\033[0m\n\n";
            system("pause");
            system("cls");
        } else if(isApproved == "Approved"){
            system("cls");
            cout << endl << "\033[1;32m Hello " << fName << ", You're approved to leave the campus!\n\033[0m\n\n";
            system("pause");
            system("cls");
        }
        } else {
            system("cls");
            cout << "\033[1;31mUser not found!\033[0m\n\n";
            system("pause");
            system("cls");
            return;
        }
        iStudents.close();
    } else cout << "Error opening students.txt!\n";
}
void manageStudents(){
    label:
    ifstream iStudents("students.txt");
    string fName, lName, ID, pass, isAppr;
    system("cls");
    int ch;
    cout << " 1. Display all students\n\n";
    cout << " 2. Delete a student\n\n";
    cout << " 3. Logout\n\n";
    cin >> ch;
    if(ch == 1){
        system("cls");
        if (iStudents.is_open()){
           cout << " All the students who are registered to the system are the following...\n\n";
            while(iStudents >> fName >> lName >> ID >> pass >> isAppr){
                cout  << " " << fName << " " << lName << " " <<  ID << " " << pass  << " " << isAppr << "\n\n";
            }
        } else {
            cout << "Error opening students.txt for reading and writing!\n";
        }
        system("pause");
        goto label;
    } else if(ch == 2){
        system("cls");
        string idInput;
        bool userFound = false;
        cout << " Enter the id number of the student you want to delete: ";
        cin >> idInput;
        for(int i = 0; i < idInput.length(); i++){
            idInput[i] = toupper(idInput[i]);
        }
        if(iStudents.is_open()){
             while(iStudents >> fName >> lName >> ID >> pass >> isAppr){
                if(idInput == ID){
                    userFound = true;
                    break;
                }
             }
        }
        if(userFound){
            ofstream temp("temp.txt");
            system("cls");
            char ch;
            cout << "\n Are you sure you want to delete " << fName << " with id number " << ID << " from the system (Y/n)? ";
            cin >> ch;
            if(ch == 'y' || ch == 'Y'){
            if(iStudents.is_open()){
                while(iStudents >> fName >> lName >> ID >> pass >> isAppr){
                    if(idInput == ID) continue;
                    temp << fName << " " << lName << " " << ID << " " << pass << " " << isAppr << "\n";
                }
                
            } else {
                cout << " Error opening students for reading";
            }
            // Deleting the old students.txt and renaming temp.text to students.txt after the selected user has been deleted
            iStudents.close();
            temp.close();
            
            remove("students.txt");
            rename("temp.txt", "students.txt");
             cout << "\n";
            loading();
            system("cls");
            cout << "\n\033[1;32m The student is deleted from the system successfully\033[0m\n\n";
            system("pause");
            goto label;
            } else {
            goto label;
            }
        } else {
        cout << "\n\033[1;31m User not found with the entered id\033[0m\n\n";
        system("pause");
        goto label;
            }
    } else {
        system("cls");
        return;
    }

}
void manageClearanceApprovers(){
    label:
    ifstream iClearanceApprover("clearanceApprovers.txt");
    string fName, lName, ID, pass;
    system("cls");
    int ch;
    cout << " 1. Display all clearance approvers\n\n";
    cout << " 2. Delete clearance approver\n\n";
    cout << " 3. Logout\n\n";
    cin >> ch;
    if(ch == 1){
        system("cls");
        if (iClearanceApprover.is_open()){
           cout << " All the clearance approvers who are registered to the system are the following...\n\n";
            while(iClearanceApprover >> fName >> lName >> ID >> pass){
                cout  << " " << fName << " " << lName << " " <<  ID << " " << pass << "\n\n";
            }
        } else {
            cout << "Error opening clearanceApprovers.txt for reading and writing!\n";
        }
        system("pause");
        goto label;
    } else if(ch == 2){
        system("cls");
        string idInput;
        bool userFound = false;
        cout << " Enter the id number of the student you want to delete: ";
        cin >> idInput;
        for(int i = 0; i < idInput.length(); i++){
            idInput[i] = toupper(idInput[i]);
        }

        // fstream Students("students.txt", ios::app | ios::in);
        if(iClearanceApprover.is_open()){
             while(iClearanceApprover >> fName >> lName >> ID >> pass){
                if(idInput == ID){
                    userFound = true;
                    break;
                }
             }
        }
        if(userFound){
            ofstream temp("temp.txt");
            system("cls");
            char ch;
            cout << "\n Are you sure you want to delete " << fName << " with id number " << ID << " from the system (Y/n)? ";
            cin >> ch;
            if(ch == 'y' || ch == 'Y'){
            if(iClearanceApprover.is_open()){
                while(iClearanceApprover >> fName >> lName >> ID >> pass){
                    if(idInput == ID) continue;
                    temp << fName << " " << lName << " " << ID << " " << pass << "\n";
                }
                
            } else {
                cout << " Error opening students for reading";
            }
            // Deleting the old students.txt and renaming temp.text to students.txt after the selected user has been deleted
            iClearanceApprover.close();
            temp.close();
            
            remove("clearanceApprovers.txt");
            rename("temp.txt", "clearanceApprovers.txt");

            cout << "\n\033[1;32m The clearance approver is deleted from the system successfully\033[0m\n\n";
            system("pause");
            goto label;
            } else {
            goto label;
            }
        } else {
        cout << "\n\033[1;31m User not found with the entered id\033[0m\n\n";
        system("pause");
        goto label;
            }
    } else {
        system("cls");
        return;
    }

}
void loading() {
    const char* spinner = "|/-\\";
    int i = 0;
    int num_spins = 10;
    clock_t start_time = clock();

    for (int j = 0; j < num_spins; j++) {
        while ((clock() - start_time) / (CLOCKS_PER_SEC / 8) < 1);
        start_time = clock();
        cout << "\r" << spinner[i % 4];
        cout.flush();
        i++;
    }
}

/*
	C++11 or above is required to run this program.
*/
