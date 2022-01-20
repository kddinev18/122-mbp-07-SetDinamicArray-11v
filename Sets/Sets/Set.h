#pragma once
class Set {

	int size = 0;
	int DEFAULTSIZE = 10;
	int* elements = new int[size];

public:

	Set();

	Set(int s);

	~Set();

	bool contains(int n);
	Set unionWith(Set& Y);
	Set intersectWith(Set& Y);
	Set complementWith(Set& Y);
	Set complimentSimetric(Set& X, Set& Y);

	void sort();
	int calcDegree();
	void enterFromKeyboard();
	void display();

};