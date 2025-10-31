# ☎️ Telephone Directory System for Students  

## 🧾 Overview
The **Telephone Directory System for Students** is a **console-based C++ application** designed to manage student contact records efficiently.  
It demonstrates **Object-Oriented Programming (OOP)** concepts such as **classes, constructors, encapsulation**, and **data manipulation** using arrays.

This project is perfect for **CS students** learning about **OOP**, **menu-driven systems**, and **basic CRUD (Create, Read, Update, Delete)** operations in C++.

---

## 🚀 Features
✅ Add new student records  
✅ Update existing records by ID  
✅ Delete a record permanently  
✅ Search for a student by ID or name  
✅ Display all stored student records  
✅ Prevent duplicate entries using ID verification  
✅ Simple and interactive menu-driven interface  

---

## ⚙️ Technologies Used
| Component | Description |
|------------|--------------|
| **Language** | C++ |
| **Concepts** | OOP (Encapsulation, Classes, Objects, Constructors) |
| **Storage** | In-memory Array (No external database or file handling) |
| **Libraries** | `<iostream>`, `<string>` |

---

## 🧱 Class Structure

### 🎓 `Student` Class
Represents a single student’s record containing:
- `ID`
- `Name`
- `Address`
- `Phone_number`

Includes:
- Default and parameterized constructors  
- `display()` function to show student info  

---

### 📇 `TelephoneDirectory` Class
Handles management of student records with:
- `records[100]` → array to store up to 100 students  
- `recordCount` → keeps track of stored entries  

Key Methods:
| Method | Description |
|--------|--------------|
| `isIDExists(string id)` | Checks if an ID already exists |
| `saveRecord(Student newStudent)` | Adds a new student to the directory |
| `findRecord(string id)` | Displays details for a given ID |
| `addRecord()` | Interactive record insertion |
| `updateRecord()` | Modifies student details using ID |
| `deleteRecord()` | Removes a student record |
| `searchRecord()` | Finds a record by ID or name |
| `showAllRecords()` | Lists all stored students |

---


