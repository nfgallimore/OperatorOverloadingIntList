#ifndef MYDOUBLE_H
#define MYDOUBLE_H

#include <iostream>
class MyDouble
{
    private:
        double value;
    public:
        //default constructor
        MyDouble(){
            value = 0;
        }
        //constructor taking a double as parameter
        MyDouble(double v){
            value = v;
        }
        //mutator
        void setValue(double d){
            value=d;
        }

        //operator +
        MyDouble operator+(const MyDouble & obj){
            MyDouble temp;
            temp.setValue(value + obj.value);
            return temp;
        }

        //operator + a double
        MyDouble operator+(double v){
            MyDouble temp;
            temp.setValue(value + v);
            return temp;
        }

        //operator += to the object of the same class
        void operator+=(const MyDouble& right){
            value += right.value;
        }
        //operator += to the primitive type
        void operator+=(double d){
            value += d;
        }
        //overload operator + applied to a primitive double
        friend MyDouble operator+(double v, MyDouble d){
            MyDouble temp;
            temp.setValue(v+d.value);
            return temp;
        }

        //overload operator == with right side of the object of the same class
        bool operator==(const MyDouble & d){
            return value==d.value;
        }
        //overload operator == with right side of a primitive double
        bool operator==(double d){
            return value==d;
        }
        //overload operator == with left side of a primitive double
        friend bool operator==(double left, const MyDouble & d){
            return left==d.value;
        }

        //prefix ++, return the value after incremented
        MyDouble operator++(){
            value += 1;
            return *this;
        }

        //prefix ++, return the value before incremented
        MyDouble operator++(int){
            MyDouble temp(value);
            value += 1;
            return temp;
        }
        friend std::ostream& operator<<(std::ostream& out, MyDouble d){
            out << d.value;
            return out;
        }
};


class IntList
{
private:
    int numberOfInts;
    int * myList;
public:
    IntList(int numberOfIntegers){
        numberOfInts = numberOfIntegers;
        myList = new int[numberOfInts];
        for(int i=0; i<numberOfInts; ++i){
            myList[i] = 0;
        }
    }
    int size(){
        return numberOfInts;
    }
    int& operator[](int index){
        return myList[index];
    }

};
#endif // MYDOUBLE_H
