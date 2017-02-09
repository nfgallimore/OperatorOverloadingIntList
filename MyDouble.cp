#include "MyDouble.h"
#include <iostream>

class MyDouble
{

private:

    double value;

public:

    // default constructor
    MyDouble() {
        value = 0;
    }
    // constructor taking a double as parameter
    MyDouble(double v) {
        value = v;
    }

    /*	=	*/
    // mutator
    void setValue(double d) {
        value = d;
    }
    // operator = a double
    MyDouble operator=(double d) {
    	value = d;
    	return *this;
    }
    // operator = MyDouble
    MyDouble operator=(const MyDouble &obj) {
    	value = obj.value
    	return *this;
    }


    /*	+	*/
    // operator + MyDouble
    MyDouble operator+(const MyDouble &obj) {
        MyDouble temp;
        temp.setValue(value + obj.value);
        return temp;
    }
    // operator + a double
    MyDouble operator+(double v) {
        MyDouble temp;
        temp.setValue(value + v);
        return temp;
    }
    // overload operator + applied to a primitive double
    friend MyDouble operator+(double v, MyDouble d) {
        MyDouble temp;
        temp.setValue(v + d.value);
        return temp;
    }



    /*	+=	*/
    // operator += to the object of the same class
    void operator+=(const MyDouble &right) {
        value += right.value;
    }
    // operator += to the primitive type
    void operator+=(double d) {
        value += d;
    }



    /* == */
    // overload operator == with right side of the object of the same class
    bool operator==(const MyDouble &d) {
        return value == d.value;
    }
    // overload operator == with right side of a primitive double
    bool operator==(double d) {
        return value == d;
    }
    // overload operator == with left side of a primitive double
    friend bool operator==(double left, const MyDouble &d) {
        return left == d.value;
    }


    /* ++i	*/
    //  prefix ++, return the value after incremented
    MyDouble operator++() {
        value += 1;
        return *this;
    }


    /*	i++	*/
    //  postfix ++, return the value before incremented
    MyDouble operator++(int) {
        MyDouble temp(value);
        value += 1;
        return temp;
    }
    

    /*	<<	*/
    friend std::ostream &operator<<(std::ostream& out, MyDouble d) {
        out << d.value;
        return out;
    }



};


class IntList
{
private:

	int length;
	int* list;

public:

	//  constructor
	IntList(int size) {
		length = size;
		list = new int[length];
		for (int i = 0; i < length; i++) {
			list[i] = 0;
		}
	}

	//  returns size of IntList
	int size() {
		return length;
	}

	//  subscript
	int& operator[](int index){
		return list[index];
	}

	//  destructor
	~IntList() {
		if (list) {
			delete[] list;
		}
	}
	IntList(const IntList &obj) {
		obj.list
		memcpy(list, obj.list, sizeof(int) * length);
	}
	
    // operator = IntList
    IntList operator=(const IntList &obj) {
		memcpy(list, obj.list, sizeof(int) * length);
		return this;
    }
    // << operator
    friend std::ostream &operator<<(std::ostream &out, const IntList &l) {
		out << "[ ";
		for (int i = 0; i < l.length; i++) {
			out << l.list[i] << ' ';
		}
  		out << ']';
  		return *out;
  	}

};