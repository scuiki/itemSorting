#include <stdio.h>
#include <stdarg.h>

#define n 7 //number of tags
#define s 10 //number of stores

int storeSorting (int tag,...) {

va_list valist;

int catalogueNumber = 1, i = 0, store;

va_start (valist, tag);

	for(int i = 0; i < tag; i++)
		catalogueNumber = catalogueNumber * va_arg(valist, int);
		
va_end(valist);	
		
		store = catalogueNumber;
	
	return store;
}

int main () {
	

int	sport = 2;
int	street = 3;
int	yellow = 5;
int	red = 7;
int	lowCost = 11;
int	mediumCost = 13;
int	highCost = 17;

int store[s];

	store[0] = storeSorting (3, sport, red, mediumCost);
	store[1] = storeSorting (5, sport, red, mediumCost, street, yellow);
	
	printf("%d", store[0]);
	printf("\n%d", store[1]);
}
