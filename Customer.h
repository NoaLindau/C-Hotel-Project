#pragma once
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
using namespace std;

struct Customer {
	long long CardNumber =0;
	int IdNumber;
	char Name[20];
	bool Empty = true;
};
void SetCustomerValue(Customer* customer,long long Cnumber, int id, char n[]) {
	Customer* CustomerPointer = customer;
	CustomerPointer->Empty = false;
	CustomerPointer->CardNumber = Cnumber;
	CustomerPointer->IdNumber = id;
	strcpy(CustomerPointer->Name, n);
	
}

// Need to define an Empty Customer, so that, I can Check things.

