#include <stdio.h>
struct book
{
	int dop;
}book1, *pBook;

int main()
{
	pBook = &book1;          
	book1.dop = 22;
	printf("%d\n", pBook->dop);
	return 0;
}
