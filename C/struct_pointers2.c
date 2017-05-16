#include <stdio.h>
typedef struct book
{
	int dop;
};

int main()
{
	struct book *pBook, book1;
	pBook = &book1;          
	book1.dop = 22;
	printf("%d\n", pBook->dop);
	return 0;
}
