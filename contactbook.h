#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED
#include <iostream>
#include <string>
#include"darray.h"
#include "Address.h"
#include"person.h"
using namespace std;
#define table cout << left << setw(25) << setfill(' ')

#define equals cout << "======================================================================================================================================================================================\n";
#define nice cout <<setw(37)<<"=";
#define decore cout <<"==================================================================\n";
#define equalsinfile << "======================================================================================================================================================================\n";

class contact
{
private:
    Darray<person> contacts;


public:

    void AddContact( person& p)
    {
        contacts.append(p);
    }
    int getContactSize() const
    {
        return contacts.getSize();
    }
    void deleteContact(int index)
    {
        if (index >= 0 && index < contacts.getSize())
        {
            contacts.remove(index);
        }
        else
        {
            cout << "Invalid index!" << endl;
        }
    }
    void printFavoriteContacts()
    {
        bool f=0;
        int j=1;
        for (int i = 0; i < contacts.getSize(); ++i)
        {
            if (contacts[i].isFavorite())
            {
                if(!f)
                {
                    equals
                    table << "ID" ;
                    table <<"FName"  ;
                    table<<"LName";
                    table <<"Classification";
                    table << "Favorite";
                    table<<"Address";
                    table<<"Phone Number";
                    cout<<"\n";
                    equals
                }
                f=1;
                table<<j;
                j++;
                contacts[i].getInfo() ;

            }
        }
        equals
    }
    void searchByLastName(const string& lastName)
    {
        int j=1;
        bool f=0;
        bool found=0;
        for (int i = 0; i < contacts.getSize(); ++i)
        {
            if (contacts[i].getLastName() == lastName)
            {
                if(!f)
                {
                    equals
                    table << "ID" ;
                    table <<"FName"  ;
                    table<<"LName";
                    table <<"Classification";
                    table << "Favorite";
                    table<<"Address";
                    table<<"Phone Number";
                    cout<<"\n";
                    equals
                }
                table<<j;
                j++;
                contacts[i].getInfo();
                found=1;
                f=1;
            }
            if(found)equals
            }
        if(!found)cout << "No contact found with that last name.\n";
    }
    void searchByClassification(const string& classification)
    {
        bool f=0;
        bool found=0;
        for (int i = 0; i < contacts.getSize(); ++i)
        {
            int j=1;
            if (contacts[i].getClassification() == classification)
            {
                if(!f)
                {
                    equals
                    table << "ID" ;
                    table <<"FName"  ;
                    table<<"LName";
                    table <<"Classification";
                    table << "Favorite";
                    table<<"Address";
                    table<<"Phone Number";
                    cout<<"\n";
                    equals
                }
                table<<j;
                j++;
                contacts[i].getInfo() ;
                f=1;
                found=1;
            }
        }
        if(found)equals
            if(!found)cout << "No contact found with that classification.\n";
    }
    void saveToFile(const string& filename) const
    {
        std::fstream file;
        file.open(filename, ios::out);
        if (!file.is_open())
        {
            cout << "Error opening file for writing: " << filename << endl;
            return;
        }
        file equalsinfile
        file<<left << setw(25) << setfill(' ') << "ID" ;
        file<<left << setw(25) << setfill(' ') <<"FName"  ;
        file<<left << setw(25) << setfill(' ')<<"LName";
        file<<left << setw(25) << setfill(' ') <<"Classification";
        file<<left << setw(25) << setfill(' ') << "Favorite";
        file<<left << setw(25) << setfill(' ')<<"Address";
        file<<left << setw(25) << setfill(' ')<<"Phone Number";
        file<<"\n";
        file equalsinfile
        for (int i = 0; i < contacts.getSize(); ++i)
        {
            person contact = contacts[i];

            file<<left << setw(25) << setfill(' ')<< i + 1;
            file<<left << setw(25) << setfill(' ') << contact.getFirstName();
            file<<left << setw(25) << setfill(' ') << contact.getLastName();
            file<<left << setw(25) << setfill(' ')<< contact.getClassification();
            file<<left << setw(25) << setfill(' ') << (contact.isFavorite() ? "Yes" : "No");
            file<<left << setw(25) << setfill(' ')<< contact.getAddress();
            file<<left << setw(25) << setfill(' ')<<contact.printphoneinfile();

            file<<"\n";
        }
        file equalsinfile


        file.close();
        cout << "Contacts saved to " << filename << " successfully!" << endl;
    }
    void loadFromFile(const string& filename)
    {
        ifstream in(filename);

        fstream file;
        file.open(filename);
        if (!file.is_open())
        {
            cout << "Error opening file : "<<filename<<" for reading" << std::endl;
            return;
        }

        string line;
        getline (in, line);
        string firstName, lastName, isFavoriteStr, classification,phone,mail;

        vector<string>read;
        string x="";
        int favv;
        for(int i=0; line[i]!=','; i++)
        {
            if(line [i]!=' ')
                x+=line[i];
            else
            {

                read.push_back(x);
                x="";
            }
            if(line[i]=='1'||line[i]=='0')favv=line[i]-'0';
        }
        firstName=read[0];
        lastName=read[1];
        classification=read[2];
        phone =read[3];
        mail=read[4];


        person contact(firstName, lastName,classification,phone,mail,favv);
        contacts.append(contact);
        file.close();
        cout << "Contacts loaded from " << filename << " successfully!" << endl;
    }
    void updateContact(int index)
    {
        if (index < 0 || index >= contacts.getSize())
        {
            cout << "Invalid index!" << endl;
            return;
        }

        person& contact = contacts[index];

        string newFirstName, newLastName,newClassification;
        string isFavorite;

        cout << "Current First Name: " << contact.getFirstName() << endl;
        cout << "Enter new First Name (or press Enter to keep it unchanged): ";
        getline(cin, newFirstName);
        if (newFirstName.empty())
            newFirstName = contact.getFirstName();
        cout << "Current Last Name: " << contact.getLastName() << endl;
        cout << "Enter new Last Name (or press Enter to keep it unchanged): ";
        getline(cin, newLastName);
        if (newLastName.empty())
            newLastName = contact.getLastName();

        cout<<"Current Classification: "<<contact.getClassification()<<endl;
        cout << "Enter new Classification (or press Enter to keep it unchanged): ";
        getline(cin, newClassification);
        if (newClassification.empty())
            newClassification = contact.getClassification();

        cout << "Current Favorite Status: " << (contact.isFavorite() ? "Yes" : "No") << endl;
        cout << "Mark as Favorite? (1 for Yes, 0 for No): ";
        getline(cin, isFavorite);
        bool fav;
        if(isFavorite.empty())fav=contact.isFavorite();
        else
        {
            if(isFavorite=="1")fav=1;
            else fav=0;
        }
        contact.setFirstName(newFirstName);
        contact.setLastName(newLastName);
        contact.setFavorite(fav);
        contact.setClassification(newClassification);

        cout << "Contact information updated successfully!" << endl;
    }
    void reverseContacts()
    {
        contacts.Reverse();
        cout << "Contacts reversed successfully!" << endl;
    }
    void RemoveDuplicates()
    {
        contacts.RemoveDuplicates();
    }
};
#endif // CONTACT_H_INCLUDED
