#pragma once
#include<stdio.h>
#include<string.h>
#include "Customer.h"
#include "Room.h"
#include "Reservation.h"
#include "Hotel.h"

void showHotelStatus(Hotel* California) {
	for (int i = 0; i < 4; i++) {
		for (int h = 0; h < 3; h++) {
			Room* HotelRoomPointer = &California->Room[i][h];
			bool RoomStatus = checkRoom(HotelRoomPointer);
			if (RoomStatus == true) {
				printf("Room: %d %d\n", i+1, h+1);
				printf("%s", "is Taken By: ");
				for (int x = 0; x < 12; x++) {
					if (California->Reservation[x].ReservationEmpty == false) {
						Reservation* ReservationFindCustomer = &California->Reservation[x];
						printf("%s\n", FindRoomForCustomer(HotelRoomPointer, ReservationFindCustomer).Name);
					}
				}
				printf("%s", "The amount of People in the Room Are: ");
				printf("%d\n", HotelRoomPointer->ResidentsInRoom);
				printf("%s", "The Amount for Breakfast: ");
				printf("%d\n", HotelRoomPointer->ResidentsForBreakfast);
			}

		}
	}
}

void addCustomer(Hotel* California) {
	char name[20];
	long long creditcard;
	bool flag = true;
	printf("%s\n", "Please Enter Your name");
	scanf("%s", name);
	while (flag) {
		printf("%s\n", "Please Enter Your Credit Card Number ");
		scanf("%lld", &creditcard);
		if (creditcard >= 100000000000 && creditcard <= 999999999999) {
			flag = false;
			int i = CheckForArraySlotIsEmpty(California);
			if (i == -1) {
				printf("%s", "Please Restart Program");
			}
			else {
				Customer customer;
				Customer* customer1 = &customer;
				SetCustomerValue(customer1,creditcard, i, name);
				SetCustomer(California, customer1, i);
				California->Customers[i].Empty = false; //For some reason I couldn't fix the pointers to work, it didn't work without me declaring it to be false outside of the previous method.
				printf("%s\n", "You have Registered Successfully!");
			}
		}
		else {
			printf("%s\n", "Please Enter a Valid Credit Card Number ");
		}
	}

}


void CheckIn(Hotel* California) {
	int NumberToBeInputted;
	int NumberOfSleepyPeople;
	int NumberOfHungryPeople;
	int Check = CheckForArraySlotIsEmpty(California);
	if (Check > 0) {
		printCustomerList(California);
		printf("%s\n", "Please Choose a Customer Name From the List Displayed Above: ");
		scanf("%d", &NumberToBeInputted);
		printf("%s\n", "Please Enter the Number of People Residing in the Room: ");
		while (true) {
			scanf("%d", &NumberOfSleepyPeople);
			if (NumberOfSleepyPeople > 0 && NumberOfSleepyPeople < 6) {
				break;
			}
			else {
				printf("%s\n", "Please Enter a Valid Number of Residents. Max 5");
			}
		}
		printf("%s\n", "Please Enter the Amount of people that go to Breakfast.");
		while (true) {
			scanf("%d", &NumberOfHungryPeople);
			if (NumberOfHungryPeople <= NumberOfSleepyPeople && NumberOfHungryPeople > 0) {
				break;
			}
			else {
				printf("%s\n", "Please Enter a Valid Number of diners. Max 5");
			}
		}
		Room* RoomPointer = CheckIfAllRoomsAreEmpty(California);
		if (checkRoom(RoomPointer)) {
			printf("%s", "There are no rooms available, go home bye bye!");
		}
		else {
			int integer = CheckForEmptyReservation(California);
			AddDetailsToReservation(&California->Reservation[integer], &California->Customers[NumberToBeInputted-1], RoomPointer);
			RegisterToRoom(RoomPointer, NumberOfSleepyPeople, NumberOfHungryPeople);
			RoomPointer->RoomTaken = true;
			printf("%s\n", "You Registered Successfully! Please go to the counter to take your keys.");
		}
	}
	else {
		printf("%s\n", "There are no Registered Customers");
	}
}

void CheckOut(Hotel* California) {
	int floorNumber;
	int RoomNumber;
	bool flag = true;
	while (flag) {
		printf("%s\n", "Please Enter your Room Floor");
		scanf("%d", &floorNumber);
		printf("%s\n", "Please Enter your Room number on the floor your entered");
		scanf("%d", &RoomNumber);
		if (floorNumber < 4 && RoomNumber < 3 && floorNumber > 0 && RoomNumber > 0) {
			flag = false;
		}
		else {
			printf("%s", "Please Enter the correct Number");
		}
	}
	California->Room[floorNumber - 1][RoomNumber - 1].RoomTaken = false;
	DeregisterReservation(California, &California->Room[floorNumber - 1][RoomNumber - 1]);
}

void PrintMenuOptions() {
	printf("%s\n", "1. Show Hotel Status");
	printf("%s\n", "2. Add Customer");
	printf("%s\n", "3. Check In");
	printf("%s\n", "4. Check Out");
	printf("%s\n", "5. Exit");
	printf("%s\n", "Please Select a Option: ");
}