#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

#define n 7 //number of tags
#define s 10 //number of stores

//tags
int sport = 2, street = 3, yellow = 5, red = 7, lowCost = 11, mediumCost = 13, highCost = 17;

//using "stdarg.h" in order to determine, when calling the function, how many arguments it contains
int catalogueNumber (int tag,...) {

va_list valist;

int catalogueNumber = 1;

va_start (valist, tag);

	//calculating catalogueNumber
	for(int i = 0; i < tag; i++)
		catalogueNumber = catalogueNumber * va_arg(valist, int);
		
va_end(valist);	
	
	return catalogueNumber;
}

int searchNumber () {

int i = 0, value[n], searchNumber = 1;
char *sSport, *sStreet, *sYellow, *sRed, *sLowCost, *sMediumCost, *sHighCost;

char str[100];
	fflush(stdin);
	gets(str);

	//checking for substrings
	sSport = strstr (str, "sport");
	sStreet = strstr (str, "street");
	sYellow = strstr (str, "yellow");
	sRed = strstr (str, "red");
	sLowCost = strstr (str, "lowCost");
	sMediumCost = strstr (str, "mediumCost");
	sHighCost = strstr (str, "highCost");
		
		if (sSport != NULL) {
			value[i] = sport;
			i++;
		}	if (sStreet != NULL) {
				value[i] = street;
				i++;
			}	if (sYellow != NULL) {
					value[i] = yellow;
					i++;
				}	if (sRed != NULL) {
						value[i] = red;
						i++;
					}	if (sLowCost != NULL) {
							value[i] = lowCost;
							i++;
						}	if (sMediumCost != NULL) {
								value[i] = mediumCost;
								i++;
							}	if (sHighCost != NULL) {
									value[i] = highCost;
									i++;
								}

	//calculating searchNumber
	for(int j = 0; j < i; j++)
		searchNumber = searchNumber * value[j];
		
	return searchNumber;
}

void layout () {
	
	//right corner position function
	void rightCorner (char str[]) {
		printf("                                                                                                   | %s\n", str);
	}
	
	//header
	printf(" _____________________________________________________________________________________________________________________\n");
	
	rightCorner (""); //skipLine
	rightCorner ("Available Tags:");
	rightCorner ("");
	rightCorner ("-sport");
	rightCorner ("-street");
	rightCorner ("-yellow");
	rightCorner ("-red");
	rightCorner ("-lowCost");
	rightCorner ("-mediumCost");
	
	//searchNote
	printf("(?) Press \"ENTER\" to start a search...                                                             | -highCost\n");
			
	//bottomLine	
	printf(" _____________________________________________________________________________________________________________________\n");

	//search
	printf("|Search: ");
}

int main () {
	
int store[s], srchNumber;
bool again;

	layout ();

	store[0] = catalogueNumber (3, sport, red, mediumCost);
	store[1] = catalogueNumber (5, sport, red, mediumCost, street, yellow);

	do {
		srchNumber = searchNumber ();
		
		//checking if the search is valid
		if (srchNumber != 1) {
			printf("\n%d\n", srchNumber);	
	
			printf("\n(?) Type \"1\" to make a new search...\n"); //searchNote	
			scanf("%d", &again);
		}	else {
				printf("\nError\n");
				again = 1;
		  	}
		  	
		if (again) 
			layout (); 
	} while (again);
}
