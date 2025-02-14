#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>
using namespace std;
#include"darray.h"
class Address
{
private:
    int streetnum;
    string streetname, city, state;

public:
    Address() : streetnum(0),streetname(" "),city(" "), state("Egypt") {}

    Address(int streetnum,string streetname, string city, string state)
        : streetnum(streetnum),streetname(streetname), city(city), state(state)
    {

    }
    void getFullAddress()
    {
        cout<<getStreetNum();
        string x=streetname+","+city+","+state;
        cout << left << setw(25) << setfill(' ')<<x;
    }
    string getFullAddressInfile()
    {
        int n=getStreetNum();
        string y=to_string(n);
        string x=y+streetname+","+city+","+state;
        return x;
    }
    int getStreetNum()
    {
        return streetnum;
    }
    void setStreetnum(const int& stnum)
    {
        streetnum = stnum;
    }
    void setStreetname(const string& stname)
    {
        streetname = stname;
    }
    void setCity(const string& ct)
    {
        city = ct;
    }
    void setState(const string& ste)
    {
        state = ste;
    }
};
#endif //ADDRESS_H
