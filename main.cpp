#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

using namespace std;
namespace fs = filesystem;

// 1. List files and directories
void listFiles() {
    cout << "\n--- Files and Directories ---\n";

    try {
        bool found = false;

        for (const auto& entry : fs::directory_iterator(".")) {
            found = true;

            if (entry.is_directory()) {
                cout << "[DIR]  ";
            }
            else {
                cout << "[FILE] ";
            }

            cout << entry.path().filename().string() << endl;
        }

        if (!found) {
            cout << "Directory is empty.\n";
        }
    }
    catch (const fs::filesystem_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// 2. Create a file
void createFile() {
    string filename;

    cout << "\nEnter filename: ";
    cin >> filename;

    if (fs::exists(filename)) {
        cout << "Error: File already exists.\n";
        return;
    }

    ofstream file(filename);

    if (file) {
        cout << "File created successfully.\n";
    }
    else {
        cout << "Error: Could not create file.\n";
    }
}

// 3. Delete a file
void deleteFile() {
    string filename;

    cout << "\nEnter filename to delete: ";
    cin >> filename;

    if (!fs::exists(filename)) {
        cout << "Error: File does not exist.\n";
        return;
    }

    if (fs::is_directory(filename)) {
        cout << "Error: Directory deletion is not supported.\n";
        return;
    }

    try {
        if (fs::remove(filename)) {
            cout << "File deleted successfully.\n";
        }
        else {
            cout << "Error: Could not delete file.\n";
        }
    }
    catch (const fs::filesystem_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// 4. Rename a file
void renameFile() {
    string oldName;
    string newName;

    cout << "\nEnter current filename: ";
    cin >> oldName;

    cout << "Enter new filename: ";
    cin >> newName;

    if (!fs::exists(oldName)) {
        cout << "Error: File does not exist.\n";
        return;
    }

    if (fs::exists(newName)) {
        cout << "Error: New filename already exists.\n";
        return;
    }

    try {
        fs::rename(oldName, newName);
        cout << "File renamed successfully.\n";
    }
    catch (const fs::filesystem_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// 5. Copy a file
void copyFile() {
    string source;
    string destination;

    cout << "\nEnter source filename: ";
    cin >> source;

    cout << "Enter destination filename: ";
    cin >> destination;

    if (!fs::exists(source)) {
        cout << "Error: Source file does not exist.\n";
        return;
    }

    if (fs::is_directory(source)) {
        cout << "Error: Only files can be copied.\n";
        return;
    }

    if (fs::exists(destination)) {
        cout << "Error: Destination file already exists.\n";
        return;
    }

    try {
        fs::copy_file(source, destination);
        cout << "File copied successfully.\n";
    }
    catch (const fs::filesystem_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// 6. Move a file
void moveFile() {
    string source;
    string destination;

    cout << "\nEnter source filename: ";
    cin >> source;

    cout << "Enter destination path: ";
    cin >> destination;

    if (!fs::exists(source)) {
        cout << "Error: Source does not exist.\n";
        return;
    }

    if (fs::exists(destination)) {
        cout << "Error: Destination already exists.\n";
        return;
    }

    try {
        fs::rename(source, destination);
        cout << "File moved successfully.\n";
    }
    catch (const fs::filesystem_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// 7. Search for a file
void searchFile() {
    string filename;

    cout << "\nEnter filename to search: ";
    cin >> filename;

    bool found = false;

    try {
        for (const auto& entry :
             fs::recursive_directory_iterator(
                 ".",
                 fs::directory_options::skip_permission_denied)) {

            if (entry.path().filename().string() == filename) {
                cout << "Found: " << entry.path() << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "File not found.\n";
        }
    }
    catch (const fs::filesystem_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// 8. Display file information
void fileInformation() {
    string filename;

    cout << "\nEnter filename: ";
    cin >> filename;

    if (!fs::exists(filename)) {
        cout << "Error: File does not exist.\n";
        return;
    }

    try {
        fs::path filePath(filename);

        cout << "\n--- File Information ---\n";
        cout << "Name: " << filePath.filename().string() << endl;
        cout << "Path: " << fs::absolute(filePath) << endl;

        if (fs::is_directory(filePath)) {
            cout << "Type: Directory" << endl;
        }
        else {
            cout << "Type: Regular File" << endl;
            cout << "Size: " << fs::file_size(filePath)
                 << " bytes" << endl;
        }
    }
    catch (const fs::filesystem_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Display menu
void showMenu() {
    cout << "\n====================================\n";
    cout << "   LINUX FILE MANAGEMENT UTILITY\n";
    cout << "====================================\n";

    cout << "1. List files and directories\n";
    cout << "2. Create file\n";
    cout << "3. Delete file\n";
    cout << "4. Rename file\n";
    cout << "5. Copy file\n";
    cout << "6. Move file\n";
    cout << "7. Search file\n";
    cout << "8. File information\n";
    cout << "0. Exit\n";

    cout << "------------------------------------\n";
    cout << "Enter your choice: ";
}

int main() {

    int choice;

    cout << "Welcome to Linux File Management Utility!\n";

    while (true) {

        showMenu();

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";

            cin.clear();
            cin.ignore(10000, '\n');

            continue;
        }

        switch (choice) {

            case 1:
                listFiles();
                break;

            case 2:
                createFile();
                break;

            case 3:
                deleteFile();
                break;

            case 4:
                renameFile();
                break;

            case 5:
                copyFile();
                break;

            case 6:
                moveFile();
                break;

            case 7:
                searchFile();
                break;

            case 8:
                fileInformation();
                break;

            case 0:
                cout << "\nExiting program...\n";
                return 0;

            default:
                cout << "\nInvalid choice. Please choose between 0 and 8.\n";
        }
    }

    return 0;
}
