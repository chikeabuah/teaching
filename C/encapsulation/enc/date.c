#include <stdio.h>
#include <stdlib.h>
#include "date.h"

struct date {
	int month;
	int day;
	int year;
};

typedef struct date Date;
typedef Date* DatePtr;

void print_date(DATE hDate) {

	// preconditions?
	// type/tagging system?
	DatePtr pDate = (DatePtr) hDate;
	printf("%d/%d/%d\n", pDate->month, pDate->day, pDate->year);
}

DATE date_init_default(void) {

	DatePtr pDate;
	pDate = (DatePtr) malloc(sizeof(Date));

	if (pDate != NULL) {
		//do important stuff...
		pDate->month = 1;
		pDate->day = 1;
		pDate->year = 1970;

	}

	//objet or null
	return pDate;
}

Status date_set_month(DATE hDate, int month){
	DatePtr pDate = (DatePtr) hDate;
	if (month) {
		pDate->month = month;
	} else {
		return FAILURE;
	}
}

Status date_set_day(DATE hDate, int day){
	return FAILURE;
}
Status date_set_year(DATE hDate, int year){
	return FAILURE;
}

void date_destroy(DATE* phDate) {
	DatePtr pDate = (DatePtr) *phDate;

	free(pDate);
	*phDate = NULL;

}