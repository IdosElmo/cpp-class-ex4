
#ifndef CIRCULARINT_H
#define CIRCULARINT_H

#include <iostream>
#include <string>

using namespace std;

class CircularInt{
    public:
    
        int start;
        
        int end;
        
        int current;
        
        CircularInt();
        
        CircularInt(int s, int e);
        
        ~CircularInt();
        
        void setCurrent(int current);
        
        CircularInt operator/ (const int num);
        
        CircularInt& operator+= (const int num);
        
        CircularInt& operator++ (int);
        
        CircularInt& operator=(const CircularInt& c);
        
        CircularInt& operator*(const int num);
        
        CircularInt& operator*=(const int num);
        
        void operator--(int);
        
        void operator--();
        
        friend CircularInt& operator- (const CircularInt&);
        
        friend CircularInt& operator- (int num, const CircularInt&);
        
        friend int operator/ (const CircularInt&, int num);
        
        friend int operator+(CircularInt& A, CircularInt& B);
        
        friend ostream& operator<< (ostream& os, const CircularInt& c);
};
#endif
