#pragma once
#include <cstddef>
#include <iostream>
#include <string>

//A class constructor is a special member function of a 
//class that is executed whenever we create new objects of that class.
class linked_list
{
public:
	//Constructor of the class
	linked_list(); //klar

	//The second constructor with arguments
	linked_list(const linked_list & src); //klar

	//Destructor
	~linked_list(); //klar

	//Operator overloading adds elements to the back
	linked_list & operator=(const linked_list & rhs);

	//Adding elements to the back, yet another operator overloading
	linked_list & operator +=(const linked_list & rhs);

	//inserting elements
	void insert(double value, size_t pus);  //klar 


	//in front
	void push_front(double value);  //klar

	//in back
	void push_back(double value); //klar

	//accessing elements
	double front() const; //klar
	double back() const;  //klar
	double at(size_t pus) const;  //klar

	// removing elements
	void remove(size_t pos);   //klar

	// remove and access
	double pop_front();  //klar
	double pop_back();   //klar

	// informational
	size_t size() const;  //klar
	bool is_empty() const;  //klar

	// output
	void print() const; //klar 
	void print_reverse() const; //KLAR
private:
	struct node_t {
		node_t(double value, node_t * next = 0, node_t * prev = 0); 
		double value;
		node_t * next;
		node_t * prev;
	};
	node_t * head;
	node_t * tail;
};

