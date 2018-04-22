#include "CircularInt.hpp"
 
CircularInt::CircularInt() {
    
    start = 0;
    end = 0;
    current = 0;
}

CircularInt::CircularInt(int s, int e){
    
    start = s;
    end = e;
    current = start;
}

CircularInt::~CircularInt(){
    
    
}

ostream& operator<< (ostream& os, const CircularInt& c)
{
	os << c.current;
	return os;
}

void CircularInt::operator--(int tmp)
{
	if(current == start){ 
	   current = end;
	}
	else current--; 
}

void CircularInt::operator--()
{
	if(current == start){
	current = end;
	}
	else current--; 
}

CircularInt& CircularInt::operator= (const CircularInt& c){
     start = c.start;
     end = c.end;
     current = c.current;
     return *this;
}

CircularInt& CircularInt::operator+= (const int num){
    int temp = current + num;
    current = temp % (end - start +1);
    return *this;
    
}

CircularInt& CircularInt::operator++(int){
    if(current == end)
        current = start;
    else
        current++;
    return (*this);
}

CircularInt& operator-(const CircularInt& c)
{
	CircularInt c1 = c;
	int tmp = c.current - c.start+1;
	c1.current = c1.end;
	for(int i=0;i<tmp;i++)
	{
		c1--;
	}
	return c1;
}
CircularInt& operator-(int tmp, const CircularInt& c)
{
	CircularInt c1=-c;
	c1+=tmp;
	return c1;
}



int operator+ (CircularInt& A, CircularInt& B)
{
	return (A.current + B.current) % (A.end - A.start +1);
}

CircularInt& CircularInt::operator* (const int num){
    current = (current * num);
    setCurrent(current);
    return *this;
}

CircularInt& CircularInt::operator*= (const int num){
    (*this) = (*this) * num;
    return *this;
}

void CircularInt::setCurrent(int current){
    if(current >= 0){
        CircularInt::current = current % end;
    }
    else{
        while(current < 0) {
            current += end;
        }
    }
}

CircularInt CircularInt::operator/ (const int num){
    
    current = current / num;
    setCurrent(current);
    
    return *this;
}