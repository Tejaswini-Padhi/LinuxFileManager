# Stage 5: Testing, Integration & Improvement

## 1. Testing Approach

Each feature of the Linux File Management Utility was tested individually after implementation.

The program was compiled using the GNU G++ compiler and executed in Ubuntu Linux through WSL2.

## 2. Feature Testing

| Test | Operation | Result |
|---|---|---|
| 1 | List files and directories | Passed |
| 2 | Create a file | Passed |
| 3 | Delete a file | Passed |
| 4 | Rename a file | Passed |
| 5 | Copy a file | Passed |
| 6 | Move a file | Passed |
| 7 | Search for a file | Passed |
| 8 | Display file information | Passed |

## 3. Testing Performed

### List
Verified that the program correctly displayed files in the project directory.

### Create
Created `test.txt` successfully.

### Delete
Deleted `test.txt` successfully.

### Rename
Renamed `main.cpp` to `program.cpp` and then restored it to `main.cpp`.

### Copy
Copied `program.cpp` to `backup.cpp` successfully.

### Move
Moved `backup.cpp` to `moved.cpp` successfully.

### Search
Successfully searched for `program.cpp`.

### File Information
Successfully displayed the name, path, type and size of `program.cpp`.

## 4. Issues and Improvements

During testing, the program was checked for common invalid operations such as missing files and existing destination files.

Error handling was added using filesystem checks and exception handling to make the program more reliable.

## 5. Final Testing Result

All eight implemented features successfully passed the basic functional tests.

The program was able to perform the planned file management operations without crashing during testing.
