// Class specification and implementation of linked list
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//******************************************************
// The ListNode creates a type used to store a node of *
// the linked list.                                    *
//******************************************************
template <class T>
class ListNode
{
public:
	T value;				// Node Value
	ListNode<T> *next;		// Pointer to the next node

	// Constructor
	ListNode(T nodeValue)
	{value = nodeValue;
		next = nullptr;}
};
template <class T>
class LinkedList
{
private:
	ListNode<T> *head;		// List head pointer

public:
	// Constructor
	LinkedList()
	{head = nullptr;}

	// Destructor
	~LinkedList();

	// Linked list operations
	void appendNode(T);
	void insertNode(T);
	void deleteNode(T);
	void displayList();
	void nodeToFile(string);
	string chooseFile(int);
};

//************************************************
// appendNode appends a node containing a value  *
// passed into newValue, to the end of the list. * 
//************************************************
template <class T>
void LinkedList<T>::appendNode(T newValue)
{
	ListNode<T> *newNode;	// To point to a new node
	ListNode<T> *nodePtr;	// To traverse the list 

	// Allocate a new node and store a value there. 
	newNode = new ListNode<T>(newValue);
	
	// If no node excists in the list make newNode the first node.
	if (!head)
		head = newNode;
	// Otherwise, insert newNode at the end.
	else
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node in the list
		nodePtr->next = newNode;
	}
}
//*****************************************************
// displayList shows the value stored in each node of *
// the linked list pointed to by head                 *
//*****************************************************
template <class T>
void LinkedList<T>::displayList()
{
	ListNode<T> *nodePtr;	// To traverse list

	// Postition nodePtr at the head of the list.
	nodePtr = head;

	// while nodePtr points to a node, traverse the list
	while (nodePtr)
	{
		// Display the value in this node.
		cout << nodePtr->value << endl;

		// Move to teh fallowing node
		nodePtr = nodePtr->next;
	}
}
//*********************************************************
// insertNode inserts a node with newValue copied to its *
// value member.                                          *
//*********************************************************
template <class T>
void LinkedList<T>::insertNode(T newValue)
{
	ListNode *newNode;		// A new Node
	ListNode *nodePtr;		// To traverse the list
	ListNode *previousNode = nullptr;	// The previous node

	// Allocate a new node and store newValue with in it.
	newNode = new ListNode;
	newNode->value = val;
	// If there are no nodes in the list make newNode the head.
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else // Otherwise, insert newNode.
	{
		// Position nodePtr at the head of the list. 
		nodePtr = head;

		// Initialze previousNode to nullptr.
		previousNode = nullptr;

		// Skip all nodes whose value is less than newValue.
		while (nodPtr != nullptr && nodePtr->value < newValue)
		{
			previousNode = nodePtr;
			nodeptr = nodePtr->next; 
		}
		// If the new node is to be the first in the list, insert
		// it at the head.
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else // Otherwise insert after the previous node.
		{
			previousNode->next = newNode;
			newNode->next = nodePtr
		}
	}
}
//*******************************************
// Destructor deletes every node in the list *
//*******************************************
template <class T>
LinkedList<T>::~LinkedList()
{
	ListNode<T> *nodePtr;		// To traverse the list
	ListNode<T> *nextNode;		// To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	while (nodePtr != nullptr)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delet the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}
//*************************************************************
// chooseFile accepts an integer num. It traverses the linked *
// list and returns the value in the node that is 1-num.      *
//*************************************************************
template <class T>
string LinkedList<T>::chooseFile(int num)
{
	// Declare local variable
	string File;	// Holds file name to be returned
	ListNode<T> *nodePtr;	// To traverse list

	// Postition nodePtr at the head of the list.
	nodePtr = head;

	// Traverse the list num-1 times
	for (int x = 0; x < num; x++)
	{
		// Move to the fallowing node
		nodePtr = nodePtr->next;
	}
	// set the nodePtr's value to File
	File = nodePtr->value;
	return File;
}
//**********************************************************
// deleteNode function searches for a node with seachValue *
// as its value. the node, if found, is deleted from the   *
// list and from memory.                                   *
//**********************************************************
template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
	ListNode<T> *nodePtr;							// To traverse the list
	ListNode<T> *previousNode = nullptr;			// TO point to the previous node

	// If the list is empty, do nothing.
	if (!head)
		return;
	
	// Determine if the first node is the one.
	if (head->value == searchValue)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all node whose values do not eqaul to searchvalue
		while (nodePtr != nullptr && nodePtr->value != searchValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		// If nodePtr is not at the end of the list, link the previous node
		// to the node after nodeptr, then delete nodePtr.
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

//**********************************************************
// nodeToFile accepts a string, the name of the file being *
// accesed. I writes each node of a list to that file.     *
// It adds $ at the end of each node for a marker in the   *
// file.                                                   *
//**********************************************************
template <class T>
void LinkedList<T>::nodeToFile(string fileName)
{
	fstream file(fileName, ios::out);
	string value;		// Holds value to be written to file

	ListNode<T> *nodePtr;	// To traverse the list

	// set nodePtr to head.
	nodePtr = head;

	// If file opened
	if (file)
	{
		// get value
		value = nodePtr->value;

		// While nodePtr still points to a value, continue.
		while (nodePtr != nullptr)
		{
			// Write value to file
			file << value + '$';

			// Move to the next node
			nodePtr = nodePtr->next;

			// If the nodePtr has not yet reached nullPtr, continue.
			if (nodePtr != nullptr)
			{

				// get value.
				value = nodePtr->value;
			}
		}
		// close file
		file.close();
	}

}
#endif // !LINKEDLIST_H

// Specification File for EnterGrades.h
#include <string>
#include <fstream>
#include "LinkedList.h"
#ifndef ENTERGRADES_H
#define ENTERGRADES_H
class enterGrades
{
private:
	// Create a list object
	LinkedList<string> list;
public:
	// Constructor
	enterGrades (){};

	// Class Functions
	void getFile(string);
	void getName();
	void fillList();
	void changedFiles(string);

	// Destructor
	~enterGrades() {};
};
#endif // !ENTERGRADES_H
// Implentaion of the enterGrades class
#include "EnterGrades.h"
#include "LinkedList.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
//**************************************************************************
// Definition of the getName member function. This function                *
// excepts an fstream object as its parameter. It opens the file           *
// and displays the file names for each students file. It uses a list      *
// for the user to select a file name. The getName function then calls     *
// the decryptFile function with the selected file name as the decryptFile *
// functions parameter.                                                    *
//**************************************************************************
void enterGrades::getName()
{
	// Declare local variables
	string file;	// To hold the selected file name
	string input;	// To hold the students name in the input file
	int selection; // To hold the selection in the switch
	int num = 1;   // To hold a number for the user to select
	// fstream for StudentNames file  
	fstream Name("StudentNames.txt", ios::in);

	// If file was successfully opened
	if (Name)
	{
		// Prompt user to enter a character to access a students file
		cout << "Enter the number that appears next to a students name to access their file.\n";
		cout << num << ": ";
		// Read Items using $ as a delimiter
		getline(Name, input, '$');

		// While the last read operation was successful, continue.
		while (Name)
		{
			// Display the last item read.
			cout << input << endl;

			// Read Items using $ as a delimiter
			getline(Name, input, '$');

			if (Name)
			{
				// Add one to num
				num += 1;

				// Display new number before the name
				cout << num << ": ";
			}
		}
		// Close the file.
		Name.close();
	}
	else
		cout << "Error: connot open file.\n";

	cout << "Enter the number to access the selected student file.\n";
	cin >> selection;

	// Ensure selection is valid
	while (selection < 1 && selection > num)
	{
		cout << "Error; invalid selction please enter an integer from 1 to " << num << endl;
		cin >> selection;
	}
	// Call fillList to add nodes to the list
	fillList();

	// Call chooseFile function with selection as its parameter
	file = list.chooseFile(selection - 1); 
	
	// call getFile function with file as its parameter
	getFile(file);
}
//*****************************************************************************
// fillList function opens the studentFiles file. It gets one line at a time. *
// Each string from each line is placed into a node in a linked list.         *
//*****************************************************************************
void enterGrades::fillList()
{
	// Declare local variables
	string input; 
	// fstream for StudentFiles file
	fstream File("StudentFiles.txt", ios::in);

	// Open File.
	//File.open;

	// If File was successfully opend 
	if (File)
	{
		// Read Items using $ as a delimiter
		getline(File, input, '$');

		// While the last read operation was successful, continue.
		while (File)
		{
			
				// Insert input into a node
				list.appendNode(input);

			// Read next line using $ as a delimiter
			getline(File, input, '$');
		}
		// close the file
		File.close();
	}
	else
		cout << "Error: connot open file.\n";
}
//************************************************************************
// the getFile function has a string as its parameter. The string is     *
// used to open the coensiding file. The getFile function opens the file *
// in output. It finds the end of the file and prompts the user to enter *
// the needed information for entering that student grade.               *
//************************************************************************
void enterGrades::getFile(string name)
{	
	// Declare local variable
	string entered;		// Holds entered information

	// Create an fstream object 
	fstream file(name, ios::app);

	
	// If the file opend properly
	if (file)
	{
		// Prompt the user to enter the needed information
		cout << "Enter the fallowing information for the grade earned by this student:\n"
			<< "Name of class: ";
		cin >>  entered;
		file << "Subject: " + entered + '\n';
		cout << "Number of credits earned: ";
		cin >> entered;
		file << "credits awarded: " + entered + '\n';
		cout << "Letter grade earned: ";
		cin >> entered;
		file << "Grade earned: " + entered + '\n';
		cout << "Date earned: ";
		cin >> entered;
		file << "submitted on " + entered + '\n';
		cout << "Grader's employee number: ";
		cin >> entered;
		file << "Teacher #: " + entered + '\n' + '\n';

		// Close the file
		file.close();
	}
	else
		cout << "Error file did not open correctly.\n";

	// Call changedFile function to indecate this file has been manipulated
	changedFiles(name);

}
//**********************************************************************
// The changedFile function accepts a string as it's argument.         *
// The string is the name of the file that was changed by the teacher. *
// It opens a file called changed. The function inserts the file name  *
// into the end of the changed file.                                   *
//**********************************************************************
void enterGrades::changedFiles(string name)
{
	// Local variable declaration
	string input;		// To hold string from changed file 
	bool exsists =false;		// Holds a true false if file exsists
	// Create fstream to open Changed.txt
	fstream file("Changed.txt", ios::in);

	if (file)
	{
		// Read first line
		getline(file, input, '$');

		// While last read operation was successful
		while (file)
		{
			// Compare input to name
			if (name != input)
			{
				// Read next line
				getline(file, input, '$');
			}
			else if (name == input)
			{
				exsists = true;
				break;
			}
		}
		file.close();
	}
	else
		cout << "changed.txt did not open for input.\n";

	if (!exsists)
	{
		// Recreate and open file to append mode.
		fstream afile("changed.txt", ios::app);
		// If the file is open
		if (afile)
		{
			// Write name to file and add identifier $
			afile << (name + '$');

			// Close file
			afile.close();
		}
		else
			cout << "Changed.txt did not open.\n";
	}
}

// Specification file for GetGrades.h
#include <string>
#include <fstream>
#include "LinkedList.h"
#ifndef GETGRADES_H
#define GETGRADES_H
class getGrades
{
private:
	// Create two list objects 
	LinkedList<string> changedList, grades;
	int accessNumber = 24;		// ID validation number
public:
	// Constructor
	getGrades() {};

	// Class Functions
	bool checkID(int, int);
	void listOfChanged();
	void getData(int);
	void displayData(string);
	void clearChanged();
	void addStudent();
	void removeStudent();

	// Destructor
	~getGrades() {};

};

#endif // !GETGRADES_H
// Implentaion of the GetGrades class
#include "GetGrades.h"
#include "LinkedList.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
//**************************************************************************
// Definition of checkID class function. A recursive function that         *
// accepts two integers as its parameters. One that is the I.D. number     *
// that the function will validate. If the I.D. is valid the function      *
// returns a true value. If the value is false the function uses recursion *
// to give the user three more attempts to enter the correct I.D. number.  *
// If the second parameter which is a number the itterates every time the  *
// function recurs reaches 4 the checkID function returns false.           *
//**************************************************************************
bool getGrades::checkID(int ID, int Tries)
{
	// Declare local variables
	bool correct = false;	// Returns true if ID matches
	int entered;			// Holds new entered value

	// If I.D. is correct
	if (ID == accessNumber)
	{
		correct = true;
		return correct;
	}
	else if (ID != accessNumber && Tries < 4)
	{
		cout << "That was an incorrect access number. Please enter your account access number.";
		cin >> entered;
		checkID(entered, Tries + 1);
	}
	else
		return correct;
}
//*************************************************************************
// listOfChanged class function uses an fstream to open the changed file. *
// It then calls the appendNode function of the linked list to create a   *
// list containing each file that has been changed from the last time it  *
// had been checked.                                                      *
//*************************************************************************
void getGrades::listOfChanged()
{
	// Create fstream to open Changed.txt
	fstream file("Changed.txt", ios::in);
	string input;		// Holds the line extracted from the file
	int numFiles = 0;	// Holds the number of files that need to be checked

	// If file opened continue
	if (file)
	{
		// Read Items using $ as a delimiter
		getline(file, input, '$');
		// While the last read operation was successful, continue.
		while (file)
		{
			// Insert input into a node
			changedList.appendNode(input);
			// Read next line using $ as a delimiter
			getline(file, input, '$');
			
			cout << input << endl;// <--- driver
			// Iterate numFiles
			numFiles++;
		}
		// close the file
		file.close();

		// call getData function
		getData(numFiles);
	}
	else
		cout << "Error: connot open file.\n";
}
//****************************************************************************
// getData class function accepts an integer value as its parameter.         *
// The int value is used in a for loop. It calls the chooseFile LinkedList   *
// function. It then uses the returned value to as the parameter to call the *
// displayData function.                                                     *
//****************************************************************************
void getGrades::getData(int num)
{
	// Declare local variable
	string name;	// Holds value in current node value

	for (int x = 1; x <= num; x++)
	{
		// Call chooseFile function
		name = changedList.chooseFile(x - 1);

		// Call displayData function 
		displayData(name);
	}
	// call the clear changed file
	clearChanged();
}
//*****************************************************************************
// displayData class function accepts a string as its parameter, name,        *
// name is set in a fstream object. the file is read from name  and displayed *
// in blocks of entered information. It has a hold to wait for the user to    *
// finish gathering the information from the file.                            *
//*****************************************************************************
void getGrades::displayData(string name)
{
	// Declare local variables
	char hold;		// pauses the program for the user
	char ch;		// Holds read character
	string input;	// Holds line of chars
	fstream file(name, ios::in);

	// If file opened
	if (file)
	{
		cout << "The Students File is:\n" << name << endl;
		// Get character
		file.get(ch);

		// While the last read operation was successful, continue.
		while (file)
		{
			// Display last character
			cout << ch;
			
			// Read next character
			file.get(ch);
		}
		// Close active file
		file.close();

		// Pause for user
		cout << "Press any key then press enter when you are ready to continue the program.\n";
		cin >> hold;
	}
	else
		cout << name << " could not be be opend.\n";
}
//***********************************************************************
// clearChanged class function uses a fstream to open the changed file. *
// it turncates all the data within the changed file.                   *
//***********************************************************************
void getGrades::clearChanged()
{
	fstream file("Changed.txt", ios::out, ios::trunc);
	file.close();
}
//***************************************************************************
// addStudent class function prompts the user to enter a students name.     *
// It then, using fstreams, opens the studentName file and the studentFile. * 
// It then writes tthe entered data into the opened files.                  *
//***************************************************************************
void getGrades::addStudent()
{
	// Declare local variables
	string entered;	// Holds the entered name of the new student
	string input;	// Holds line read into program
	fstream name("StudentNames.txt", ios::in),
		file("StudentFiles.txt", ios::in);

	// Create two list objects
	LinkedList<string> nameList, fileList;		// nodes contain meterail read from files

	// Print drvier note.
	cout << "Note; becouse this driver is being sent over email the code will not a student file to the executable\n"
		<< "for this project. In a network enviroment the new student's file would be located in a shared file\nthat could be accessed"
		<< "via that file. To demonstrait this driver please remove a\nstudent's and then add it back into the program. This way the file/n"
		<< "already be in the resource files of this program.\n\n";

	// Prompt the user to enter new name.
	cout << "Enter the name of the new student with no spaces or commas example: JohnDoe\n"
		<< "Please enter new student's name as shown above: ";
	cin >> entered;

	// if name opened 
	if (name)
	{
		// Read Items using $ as a delimiter
		getline(name, input, '$');

		// Append input into nameList
		nameList.appendNode(input);

		// While the last read operation was successful, continue.
		while (name)
		{
			// Read Items using $ as a delimiter
			getline(name, input, '$');

			if (name) // if the file hasn't hit Null
			{
				// Insert input into a node
				nameList.appendNode(input);
			}
		}
		name.close();	// close name
	}
	else
		cout << "Erorr: File did not open.";

	// Append entered to the a new node in the list
	nameList.appendNode(entered);

	// call nodeToFile to write the updated file
	nameList.nodeToFile("StudentNames.txt");

	//Update studentFile file
	if (file)
	{
		// Read Items using $ as a delimiter
		getline(file, input, '$');

		// Append input into nameList
		fileList.appendNode(input);

		// While the last read operation was successful, continue.
		while (file)
		{

			// Read Items using $ as a delimiter
			getline(file, input, '$');

			if (file) // if the file hasn't hit Null
			{
				// Insert input into a node
				fileList.appendNode(input);
			}
		}
		// Close the file.
		file.close();
	}
	else
		cout << "Error: connot open file.\n";

	// Use name plus strings made up of file location
	// to call appendNode list function
	fileList.appendNode(entered + ".txt");

	// call nodeToFile to write updated file
	fileList.nodeToFile("StudentFiles.txt");
	
	// Explain to user what program just accomplished
	cout << entered << " has been added to the StudentFiles file.\n";
}
//************************************************************************
// removeStudent class function prompts the user to enter a students     *
// name it then seeks that name out and removes it from the studentsName *
// and the studentsFeile files.                                          *
//************************************************************************
void getGrades::removeStudent()
{
	// Declare local variables
	string name;		// Holds name
	string input;		// Holds lines from files
	int entered;		// holds number for entered name
	int num = 1;		// Holds number for iterations
	//bool validName = false;		// Holds true if entered is a valid name

	fstream sName("StudentNames.txt", ios::in),
		sFile("StudentFiles.txt", ios::in);

	// Create two list objects
	LinkedList<string> nameList, fileList;		// nodes contain meterail read from files

	if (sName)
	{
		// Prompt user to enter a character to access a students file
		cout << "Enter the number that appears next to a students name to remove their file.\n";
		cout << num << ": ";
		// Read Items using $ as a delimiter
		getline(sName, input, '$');

		// Append input into nameList
		nameList.appendNode(input);

		// While the last read operation was successful, continue.
		while (sName)
		{
			// Display the last item read.
			cout << input << endl;

			// Read Items using $ as a delimiter
			getline(sName, input, '$');

			if (sName) // if the file hasn't hit Null
			{
				// Add one to num
				num += 1;

				// Display new number before the name
				cout << num << ": ";

				// Insert input into a node
				nameList.appendNode(input);
			}
		}
		// Close the file.
		sName.close();
	}
	else
		cout << "Error: connot open file.\n";
	
	// Prmopt user to identify student they want to remove
	cout << "Enter the number that is next to the students name that you want to remove.\n";
	cin >> entered;

	// call choose file to get the string value
	name = nameList.chooseFile(entered - 1);
	
	// Use name to call deleteNode list function
	nameList.deleteNode(name);

	// Write the new list to the name file
	nameList.nodeToFile("StudentNames.txt");

	// Now remove the student's file from the StudentsFile file

	if (sFile)
	{
		// Read Items using $ as a delimiter
		getline(sFile, input, '$');

		// Append input into nameList
		fileList.appendNode(input);

		// While the last read operation was successful, continue.
		while (sFile)
		{

			// Read Items using $ as a delimiter
			getline(sFile, input, '$');

			if (sFile) // if the file hasn't hit Null
			{
				// Insert input into a node
				fileList.appendNode(input);
			}
		}
		// Close the file.
		sFile.close();
	}
	else
		cout << "Error: connot open file.\n";

	// Use name plus strings made up of file location
	// to call deleteNode list function
	fileList.deleteNode(name + ".txt");

	fileList.nodeToFile("StudentFiles.txt");

	cout << name << " has been removed from studentFiles file.\n";
}
/*PROGRAM:  GradeTracker.cpp
Written by Trevor Evans
This program keeps track of the grades entered
 by teachers and opens the correct files to store 
 their entered information. It also serves as an access
 point to those files for the secritary entering the grades
 into transcript.
Written on March 15, 2016*/
#include "EnterGrades.h"
#include "GetGrades.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

// Function declaration
void teachers();
void secretary();

int main()
{
	
	char selection;		// Holds the users selection

		cout << "How do you plan on using this system?\n"
			<< "Enter (T) if you are a teacher\n"
			<< "or (S) if you are a secretary: ";
		cin >> selection;

		// validate selection
	while (selection != 't' && selection != 's' &&
		selection != 'T' && selection != 'S')
	{
		cout << "Error you entered a character that wasn't an option.\n"
			<< "Please enter (T) if you are a teacher\n"
			<< "or (S) if you are a secretary: ";
		cin >> selection;
	}

	// Call teachers function if selection = T
	if (selection == 't' || selection == 'T')
		teachers();
	else if (selection == 's' || selection == 'S')  // if selection = S
		secretary();

	return 0;
}
//**********************************************************************
// Definition of the teacher function. It creates an enterGrades class *
// object and calls the enterGrades class function getName.            *
//**********************************************************************
void teachers()
{
	// Create an enterGrades object
	enterGrades student;

	// Call the getName function
	student.getName();
}
//*****************************************************************************
// Definition of the secretary function. It creates a getGrades object.       *
// It then validates the users I.D. number by calling the checkID class       *
// function. It then gives the option to view all updated files, add students *
// files, or remove student files. Once a selction is made it calls the       *
// corresponding class functions.                                             *
//*****************************************************************************
void secretary()
{
	// Declare local variables
	int IDNum;		// Holds entered ID number
	bool valid;		// Holds true if check ID returns true
	char need;		// Holds need identified by user
	char entered;	// Holds value wether adding or deleting student
	// Create a getGrades object
		getGrades grades;
	// Prompt user to enter id number
	cout << "Please enter your work ID number.\n";
	cout << "Note for this driver the access number is 24: ";
	cin >> IDNum;

	// Validate ID with checkID function
	valid = grades.checkID(IDNum, 0);

	if (valid == true) // If true continue running program.
	{
		// Prompt the user to identify their need
		cout << "Please select an option.\n"
			<< "Enter (R) if you're retrieveing data.\n"
			<< "Enter (C) if you are making a change to the roll: ";
		cin >> need;

		// Varify that data is good
		while (need != 'R' && need != 'C' &&
			need != 'r' && need != 'c')
		{
			cout << need << " was a ninvalid entery.\n"
				<< "please enter R if you wish to retrieve data,\n"
				<< "or enter C if you wish to change the roll: ";
			cin >> need;
		}
		// In the case the user wants to retrieve data
		if (need == 'R' || need == 'r')
		{
			cout << "Here is the data that has changed since you last checked:\n\n";

			// Call the listOfChanged function to run
			// through the coresponding getGrade functions.
			grades.listOfChanged();
		}
		else if (need == 'C' || need == 'c')
		{
			// Prompt user to indecate if they are adding or removing student file
			cout << "Are you adding or are you removing a student's file?\n"
				<< "Enter (A) if you are adding a student\n"
				<< "Enter (R) if you are removing a student's file: ";
				cin >> entered;

				// Validate entery
				while (entered != 'A' && entered != 'R' && entered != 'a'
					&& entered != 'r')
				{
					cout << entered << " is invalid. Please enter (R) to remove a student's file or (A) to add a file: ";
					cin >> entered;
				}

				// If add was selected call the addStudent member function
				if (entered == 'A' || entered == 'a')
					grades.addStudent();
				else if (entered == 'R' || entered == 'r')
					grades.removeStudent();
		}
	}
	else // If false end program.
	{
		cout << "Sorry the entered Credentials were invalid please contact your supervisor\n"
			<< " to confirm your access number.\n"
			<< "Program terminating.";
		exit(EXIT_FAILURE);
	}
}

