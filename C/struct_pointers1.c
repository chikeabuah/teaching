#include <stdio.h>
#include <string.h>


struct Books {
	int dop;
	char title[50];
};

struct Books book1;

void printStr(struct Books *book) {
	printf("%d\n", book->dop);
	printf("%s\n", book->title);
}

int main(int argc, char * argv[]){
	book1.dop = 1984;
	strcpy(book1.title, "Yarry Nutter");
	printStr(&book1);
	return 0;
}

