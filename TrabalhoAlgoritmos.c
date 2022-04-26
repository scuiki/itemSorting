#include <stdio.h>
#include <stdarg.h>
#include <string.h>

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
char *sSport, *sStreet, *sYellow, *sRed, *sLowCost, *sMediumCost, *sHighCost, *sEnd;

	//executing while string doesn't contain "."
	do {
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
		sEnd = strstr (str, ".");
				
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
	} while (sEnd == NULL);

	//calculating searchNumber
	for(int j = 0; j < i; j++)
		searchNumber = searchNumber * value[j];
		
	return searchNumber;
}

int main () {
	
int store[s], srchNumber;

	store[0] = catalogueNumber (3, sport, red, mediumCost);
	store[1] = catalogueNumber (5, sport, red, mediumCost, street, yellow);
	
	printf("%d\n", store[0]);
	printf("%d\n", store[1]);
	
	srchNumber = searchNumber ();
	
	printf("%d", srchNumber);	
}
