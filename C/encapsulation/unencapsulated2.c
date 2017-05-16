#include <stdio.h>
#include <string.h>


typedef struct Date {
	int month;
	int day;
	int year;
};


void print_date(struct Date *date) {
	printf("%d/%d/%d\n", date->month, date->day, date->year);
}

int main(int argc, char * argv[]){
	struct Date today = {12, 25, 2017};
	print_date(&today);
	return 0;
}

