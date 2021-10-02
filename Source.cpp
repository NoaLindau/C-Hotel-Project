#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <string>
#include "Hotel.h"
#include "UpdateStructure.h"
using namespace std;

int main() {
	struct Hotel California;
	Hotel* California1 = &California;
	int OptionSelection;
	bool flag = true;
	while (flag) {
		PrintMenuOptions();
		scanf("%d", &OptionSelection);
		if (OptionSelection > 0 && OptionSelection < 6) {
			switch (OptionSelection)
			{
			case 1:
				showHotelStatus(California1);
				break;
			case 2:
				addCustomer(California1);
				break;
			case 3:
				CheckIn(California1);
				break;
			case 4:
				CheckOut(California1);
				break;
			case 5:
				flag = false;
				break;
			default:
				printf("%s\n", "Please Pick a Valid Number");
				break;
			}
		}

	}
	return 0;
}