#ifndef readFiles_h
#define readFiles_h

#include <stdio.h>
#include <string.h>
#include "lists.h"

#define CORRECT_KEY 1
#define INCORRECT_KEY 0
#define MAX_PATH 200
#define PATH ""

int scanKey(char *line, char *key);

void readMenu(void);
Cities readCities(void);
Cities readCitiesPopularity(void);
Cities readPopularity(void);
Users readUsers(void);
Users readUsersPreferences(void);
#endif /* readFiles_h */
