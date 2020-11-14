#include "point.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

Point::Point(){
    _x = 0;
    _y = 0;
    _name = NULL;
}

Point::Point(double x, double y){
    _x = x;
    _y = y;
    _name = new char[17];
    char* name = (char*)"Miejsce nieznane";
    strcpy(_name, name);
}

Point::Point(const char* name, double x, double y){
    _x = x;
    _y = y;
    _name = new char[strlen(name)];
    strcpy(_name, name);
}

Point::Point(const Point &p1){
    _x = p1._x;
    _y = p1._y;
    _name = new char[strlen(p1._name)];
    strcpy(_name, p1._name);
}

Point::Point(Point &&p1){
    _x = p1._x;
    _y = p1._y;
    _name = new char[strlen(p1._name)];
    strcpy(_name, p1._name);
    delete [] p1._name;
    p1._name = NULL;
    p1._x = 0;
    p1._y = 0;
}

Point::~Point(){
    delete [] _name;
}

double Point::getX(){
    return _x;
}

double Point::getY(){
    return _y;
}

char* Point::getName(){
    return _name;
}

void Point::changeName(const char* name){
    delete [] _name;
    _name = new char[strlen(name)];
    strcpy(_name, name);
}

void Point::fullPrint(){
    if(_name == NULL){
        cout<<"NULL"<<" ("<<_x<<", "<<_y<<")"<<endl;
    }
    else{
    	cout<<_name<<" ("<<_x<<", "<<_y<<")"<<endl;
    }
}

void Point::move(double x, double y){
    _x += x;
    _y += y;
}

int compareX(const Point &p1, const Point &p2){
    if(p1._x > p2._x){
    	return -1;
	}
	else if(p1._x == p2._x){
		return 0;
	}
	else{
		return 1;
	}
}

int compareY(const Point &p1, const Point &p2){
	if(p1._y > p2._y){
    		return -1;
	}
	else if(p1._y == p2._y){
		return 0;
	}
	else{
		return 1;
	}
}

int compareXY(const Point &p1, const Point &p2){
	int x,y;
	if(p1._x > p2._x){
    		x = -1;
	}
	else if(p1._x == p2._x){
		x = 0;
	}
	else{
		x = 1;
	}
	if(p1._y > p2._y){
    		y = -1;
	}
	else if(p1._y == p2._y){
		y = 0;
	}
	else{
		y = 1;
	}
	return 10*x+y;
}

void directions(const Point &p1, const Point &p2, int(*f) (const Point &, const Point &)){
	cout<<p1._name<<" jest na ";
	if(f == compareX){
		switch(f(p1, p2)){
			case 1:
				cout<<"zachod od ";
				break;
			case 0:
				cout<<"tej samej dlugosci co ";
				break;
			case -1:
				cout<<"wschod od ";
				break;
		}
	}
	else if(f == compareY){
		switch(f(p1, p2)){
			case 1:
				cout<<"poludnie od ";
				break;
			case 0:
				cout<<"tej samej szerokosci co ";
				break;
			case -1:
				cout<<"polnoc od ";
				break;
		}
	}
	else{
		switch(f(p1, p2)){
			case -9:
				cout<<"poludniowy-wschod od ";
				break;
			case 11:
				cout<<"poludniowy-zachod od ";
				break;
			case -11:
				cout<<"polnocny-wschod od ";
				break;
			case 9:
				cout<<"polnocny-zachod od ";
				break;
			case 10:
				cout<<"zachod od "<<p2._name<<endl;
				cout<<p1._name<<" jest na tej samej szerokosci co ";
				break;
			case 1:
				cout<<"tej samej dlugosci co "<<p2._name<<endl;
				cout<<p1._name<<" jest na poludnie od ";
				break;
			case -10:
				cout<<"wschod od "<<p2._name<<endl;
				cout<<p1._name<<" jest na tej samej szerokosci co ";
				break;
			case -1:
				cout<<"tej samej dlugosci co "<<p2._name<<endl;
				cout<<p1._name<<" jest na polnoc od ";
				break;
		}
	}
	cout<<p2._name<<endl;
}

