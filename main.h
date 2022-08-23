#pragma once

#include "Person.h"
#include <iostream>
#include <time.h>
#include <random>
#include <string>
#include"BSTree.h"
#include"heap.h"

void swap(Person& a, Person& b);
const Person& RandSelection(Person arr[], int left, int right, int k, int& NumComp);
int Partition(Person arr[], int left, int right, Person ptr, int& NumComp);
const Person& BST(Person arr[], int n, int k, int& NumComp);
string makeString(Person* pArr, Person* pArr2, int id);
bool isLetter(char c);
const Person& selectHeap(Person data[], int n, int k, int& NumComp);