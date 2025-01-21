//   ________  ________  ________  ___  ___  ___       ________  ________  ___  ___  _____ ______   ________  ________           _____ ______   ___  ___  ___  ___  ________  _____ ______   _____ ______   ________  ________     
//  |\   __  \|\   __  \|\   ___ \|\  \|\  \|\  \     |\   __  \|\   __  \|\  \|\  \|\   _ \  _   \|\   __  \|\   ___  \        |\   _ \  _   \|\  \|\  \|\  \|\  \|\   __  \|\   _ \  _   \|\   _ \  _   \|\   __  \|\   ___ \    
//  \ \  \|\  \ \  \|\ /\ \  \_|\ \ \  \\\  \ \  \    \ \  \|\  \ \  \|\  \ \  \\\  \ \  \\\__\ \  \ \  \|\  \ \  \\ \  \       \ \  \\\__\ \  \ \  \\\  \ \  \\\  \ \  \|\  \ \  \\\__\ \  \ \  \\\__\ \  \ \  \|\  \ \  \_|\ \   
//   \ \   __  \ \   __  \ \  \ \\ \ \  \\\  \ \  \    \ \   _  _\ \   __  \ \   __  \ \  \\|__| \  \ \   __  \ \  \\ \  \       \ \  \\|__| \  \ \  \\\  \ \   __  \ \   __  \ \  \\|__| \  \ \  \\|__| \  \ \   __  \ \  \ \\ \  
//    \ \  \ \  \ \  \|\  \ \  \_\\ \ \  \\\  \ \  \____\ \  \\  \\ \  \ \  \ \  \ \  \ \  \    \ \  \ \  \ \  \ \  \\ \  \       \ \  \    \ \  \ \  \\\  \ \  \ \  \ \  \ \  \ \  \    \ \  \ \  \    \ \  \ \  \ \  \ \  \_\\ \ 
//     \ \__\ \__\ \_______\ \_______\ \_______\ \_______\ \__\\ _\\ \__\ \__\ \__\ \__\ \__\    \ \__\ \__\ \__\ \__\\ \__\       \ \__\    \ \__\ \_______\ \__\ \__\ \__\ \__\ \__\    \ \__\ \__\    \ \__\ \__\ \__\ \_______\
//      \|__|\|__|\|_______|\|_______|\|_______|\|_______|\|__|\|__|\|__|\|__|\|__|\|__|\|__|     \|__|\|__|\|__|\|__| \|__|        \|__|     \|__|\|_______|\|__|\|__|\|__|\|__|\|__|     \|__|\|__|     \|__|\|__|\|__|\|_______|

//						Project 1 - Library Management System

#include <iostream>
#include <string>
using namespace std;

void libraryInit(bool borrow[], bool empty[], int capacity);
void titleChange(string title[], int pos);
void authorChange(string author[], int pos);
void addBook(string title[], string author[], int id[], bool empty[], int capacity);
void removeBook(bool empty[], bool borrow[], int pos);
void borrowBook(bool borrow[], int pos, int &borrowCount);
void returnBook(bool borrow[], int pos, int &borrowCount);
void updateBook(string title[], string author[], int pos);
int searchBook(int id[], bool empty[], int capacity, int bookId);
void bookStats(bool borrow[], int pos);
void displayLib(string title[], string author[], int id[], bool borrow[], bool empty[], int capacity);
void bookInfo(string title[], string author[], bool borrow[], int pos);
void mainMenu(string libname);

int main()
{
	//		Create variables to store LibName, LibStats, and take instructions and book ids for user
	string libName;
	int capacity{}, bookCount{}, borrowCount{};
	long long totalAdded{}, totalRemoved{};
	int bookId{}, pos{}, order{};
	
	//		Prompt the user to enter LibName and Capacity
	cout << "Enter your library name: ";
	getline(cin, libName);
	cout << "Enter your library book capacity: ";
	cin >> capacity;

	//		Creating the 5 library structure arrays
	string* title = new string[capacity];
	string* author = new string[capacity];
	int* id = new int[capacity];
	bool* borrowState = new bool[capacity];
	bool* emptyPlace = new bool[capacity];

	//		Initializing the library to make it empty and any incoming books available to borrow
	libraryInit(borrowState, emptyPlace, capacity);
	
	//		Looping the program until prompted to exit by user
	while (true)
	{
		order = 0;			// Clearing user instruction to take new one
		mainMenu(libName);
		cin >> order;		// Taking new instruction
		if (order != 1 && order != 2 && order != 11 && order != 12)			// if NOT: adding books, showing LibStats, and exiting instructions
		{
			if (bookCount > 0)		// The remaining instructions require the library to contain books
			{
				switch (order)
				{
				case 3:				// Removing a book
					cout << "Enter book ID: ";
					cin >> bookId;
					pos = searchBook(id, emptyPlace, capacity, bookId);
					if (pos >= 0)
					{
						removeBook(emptyPlace, borrowState, pos);
						bookCount--;
						totalRemoved++;
						cout << "Book removed successfuly\n";
					}
					else
						cout << "No book with such ID\n";
					cout << "Enter any number to continue: ";
					cin >> order;
					break;

				case 4:				// Borrowing a book
					cout << "Enter book ID: ";
					cin >> bookId;
					pos = searchBook(id, emptyPlace, capacity, bookId);
					if (pos >= 0)
					{
					borrowBook(borrowState, pos, borrowCount);
					}
					else
						cout << "No book with such ID\n";
					cout << "Enter any number to continue: ";
					cin >> order;
					break;
				case 5:				// Returning a book
					cout << "Enter book ID: ";
					cin >> bookId;
					pos = searchBook(id, emptyPlace, capacity, bookId);
					if (pos >= 0)
					{
						returnBook(borrowState, pos, borrowCount);
					}
					else
						cout << "No book with such ID\n";
					cout << "Enter any number to continue: ";
					cin >> order;
					break;

				case 6:				// Updating a book
					cout << "Enter book ID: ";
					cin >> bookId;
					pos = searchBook(id, emptyPlace, capacity, bookId);
					if (pos >= 0)
					{
						updateBook(title, author, pos);
						cout << "Book updated successfuly\n";
					}
					else
						cout << "No book with such ID\n";
					cout << "Enter any number to continue: ";
					cin >> order;
					break;

				case 7:				// Searching for a book
					cout << "Enter book ID: ";
					cin >> bookId;
					pos = searchBook(id, emptyPlace, capacity, bookId);
					if (pos >= 0)
					{
						cout << "Book position: " << pos << endl;
					}
					else
						cout << "No book with such ID\n";
					cout << "Enter any number to continue: ";
					cin >> order;
					break;

				case 8:				// Checking if a book is borrowed
					cout << "Enter book ID: ";
					cin >> bookId;
					pos = searchBook(id, emptyPlace, capacity, bookId);
					if (pos >= 0)
					{
						bookStats(borrowState, pos);
					}
					else
						cout << "No book with such ID\n";
					cout << "Enter any number to continue: ";
					cin >> order;
					break;

				case 9:				// Displaying the whole detailed library storage 
					displayLib(title, author, id, borrowState, emptyPlace, capacity);
					cout << "Enter any number to continue: ";
					cin >> order;
					break;

				case 10:			// Displaying one book details
					cout << "Enter book ID: ";
					cin >> bookId;
					pos = searchBook(id, emptyPlace, capacity, bookId);
					if (pos >= 0)
					{
						bookInfo(title, author, borrowState, pos);
					}
					else
						cout << "No book with such ID\n";
					cout << "Enter any number to continue: ";
					cin >> order;
					break;
				}
			}
			else					// The library is empty (Books required for the above instructions)
			{
				cout << "Library is empty\n";
				cout << "Enter any number to continue: ";
				cin >> order;
			}

		}
		else if (order == 1)		// Add one book
		{
			if (bookCount < capacity) // if the library is not full
			{
				addBook(title, author, id, emptyPlace, capacity);
				bookCount++;
				totalAdded++;
			}
			else
				cout << "Library is full\n";
			cout << "Enter any number to continue: ";
			cin >> order;
		}
		else if (order == 2)	// Add a book or more
		{
			int booksNumber;
			cout << "Enter number of books to add: ";
			cin >> booksNumber;
			if (booksNumber <= (capacity - bookCount))	// If there is enough space
			{
				for (int i = 1; i <= booksNumber; i++)
				{
					addBook(title, author, id, emptyPlace, capacity);
					bookCount++;
					totalAdded++;
				}
			}
			else
				cout << "Available places left: " << capacity - bookCount << endl;
			cout << "Enter any number to continue: ";
			cin >> order;
		}
		else if (order == 11)		// Display Library statistics
		{
			cout << "\n\t\tLibrary statuses\n";
			cout << "========================================\n\n";
			cout << "Library capacity: " << capacity << endl;
			cout << "Owned books: " << bookCount << endl;
			cout << "Stored books: " << bookCount - borrowCount << endl;
			cout << "Borrowed books: " << borrowCount << endl;
			cout << "Total ever added books: " << totalAdded << endl;
			cout << "Total ever removed books: " << totalRemoved << endl;
			cout << "\n========================================\n";
			cout << "Enter any number to continue: ";
			cin >> order;
		}
		else if (order == 12)	// Exiti
		{
			cout << "\n\t\t Goodbye\n";
			break;
		}
		else	  // If the entered instruction number is other than all of the above
			cout << "Invalid input, try again\n";
	}

}

void libraryInit(bool borrow[], bool empty[], int capacity)
{
	for (int i = 0; i < capacity; i++)
	{
		borrow[i] = false;
		empty[i] = true;
	}
}

void titleChange(string title[], int pos) // To access and change title, used by other functions
{
	string booktitle;
	cout << "Enter the book title: ";
	cin.ignore();
	getline(cin, booktitle);
	title[pos] = booktitle;
}

void authorChange(string author[], int pos) // To access and change authors, used by other functions
{
	string bookauthor;
	cout << "Enter the book author: ";
	//cin.ignore();
	getline(cin >> ws, bookauthor);
	author[pos] = bookauthor;
}

void addBook(string title[], string author[], int id[], bool empty[], int capacity)
{
	int bookID;
	for (int i = 0; i < capacity; i++)
	{
		if (empty[i])
		{
			cout << "Enter book ID: ";
			cin >> bookID;
			id[i] = bookID;
			titleChange(title, i);
			authorChange(author, i);
			empty[i] = false;
			cout << "Book position: " << i << endl;
			break;
		}
	}
}

void removeBook(bool empty[], bool borrow[], int pos)
{
	empty[pos] = true;
	borrow[pos] = false;
}

void borrowBook(bool borrow[], int pos, int &borrowCount)
{
	if (!borrow[pos])
	{
		borrow[pos] = true;
		borrowCount++;
		cout << "Book borrowed successfuly\n";
	}
	else
		cout << "The book is already borrowed\n";
}

void returnBook(bool borrow[], int pos, int& borrowCount)
{
	if (borrow[pos])
	{
		borrow[pos] = false;
		cout << "Book returned successfuly\n";
		borrowCount--;
	}
	else
		cout << "No borrowed book with such ID\n";
}

void updateBook(string title[], string author[], int pos)
{
	char ans;
	cout << "Title: " << title[pos] << endl << "Update title? (y/n)\n";
	cin >> ans;
	if (ans == 'y')
	{
		titleChange(title, pos);
		cout << "Title updated\n";
	}

	cout << "Author: " << author[pos] << endl << "Update author? (y/n)\n";
	cin >> ans;
	if (ans == 'y')
	{
		authorChange(author, pos);
		cout << "Author updated\n";
	}
}

int searchBook(int id[], bool empty[], int capacity, int bookId)
{
	for (int i = 0; i < capacity; i++)
	{
		if (id[i] == bookId && !empty[i])
		{
			return i;
		}
	}
	return -1;
}

void bookStats(bool borrow[], int pos)
{
	if (borrow[pos])
		cout << "The book is borrowed\n";
	else
		cout << "The book is available\n";
}

void displayLib(string title[], string author[], int id[], bool borrow[], bool empty[], int capacity)
{
	for (int i = 0; i < capacity; i++)
	{
		if (!empty[i])
		{
			cout << "ID: " << id[i] << endl;
			cout << "Position: " << i << endl;
			cout << "Title: " << title[i] << endl;
			cout << "Author: " << author[i] << endl;
			cout << "Status: ";
			bookStats(borrow, i);
			cout << "===============================\n";
		}
	}
}

void bookInfo(string title[], string author[], bool borrow[], int pos)
{
	cout << "Position: " << pos << endl;
	cout << "Title: " << title[pos] << endl;
	cout << "Author: " << author[pos] << endl;
	cout << "Status: ";
	bookStats(borrow, pos);
	cout << "===============================\n";
}

void mainMenu(string libname)
{
	cout << "\n\t\t" << libname << endl;
	cout << "===================================================\n";
	cout << "-> Enter 1 to add a book\n\n";
	cout << "-> Enter 2 to add more than a book\n\n";
	cout << "-> Enter 3 to remove a book\n\n";
	cout << "-> Enter 4 to borrow a book\n\n";
	cout << "-> Enter 5 to return a book\n\n";
	cout << "-> Enter 6 to update a book\n\n";
	cout << "-> Enter 7 to search for a book\n\n";
	cout << "-> Enter 8 to check book status\n\n";
	cout << "-> Enter 9 to display the whole storage\n\n";
	cout << "-> Enter 10 to check a book info\n\n";
	cout << "-> Enter 11 to display library statuses\n\n";
	cout << "-> Enter 12 to exit\n";
	cout << "===================================================\n";
}