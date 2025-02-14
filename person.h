#ifndef PERSON_H
#define PERSON_H
#include<bits/stdc++.h>
#include"address.h"
using namespace std;
#define table cout << left << setw(25) << setfill(' ')

#define equals cout << "======================================================================================================================================================================================\n";
#define nice cout <<setw(37)<<"=";
#define decore cout <<"==================================================================\n";
class person
{
private:
    string firstName,lastName,Classification;
    bool Favorite;
    Address add;
    int nn,mm;
    vector<string>phoneNumber,Email;

public:
    person() {}
    person (string firstname,string lastname,string classification,vector<string> numofnums,int n,
            vector<string> numofemails,int m,Address &addr, bool favorite)
        :firstName(firstname),
         lastName(lastname),
         Classification(classification),
         phoneNumber(numofnums),
         nn(n),
         Email(numofemails),
         mm(m),
         add(addr),Favorite(favorite) {}
    person(const string& fName, const string& lName, bool fav, const string& classif)
        : firstName(fName), lastName(lName), Favorite(fav), Classification(classif) {}
    person(const string& fName, const string& lName, const string& classif,string phone,string email,  bool fav)
        : firstName(fName), lastName(lName), Classification(classif), Favorite(fav)
    {
        phoneNumber.push_back(phone);
        Email.push_back(email);

    }
    string getFirstName() const
    {
        return firstName;
    }
    string getLastName() const
    {
        return lastName;
    }
    bool isFavorite() const
    {
        return Favorite;
    }
    string getClassification()
    {
        return Classification;
    }
    void setFirstName(string fName)
    {
        firstName = fName;
    }
    void setLastName(string lName)
    {
        lastName = lName;
    }
    void setClassification(string classif)
    {
        Classification = classif;
    }
    void setFavorite(bool fav)
    {
        Favorite = fav;
    }
    void setAddress(Address addr)
    {
        add = addr;
    }
    bool operator==(const person& other) const
    {
        return (firstName == other.firstName &&lastName==other.lastName&& phoneNumber == other.phoneNumber && Email == other.Email);
    }
    void printaddress()
    {
        add.getFullAddress();
    }
    string getAddress()
    {

        return add.getFullAddressInfile();
    }
    void printphone()
    {

        string x="";

        for(int i=0; i<phoneNumber.size(); i++)x+=phoneNumber[i]+",";
        table<<x;

    }
    string printphoneinfile()
    {

        string x="";

        for(int i=0; i<phoneNumber.size(); i++)x+=phoneNumber[i]+",";
        return x;
    }
    void getInfo()
    {
        table <<getFirstName();
        table <<getLastName();
        table<<getClassification();
        table << (isFavorite() ? "Yes" : "No");
        printaddress();
        table;
        printphone();
        cout<<"\n";
    }
};
#endif //PERSON_H
