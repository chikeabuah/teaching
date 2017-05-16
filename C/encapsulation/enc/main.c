#include <stdio.h>
#include <stdlib.h>
#include "date.h"

int main(int argc, char * argv[]){

	// Date today = {-12, -25, 2017};
	DATE today = NULL;
	today = date_init_default();
	if (today == NULL) {
		printf("Failed to allocate date object\n");
		exit(1);
	}
	date_set_month(today, 7);
	print_date(today);
	return 0;
}

