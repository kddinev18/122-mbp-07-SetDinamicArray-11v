#include "Set.h"
#include <iostream>

int Set::calcDegree()
{
	return size;
}

Set Set::complementWith(Set& Y)
{
	Set newSet;
	int count = 0;
	int i = 0, j = 0;
	while (i < size && j < Y.size) {
		if (elements[i] < Y.elements[j]) {
			newSet.elements[count++] = elements[i];
			newSet.size++;
			i++;
		}
		else if (elements[i] > Y.elements[j]) {
			j++;
		}
		else if (elements[i] == Y.elements[j]) {
			i++;
			j++;
		}
	}
	while (i < size)
	{
		newSet.elements[count++] = elements[i];
		newSet.size++;
	}

	return newSet;
}

void Set::enterFromKeyboard()
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> elements[i];
	}
}

Set::Set()
{
	size = DEFAULTSIZE;
	elements = new int[size];
}

Set::Set(int s)
{
	size = s;
	elements = new int[size];
}

Set::~Set()
{
	delete[] elements;
}

bool Set::contains(int n)
{
	for (int i = 0; i < size; i++)
	{
		if (elements[i] == n)
		{
			return true;
		}
	}
}

Set Set::unionWith(Set& y)
{
	Set newSet;
	int count = 0;
	newSet.size = this->size + y.size;
	newSet.elements = new int[size];
	for (int i = 0; i < this->size; i++)
	{
		newSet.elements[count++] = this->elements[i];
		newSet.size++;
	}
	for (int i = 0; i < y.size; i++)
	{
		newSet.elements[count++] = y.elements[i];
		newSet.size++;
	}
	return newSet;
}

Set Set::intersectWith(Set& y)
{
	Set newSet;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (y.contains(elements[i]))
		{
			newSet.elements[count++] = elements[i];
			newSet.size++;
		}
	}
	return newSet;
}

void Set::sort()
{
	int i, j;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (elements[j] > elements[j + 1])
				std::swap(elements[j], elements[j + 1]);
}

void Set::display()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << elements[i] << " ";
	}
}
