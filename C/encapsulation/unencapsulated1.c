#include <stdio.h>

void print_date(int month, int day, int year);

int main()
{

	int month, day, year;

	month = 5;
	day = 12;
	year = 2017;

	print_date(month, day, year);

	return 0;
}

void print_date(int month, int day, int year) {

	printf("%d/%d/%d\n", month, day, year);

}