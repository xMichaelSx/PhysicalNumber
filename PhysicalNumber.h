

#pragma once
#include "Unit.h"
#include <iostream>
using namespace std;

namespace ariel {
    class PhysicalNumber{
    private:
        double data;
        Unit unit;
    public:
        PhysicalNumber();
        //constructor with initializing list
        PhysicalNumber(double num, Unit type):data(num), unit(type){
            if(type>8||type<0)throw std::invalid_argument("recieved wrong value");
        }

        double GetData(){
            return this->data;
        }
        std::string GetUnit(){
            int temp = this->unit;
            switch (temp){
                case 0: return "CM";
                case 1: return "M";
                case 2: return "KM";
                case 3: return "SEC";
                case 4: return "MIN";
                case 5: return "HOUR";
                case 6: return "G";
                case 7: return "KG";
                case 8: return "TON";
                default: throw invalid_argument("nooo");
            }
            return "";
        }
        void setUnit(Unit un){
            this->unit = un;
        }
        void setData(double num){
            this->data=num;
        }

        //+/-

        ariel::PhysicalNumber operator+(const PhysicalNumber& b);
        friend ariel::PhysicalNumber& operator+=(PhysicalNumber& a,const ariel::PhysicalNumber& b);
        PhysicalNumber operator+()const;

        ariel::PhysicalNumber operator-(const PhysicalNumber& b);
        friend ariel::PhysicalNumber& operator-=(PhysicalNumber& a,const ariel::PhysicalNumber& b);
        PhysicalNumber operator-();

        //comparison
        friend bool operator== (const PhysicalNumber& a,const PhysicalNumber& b);
        friend bool operator>= (const PhysicalNumber& a,const PhysicalNumber& b);
        friend bool operator<= (const PhysicalNumber& a,const PhysicalNumber& b);
        friend bool operator> (const PhysicalNumber& a,const PhysicalNumber& b);
        friend bool operator< (const PhysicalNumber& a,const PhysicalNumber& b);
        friend bool operator!= (const PhysicalNumber& a,const PhysicalNumber& b);

        //++,--
        friend PhysicalNumber& operator++(PhysicalNumber& a); //++num
        PhysicalNumber operator++(int); //num++
        friend PhysicalNumber& operator--(PhysicalNumber& a);//--num
        PhysicalNumber operator--(int);//num--

        //input output
        friend istream& operator>> (istream& in, ariel::PhysicalNumber& a);
        friend ostream& operator<<(ostream& out,const ariel::PhysicalNumber& a);

    };
}













// #pragma once
// #include <iostream>
// #include "Unit.h"
        
// namespace ariel
// {

//     using namespace std;
//         // ostream& operator <<(ostream &, PhysicalNumber const &);
//     class PhysicalNumber
//     {
//         private:
//         PhysicalNumber convert(const PhysicalNumber &pn) const;
//         // string PhysicalNumber::getUnitName(enum ariel::Unit::Type type) const;

//         public:
        
//         //members (variables)
//         double number; // the amount of the units
//         Unit unit; // can be  seconds,minutes,hours,tons,m and so on...
        
//         //constructor
//         PhysicalNumber(double ,Unit::Type);
//         PhysicalNumber();
//         ~PhysicalNumber();

//         PhysicalNumber operator+(const PhysicalNumber &pn) const;
//         PhysicalNumber& operator+=(const PhysicalNumber &pn);
//         PhysicalNumber operator+() const;
//         PhysicalNumber& operator++(int);
//         PhysicalNumber& operator++();
        
//         PhysicalNumber operator-(const PhysicalNumber &pn) const;
//         PhysicalNumber& operator-=(const PhysicalNumber &pn);
//         PhysicalNumber operator-() const;
//         PhysicalNumber& operator--(int);
//         PhysicalNumber& operator--();
        
    
//         bool operator<(const PhysicalNumber& PhysicalNumber) const;
//         bool operator>(const PhysicalNumber& PhysicalNumber) const;
//         bool operator<=(const PhysicalNumber& PhysicalNumber) const;
//         bool operator>=(const PhysicalNumber& PhysicalNumber) const;
//         bool operator==(const PhysicalNumber& PhysicalNumber) const;
//         bool operator!=(const PhysicalNumber& PhysicalNumber) const;
//         /*
//         friend bool operator<(const PhysicalNumber& PhysicalNumber);
//         friend bool operator>(const PhysicalNumber& PhysicalNumber);
//         friend bool operator<=(const PhysicalNumber& PhysicalNumber);
//         friend bool operator>=(const PhysicalNumber& PhysicalNumber);
//         friend bool operator==(const PhysicalNumber& PhysicalNumber);
//         friend bool operator!=(const PhysicalNumber& PhysicalNumber);
//         */

//         // this function check if the unit family is the same (for example, km and m)
//         //  istream& operator >>(istream &is ,PhysicalNumber &pn);
//         };
        
//         ostream& operator <<(ostream &os, PhysicalNumber const &pn);
//         istream& operator >>(istream &is ,PhysicalNumber &pn);
// }