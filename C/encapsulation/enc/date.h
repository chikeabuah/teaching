#include "status.h"

typedef void* DATE;

DATE date_init_default(void);

void print_date(DATE hDate);


Status date_set_month(DATE hDate, int month);
Status date_set_day(DATE hDate, int day);
Status date_set_year(DATE hDate, int year);
