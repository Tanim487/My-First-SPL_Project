# 🏥 Patient Management System.

## 📌 Overview
Welcome to the **Patient Management System**! This is a simple **console-based** program designed to help manage patient records efficiently. With this system, you can **add, search, update, list, and delete** patient details with ease. Built using **C programming**, it uses text files for data storage.

## ✨ Features
- **Add Patient** 📝 - Register a new patient with a unique ID.
- **Search Patient** 🔍 - Look up patient details by ID or name.
- **Update Patient** ✏️ - Modify existing patient records.
- **List Patients** 📋 - View all stored patient records.
- **Delete Patient** ❌ - Remove a patient’s data.
- **Login System** 🔐 - Basic authentication for system access.

## 📁 Project Structure
```
|-- main.c                  # The main program file
|-- Patientlist.txt         # Stores patient details
|-- id.txt                  # Keeps track of unique patient IDs
```

## 🛠 Technologies Used
- **Programming Language**: C
- **File Handling**: Stores patient records in text files.
- **Structs**: Organizes patient data efficiently.
- **Windows API**: Utilized for system operations (like clearing the screen).

## 🚀 How to Use
### 1️⃣ Start the Program
- The program begins with a **welcome screen** and a login prompt.
- Use these credentials to log in:
  ```
  Username: abc
  Password: abc
  ```
- Upon successful login, you’ll be presented with the **Main Menu**.

### 2️⃣ Choose an Option from the Menu
- **1. Add a Patient** 🏥
  - Enter the patient’s details (name, date of admission, contact, disease, and doctor).
  - The program will generate a unique **Patient ID**.
  - This information is saved in `Patientlist.txt`.
- **2. Search for a Patient** 🔎
  - Search by **ID** or **Name**.
  - If found, the patient’s details will be displayed.
- **3. Update Patient Details** ✍️
  - Enter the **Patient ID**.
  - Modify the details and save the changes.
- **4. View All Patients** 📄
  - Displays all stored patient records.
- **5. Delete a Patient** ❌
  - Enter the **Patient ID** to remove the record permanently.
- **6. Exit the Program** 🔚

## 🔧 How to Compile and Run
1. **Compile the Code**:
   ```sh
   gcc main.c -o patient_management_system
   ```
2. **Run the Program**:
   ```sh
   ./patient_management_system
   ```

## 📌 Example Patient Records (Stored in `Patientlist.txt`)
```
101 Abdul_Halim 18/12/24 1732883224 Fever Dr_Sharmin
102 Nasir_Uddin 10/11/2024 182832424 Diabetes Dr_Sharmin
```

## 👥 Team Members
- **Mobinul Islam Tanim** (0112230487)
- **Zareen Bushra** (0112230248)
- **Nowshin Nawar** (0112230331)

---
🚀 **We hope you find this project useful! Happy coding!** 😊

