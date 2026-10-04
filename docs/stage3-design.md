# Stage 3: System Design & Architecture

## 1. System Architecture

The project follows a simple menu-driven architecture.

User
  |
  v
Main Menu
  |
  +--> List Files
  +--> Create File
  +--> Delete File
  +--> Rename File
  +--> Copy File
  +--> Move File
  +--> Search File
  +--> File Information
  |
  v
Linux File System

## 2. Components

### Main Program
Controls the menu and receives the user's choice.

### File Listing
Uses the C++ filesystem library to display files and directories.

### File Operations
Handles creation, deletion, renaming, copying and moving of files.

### Search
Searches through directories recursively to find a specified filename.

### File Information
Displays the file name, path, type and size.

## 3. Data Structures

The project mainly uses:

- `std::string` for filenames and paths.
- `std::filesystem::path` for file paths.
- `std::filesystem::directory_iterator` for directory traversal.
- `std::filesystem::recursive_directory_iterator` for searching.

## 4. Program Flow

1. Start the program.
2. Display the main menu.
3. Accept the user's choice.
4. Call the corresponding function.
5. Perform the selected file operation.
6. Display the result.
7. Return to the main menu.
8. Exit when the user selects option 0.

## 5. Development Tools

- Ubuntu Linux
- WSL2
- C++
- GNU G++ compiler
- Nano editor
- Git/GitHub

## 6. Implementation Plan

The project was developed incrementally:

1. Created the basic C++ program.
2. Implemented file listing.
3. Added the menu system.
4. Implemented file creation and deletion.
5. Implemented rename, copy and move.
6. Implemented file search.
7. Implemented file information.
8. Tested each feature individually.
