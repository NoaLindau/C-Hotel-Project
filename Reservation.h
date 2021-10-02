#pragma once
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "Customer.h"
#include "Room.h"
using namespace std;
struct Reservation {
	char date[11] = "2021-01-08";
	Customer customer;
	Room  room;
	bool ReservationEmpty = true;
	
};


void AddDetailsToReservation(Reservation* CurrentReservation, Customer* AddCustomer, Room* CurrentRoom) {
	CurrentReservation->ReservationEmpty = false;
	CurrentReservation->customer = *AddCustomer;
	CurrentReservation->room = *CurrentRoom;
}

Customer FindRoomForCustomer(Room* RoomCheck, Reservation* ReservationToFindCustomerIn) {
	if (isEqual(RoomCheck, &ReservationToFindCustomerIn->room)) {
		return ReservationToFindCustomerIn->customer;
	}
	else {
		return ReservationToFindCustomerIn->customer;
	}
}
void DeleteReservation(Reservation* CurrentReservation) {
	CurrentReservation->ReservationEmpty = true;
}

bool CheckReservation(Reservation* CurrentReservation) {
	return CurrentReservation->ReservationEmpty;
}