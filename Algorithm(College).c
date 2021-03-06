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
	for (int i = 0; i < tag; i++)
		catalogueNumber = catalogueNumber * va_arg (valist, int);
		
va_end (valist);	
	
	return catalogueNumber;
}

int searchNumber () {

int i = 0, value[n], searchNumber = 1;
char *sSport, *sStreet, *sYellow, *sRed, *sLowCost, *sMediumCost, *sHighCost;

char str[100];
	fflush (stdin);
	gets (str);

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
	for (int j = 0; j < i; j++)
		searchNumber = searchNumber * value[j];
		
	return searchNumber;
}

bool search (int catalogueN, int searchN) {
	if (catalogueN % searchN == 0){
		return 1;
	}	else return 0;
}

void line () {
	printf (" _____________________________________________________________________________________________________________________\n");
}

void layout () {
	
	//right corner position function
	void rightCorner (char str[]) {
		printf ("                                                                                                   | %s\n", str);
	}
	
	//header
	line ();
	
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
	printf ("(?) Press \"ENTER\" to start a search...                                                             | -highCost\n");
			
	//bottomLine	
	line ();

	//search
	printf ("|Search: ");
}

void space () {
	printf("\n\n\n\n\n");
}

int main () {
	
int store[s], srchNumber, k;
bool occur[s], again;

	layout ();

	store[0] = catalogueNumber (3, sport, red, lowCost);
	store[1] = catalogueNumber (5, sport, red, mediumCost, street, yellow);
	store[2] = catalogueNumber (4, sport, yellow, red, street);
	store[3] = catalogueNumber (2, sport, red);
	store[4] = catalogueNumber (2, sport, yellow);
	store[5] = catalogueNumber (1, sport);
	store[6] = catalogueNumber (2, sport, yellow);
	store[7] = catalogueNumber (2, sport, yellow);
	store[8] = catalogueNumber (1, street);
	store[9] = catalogueNumber (2, highCost, yellow);

	do {
		//store names
		char storeName[s][20] = {"Store1", "Store2", "Store3", "Store4", "Store5", "Store6", "Store7", "Store8", "Store9", "Store10"};
		k = 0;
		srchNumber = searchNumber ();	
		
		//checking if the search is valid
		if (srchNumber != 1) {
			//searching
			for (int i = 0; i < s; i++) 
				occur[i] = search (store[i], srchNumber);		

 			space ();
 			
			for (int i = 0; i < s; i++) {
				if (occur[i]) {
					printf ("                        %s", storeName[i]);
					k++;
				}
				
				if (k == 3) {
					space ();
					k = 0;
				}
			}
			
			space ();
	
			printf ("\n(?) Type \"1\" to make a new search...\n"); //searchNote
			line ();
				
			scanf ("%d", &again);
		}	else {
				printf ("\nError\n");
				again = 1;
		  	}
		  	
		if (again) 
			layout (); 
	} while (again);
}
