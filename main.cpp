#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string ID;
    string Name;
    string Address;
    string Phone_number;

    Student() {} // default constructor

    Student(string id, string name, string address, string phone_number) { // parameterised constructor
        ID = id;
        Name = name;
        Address = address;
        Phone_number = phone_number;
    }

    void display() {
        cout << "Enter ID: " << ID << endl;
        cout << "Enter Name: " << Name << endl;
        cout << "Enter Address: " << Address << endl;
        cout << "Enter Phone Number: " << Phone_number << endl;
    }
};

class TelephoneDirectory {
private:
    Student records[100];
    int recordCount = 0;

public:
    void showMainMenu();
    bool isIDExists(string id);
    void saveRecord(Student newStudent);
    void findRecord(string id);
    void addRecord();
    void updateRecord();
    void deleteRecord();
    void searchRecord();
    void showAllRecords();
};

bool TelephoneDirectory::isIDExists(string id) { // loops through the saved records and returns true if the record with same ID is found.
    for (int i = 0; i < recordCount; i++) {
        if (records[i].ID == id) {
            return true;
        }
    }
    return false;
}

void TelephoneDirectory::saveRecord(Student newStudent) { // Checks if directory is full and if it is full it will give an error Saves the new student to the array and then increments the record count.
    if (recordCount >= 100) {
        cout << "Error" << endl;
        return;
    }
    records[recordCount++] = newStudent;
    cout << "Record saved successfully!" << endl;
}

void TelephoneDirectory::findRecord(string id) { //finds record through looping if found it will show the entire details of the found ID and if not found then it will show the output record not found.
    bool found = false;

    for (int i = 0; i < recordCount; i++) {
        if(records[i].ID == id) {
            found = true;
            cout << "Record found!" << endl;
            cout << endl;
            cout << "Current Information is:" << endl;
            cout << "Record ID: " << records[i].ID << endl;
            cout << "Record Name: " << records[i].Name << endl;
            cout << "Record Address: " << records[i].Address << endl;
            cout << "Record Phone Number: " << records[i].Phone_number << endl;
            break;
        }
    }

    if (!found) {
        cout << "Record not found!" << endl;
    }
}

void TelephoneDirectory::addRecord() {
    char another = 'y';
    do {
        cout << "\nTelephone Directory: Insert Menu\n";
        string id, name, address, phone_number;

        cout << "Enter ID: ";
        cin >> id;

        if (isIDExists(id)) {
            cout << "Error: ID already exists!" << endl;
            break;
        }

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Address: ";
        getline(cin, address);

        cout << "Enter Phone Number: ";
        getline(cin, phone_number);

        Student newStudent(id, name, address, phone_number);
        saveRecord(newStudent);

        cout << "Add another record? (Y/N): ";
        cin >> another;

    } while (another == 'y');
}

void TelephoneDirectory::updateRecord() {
    char update = 'y';
    do {
        cout << "Telephone Directory: Update Menu" << endl;
        cout << "Enter ID to update: ";
        string searchId;
        cin >> searchId;

        int foundIndex = -1; //foundIndex is initialized to -1 (means "not found"), The loop goes through the array records which holds directory entries, If it finds a record where the ID matches the user input (searchId), it saves the index and breaks the loop.
        for (int i = 0; i < recordCount; i++) {
            if (records[i].ID == searchId) {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex == -1) { //If no matching ID is found, it will inform the user that the user is not found.
            cout << "Record not found!" << endl;
        } else {
            cout << "\nCurrent Information:" << endl;
            records[foundIndex].display();
            cout << endl;

            cout << "Enter New Information : " << endl;
            cout << endl;
            cin.ignore();

            string name, address, phone;
            records[foundIndex].Name = name;
            records[foundIndex].Address = address;
            records[foundIndex].Phone_number = phone;

            cout << "Record updated successfully!" << endl;
        }

        cout << "Update another record? (Y/N): ";
        cin >> update;
    } while (update == 'y' || update == 'Y');
}

void TelephoneDirectory::deleteRecord() {
   char choice;
    do {
        cout << "Telephone Directory: Delete Menu" << endl;
        cout << endl;

        string IdToDelete;
        cout << "Enter ID to delete: ";
        cin >> IdToDelete;

        bool found = false;
        for (int i = 0; i < recordCount; i++) {
            if (records[i].ID == IdToDelete) {
                found = true;

                cout << "Record Found" << endl;
                cout << "ID: " << records[i].ID << endl;
                cout << "Name: " << records[i].Name << endl;

                char confirm;
                cout << "Do you want to delete this record" << endl;
                cin >> confirm;

                if (confirm == 'y' || confirm == 'Y') {
                    for (int j = 0; j < recordCount - 1; j++) {
                        records[j] = records[j + 1];
                    }
                    recordCount--;
                    cout << "Record deleted successfully!" << endl;
                    cout << endl;
                } else {
                    cout << "Deletion Cancelled" << endl;
                }
                break;
            }
        }
        if (!found) {
            cout << "Record not found: ";
        }
        cout << "Delete another record? (Y/N): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
}

void TelephoneDirectory::searchRecord() {
    char choice;

    do {

        cout << "Telephone Directory: Search Menu" << endl;
        cout << endl;

        string searchId;
        cout << "Enter ID or Name to search: ";
        cin >> searchId;

        bool found = false;
        for (int i=0;i < recordCount; i++) {
            if (records[i].ID == searchId) {
                found = true;

                cout << "Record Found" << endl;
                cout << endl;

                cout << "ID: " << records[i].ID << endl;
                cout << "Name: " << records[i].Name << endl;
                cout << "Phone Number: " << records[i].Phone_number << endl;
                cout << "Address: " << records[i].Address << endl;
            }
        }
        if (!found) {
            cout << "Record not found!" << endl;
        }
        cout << "Do you want to find Another Record ? (Y/N)";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

}

void TelephoneDirectory::showAllRecords() {
    cout << "Telephone Directory: All Students";
    cout << endl;
    cout << endl;

    if (recordCount == 0) {
        cout << "Record not found!" << endl;
    }
    else {
        for (int i = 0; i < recordCount; i++) {

            cout << "Record #"<< i+1 << ": "<< endl;
            cout << endl;

            cout << "ID: " << records[i].ID << endl;
            cout << "Name: " << records[i].Name << endl;
            cout << "Phone Number: " << records[i].Phone_number << endl;
            cout << "Address: " << records[i].Address << endl;
        }
    }
    char choice;
    cout << "Press 'm' To Go To The Main Menu";
    cin >> choice;
}
int main () {
    TelephoneDirectory directory;
    int choice;
    do {
        cout << "***************************************\n";
        cout << "      Telephone Directory: Main Menu    \n";
        cout << "***************************************\n\n";

        cout << "1. Add New Student\n";
        cout << "2. Update Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Search Student\n";
        cout << "5. Show All Students\n";
        cout << "Enter your choice (1-5): ";

        cin >> choice;

        switch (choice) {
            case 1:
                directory.addRecord();
            break;

            case 2:
                directory.updateRecord();
            break;

            case 3:
                directory.deleteRecord();
            break;

            case 4:
                directory.searchRecord();
            break;

            case 5:
                directory.showAllRecords();
            default:
                cout << "\nInvalid choice! Please try again.\n";
            break;
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();

    } while(choice!=6);

    return 0;
}