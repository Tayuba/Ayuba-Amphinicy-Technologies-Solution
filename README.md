# Ayuba-Amphinicy-Technologies-Solution
# Library Management System

## Project Overview
The **Library Management System** is a C++ application that allows users to manage a collection of books. Users can perform operations such as adding, deleting, searching, and borrowing books. This project is structured for development in **Visual Studio Code** and is built using **CMake**.

## Workspace Structure
The project workspace is named:
**`AYUBA-AMPHINICY-TECHNOLOGIE-SOLUTIONS`**

###  Project Directory Structure
```
AYUBA-AMPHINICY-TECHNOLOGIE-SOLUTIONS/
│── src/                         # Source files
│   ├── Book_Interface.cpp
│   ├── Library_Interface.cpp
│   ├── Storage_Interface.cpp
│
│── include/                     # Header files
│   ├── Book_Interface.hpp
│   ├── Constant_Interface.hpp
│   ├── Library_Interface.hpp
│   ├── Storage_Interface.hpp
│
│── data/                        # Data storage
│   ├── book_DB.txt              # Database file for book records
|
|── doc/                        # Data storage
│   ├── project_description.pdf # Describes the tasks to do
|   ├── Doxygen_Generated doc   
│
│── .vscode/                     # VS Code configuration
│   ├── launch.json              # Debugging configurations
│   ├── settings.json            # VS Code settings
│   ├── tasks.json               # Build task configurations
│
│── main.cpp                     # Main entry point of the application
│── CMakeLists.txt                # CMake configuration file
│── README.md                     # Project documentation
```

##  Cloning or Downloading the Project
You can set up this project by **cloning from GitHub** or **downloading it manually**.

### **Clone via GitHub** (Recommended)
```sh
# Open a terminal and run:
git clone https://github.com/YOUR_GITHUB_USERNAME/Library-Management-System.git
cd Library-Management-System
```

### **Download Manually**
1. Go to the **GitHub repository**.
2. Click **Code → Download ZIP**.
3. Extract the ZIP file.

---

## Setting Up the Project in VS Code
This project is configured and run **Visual Studio Code** and uses **CMake** for building and compiling, feel free to use Clion if that what you have.

### **Step 1: Install Prerequisites**
Before you proceed, ensure that you have the following installed:
- **C++ Compiler** (GCC, Clang, or MSVC)
- **CMake** (version 3.17 or later)
- **Visual Studio Code** (Latest version)
- **CMake Tools Extension for VS Code**

### **Step 2: Open the Project in VS Code**
1. Open **Visual Studio Code**.
2. Click **File → Open Folder...**.
3. Select the folder **`AYUBA-AMPHINICY-TECHNOLOGIE-SOLUTIONS`**.

### **Step 3: Configure .vscode/tasks.json and launch.json**
#### `tasks.json` (Defines build tasks for Debug and Release modes)
1. Open **VS Code** and navigate to `.vscode/tasks.json`.
2. Ensure the following configuration is set:
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Prepare Debug Build",
            "type": "shell",
            "command": "if not exist ./build mkdir build && cmake -B ./build -DCMAKE_BUILD_TYPE=Debug",
            "problemMatcher": [],
            "group": { "kind": "build", "isDefault": true }
        },
        {
            "label": "Build Debug",
            "type": "shell",
            "command": "cmake --build ./build --config Debug",
            "dependsOn": "Prepare Debug Build",
            "problemMatcher": [],
            "group": { "kind": "build", "isDefault": true }
        }
    ]
}
```
####  `launch.json` (Defines how the application runs in debug mode)
1. Open **VS Code** and navigate to `.vscode/launch.json`.
2. Ensure the following configuration is set:
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Run Book (Debug)",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/Debug/Book_Library.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "preLaunchTask": "Build Debug"
        }
    ]
}
```

### **Step 4: Configure CMake**
1. Open **CMakeLists.txt** and verify it contains:
```cmake
cmake_minimum_required(VERSION 3.17)
project(Book_Library)
set(CMAKE_CXX_STANDARD 20)
add_executable(Book_Library main.cpp src/Book_Interface.cpp src/Library_Interface.cpp src/Storage_Interface.cpp)
```

### **Step 5: Build the Project Using CMake**
To compile the project, run:
```sh
cmake --build ./build --config Debug
```
Or, using **VS Code Tasks**:
1. Open the **Command Palette** (**Ctrl + Shift + P**).
2. Search for **Tasks: Run Build Task**.
3. Select **Build Debug**.

### **Step 6: Run the Application**
After building, you can run the executable:
```sh
./build/Debug/Book_Library
```
Or, in Windows:
```sh
build\Debug\Book_Library.exe
```

Alternatively, use **VS Code Debugging**:
1. Open the **Run and Debug** panel (**Ctrl + Shift + D**).
2. Select **Run Book (Debug)**.
3. Click the **Start Debugging** button (**F5**).

---

##  Running the Application
Once the project is built, run the program using one of the following methods:
1. **Via terminal:**
   ```sh
   ./build/Debug/Book_Library
   ```
   *(On Windows, use `build\Debug\Book_Library.exe` instead.)*
2. **Via VS Code:**
   - Open **Run and Debug Panel** (**Ctrl + Shift + D**).
   - Select **Run Book (Debug)**.
   - Click **Start Debugging (F5)**.

---

## Troubleshooting
###  **CMake Errors**
**Solution:** Ensure CMake is installed and run:
```sh
cmake --version
```

###  **Cannot Open File ‘book_DB.txt’**
**Solution:** Ensure the `data/` directory exists and contains `book_DB.txt`.

###  **Execution Permission Denied**
**Solution:** If running on Linux/macOS, grant execution permissions:
```sh
chmod +x build/Debug/Book_Library
```

---

