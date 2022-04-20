#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define n 7 //number of tags
#define s 10 //number of stores

//using "stdarg.h" in order to determine, when calling the function, how many arguments it contains
int storeSorting (int tag,...) {

va_list valist;

int catalogueNumber = 1;

va_start (valist, tag);

//calculating catalogueNumber
	for(int i = 0; i < tag; i++)
		catalogueNumber = catalogueNumber * va_arg(valist, int);
		
va_end(valist);	
	
	return catalogueNumber;
}

int tagSearching () {

int i = 0, value[n], searchNumber = 1;
char division;

//execute until user types ".", which starts the search
	while (division != '.'){
	char str[100], *sport, *street, *yellow, *red, *lowCost, *mediumCost, *highCost;
		fflush(stdin);
		gets(str);

//checking for a substring
	sport = strstr (str, "sport");
	street = strstr (str, "street");
	yellow = strstr (str, "yellow");
	red = strstr (str, "red");
	lowCost = strstr (str, "lowCost");
	mediumCost = strstr (str, "mediumCost");
	highCost = strstr (str, "highCost");
			
		if (sport != NULL) {
			value[i] = 2;
			i++;
		}	if (street != NULL) {
				value[i] = 3;
				i++;
			}	if (yellow != NULL) {
					value[i] = 5;
					i++;
				}	if (red != NULL) {
						value[i] = 7;
						i++;
					}	if (lowCost != NULL) {
							value[i] = 11;
							i++;
						}	if (mediumCost != NULL) {
								value[i] = 13;
								i++;
							}	if (highCost != NULL) {
									value[i] = 17;
									i++;
								}

//scanning "division" to determine if the user wants to add more tags or search				
		scanf("%c", &division);	
	}

//calculating searchNumber
	for(int j = 0; j < i; j++)
		searchNumber = searchNumber * value[j];
		
	return searchNumber;
}

int main () {
	
//tags
int	sport = 2, street = 3, yellow = 5, red = 7, lowCost = 11, mediumCost = 13, highCost = 17;

int store[s], snumber;

	store[0] = storeSorting (3, sport, red, mediumCost);
	store[1] = storeSorting (5, sport, red, mediumCost, street, yellow);
	
	printf("%d\n", store[0]);
	printf("%d\n", store[1]);
	
	snumber = tagSearching ();
	
	printf("%d", snumber);	
}
