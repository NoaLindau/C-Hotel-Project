#pragma once
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "Customer.h"
#include "Room.h"
#include "Reservation.h"
using namespace std;

struct Hotel {
	Room Room[4][3];
	Reservation Reservation[12];
	Customer Customers[60];
};

Room getRoom(Hotel* California,int x, int y) {
	return California->Room[x][y];
}

int CheckForArraySlotIsEmpty(Hotel* California) {
	for (int i = 0; i < 60; i++) {
		if (California->Customers[i].Empty == true) {
			return i;
		}
	}
	return -1;
}

void printCustomerList(Hotel* California) {
	int StopValue = CheckForArraySlotIsEmpty(California);
	for (int i = 0; i < StopValue; i++) {
		printf("%d.%s\n", i + 1, California->Customers[i].Name);
	}
}

	Customer ReturnCustomerFromList(Hotel * California, int i){
		i = i +1;
		return California->Customers[i];
	}

	bool CheckIfRoomIsEmpty(Hotel* California, int x, int y) {
		if (California->Room[x][y].RoomTaken == false) {
			return true;
		}
		else {
			return false;
		}
}
	Room* CheckIfAllRoomsAreEmpty(Hotel* California) {
		for (int i = 0; i < 4; i++) {
			for (int h = 0; h < 3; h++) {
				if (CheckIfRoomIsEmpty(California, i, h)) {
					return &California->Room[i][h];
				}
			}
		}
		return &California->Room[0][0];
	}
	int CheckForEmptyReservation(Hotel* California) {
		for (int i = 0; i < 12; i++) {
			if (CheckReservation(&California->Reservation[5])) {
				return i;
			}
		}

		return -1;
	}

	void DeregisterReservation(Hotel* California, Room* room) {
		for (int i = 0; i < 12; i++) {
			if (isEqual(&California->Reservation[i].room, room)) {
				California->Reservation[i].ReservationEmpty = true;
			}
		}
	}

	void SetCustomer(Hotel* California, Customer* Customer, int i) {
		California->Customers[i] = *Customer;
	}