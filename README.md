Contact Managementer This project is a Contact Managementer implemented in C++. It allows users to manage their contacts efficiently by providing various features such as adding, removing, updating, and searching contacts. It also supports saving and loading contacts from a text file, making it easy to persist data between sessions.

Features :
Add Contact: Add a new contact with details such as first name, last name, classification, email and validate it, phone number and validate it, and address .

Remove Contact: Remove a contact by specifying the first name.

Search Contact: Search for contacts by last name or classification.

Display All Contacts: View all contacts in the system.

Display Favorite Contacts: View only the contacts marked as favorites.

Save to File: Save all contacts to a text file (filee.txt).

Load from File: Load contacts from a previously saved text file (filee.txt).

Update Contact: Update the details of an existing contact by specifying the contact's ID.

Reverse Contact List: Reverse the order of the contact list.

Project Structure The project is organized into the following files:

address.h : Contains the Address class, which manages the address details (street, city, country, etc.) of a contact.

person.h : Contains the person class, which represents a contact with attributes like name, email, phone, address, and favorite status.

darray.h  : Contains the Dynamic Array template class, which manages a dynamic array of contacts and provides functionalities like adding, removing, searching, and updating contacts.

main.cpp: The main program that provides a menu-driven interface for interacting with the contact management system.

contacts.txt: A text file used to store and load contact data.

Contacts can be saved to and loaded from the filee.txt file.

Dependencies : Standard C++ libraries (, , , , etc.).
