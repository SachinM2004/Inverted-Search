# Inverted-Search

# 🔍 Inverted Search

A command-line **Inverted Search Engine** developed in **C** that indexes multiple text files and enables fast keyword-based searching using **Hash Tables** and **Linked Lists**.

---

## 📖 Overview

An Inverted Search is a data structure used by search engines to quickly locate documents containing a given word. Instead of searching every file sequentially, the application creates an index that maps each word to the files in which it appears along with the number of occurrences.

This project demonstrates the implementation of:

- Hash Tables
- Linked Lists
- Dynamic Memory Allocation
- File Handling
- Data Structures
- Modular Programming

---

## 🚀 Features

- Create an inverted index from multiple text files
- Search any word efficiently
- Display word occurrences in each file
- Save the database to a backup file
- Update the database from a backup file
- Avoid duplicate file entries while updating
- Handle collisions using linked lists
- Menu-driven interface

---

## 🛠 Technologies Used

- C Programming
- GCC Compiler
- Linux
- Hash Tables
- Linked Lists
- Dynamic Memory Allocation
- File Handling



## ⚙️ Working

### Step 1: Validation

- Validates command-line arguments
- Checks file existence
- Avoids duplicate file names

### Step 2: Create Database

- Reads each text file
- Extracts every word
- Calculates hash index
- Creates Main Node
- Creates Sub Nodes
- Stores file name and word count

### Step 3: Display Database

Displays

- Hash Index
- Word
- File Count
- File Names
- Word Frequency

### Step 4: Search

Searches a given word and displays

- Word
- Number of files
- File names
- Occurrence count

### Step 5: Save Database

Stores the complete database into a backup text file.

Example:

```
#5;hello;2;file1.txt;5;file2.txt;3;
```

### Step 6: Update Database

Loads the database from the backup file and reconstructs the complete hash table.

Already indexed files are removed from the file list to prevent duplicate indexing.



## 🧠 Hash Function


index = tolower(word[0]) % 97


The first character of each word determines the hash index.

Example

| Word | Index |
|------|------|
| Apple | a |
| Ball | b |
| Cat | c |

---

## 💻 Compilation

```bash
gcc *.c -o inverted_search
```

or

```bash
make
```

---

## ▶️ Execution

```bash
./inverted_search file1.txt file2.txt file3.txt
```

---

## 📷 Sample Output

1.Create Database
2.Display Database
3.Search
4.Save Database
5.Update Database
6.Exit

Enter Choice: 1

Database created successfully.
```

Searching

```
Enter word: embedded

Word Found

Word        : embedded
File Count  : 2

file1.txt -> 5
file2.txt -> 3




## ⏱ Time Complexity

| Operation | Complexity |
|------------|------------|
| Create Database | O(N) |
| Search | O(1) Average |
| Display | O(N) |
| Save | O(N) |
| Update | O(N) |



## 📚 Data Structures Used

- Hash Table
- Singly Linked List
- Dynamic Memory Allocation

---

## 🎯 Learning Outcomes

This project helped me understand:

- Hashing techniques
- Collision handling
- Linked list manipulation
- File parsing
- Dynamic memory management
- Modular programming
- Searching algorithms
- Database serialization and restoration

---

## 🔮 Future Enhancements

- Case-insensitive searching
- Phrase searching
- Delete a file from the database
- Ranking based on frequency
- Wildcard search
- GUI version
- Multithreaded indexing

---

## 👨‍💻 Author

**Sachin Maralabavi**

- Email: sachinmaralabavimaralabavi@gmail.com
- GitHub:
- LinkedIn: www.linkedin.com/in/sachin-maralabavi-94b871399

---

## ⭐ If you found this project useful, don't forget to star the repository!
