#pragma once
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
using namespace std;


struct Room {
	bool RoomTaken = false;
	int ResidentsInRoom=0;
	int ResidentsForBreakfast=0;
};

void RegisterToRoom(Room* room, int ResidentsInRoom, int ResidentsForBreakfast) {
		room->ResidentsInRoom = ResidentsInRoom;
		room->ResidentsForBreakfast = ResidentsForBreakfast;
}

bool checkRoom(Room* room) { // Arrow Operator means referencing the struct private value the pointer is pointing at.
	return room->RoomTaken;
}

int ResidentsForBreakfast(Room* room) {
	return room->ResidentsForBreakfast;
}

bool isEqual(Room* FirstRoom, Room* SecondRoom) {
	if (FirstRoom == SecondRoom) {
		return true;
	}
	else{
		return false;
	}
}
