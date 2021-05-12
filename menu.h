#ifndef menu_h
#define menu_h

#define THIS_YEAR 2019
#define MAX_TERMINAL 50
#define MAX_FAV_CITIES 3
#define MAX_TRIP_IP 3

#include <stdio.h>
#include <string.h>
#include "lists.h"
#include "readFiles.h"

enum mode{DEFAULT,REGISTER,EDITUSER,ADDCITY,ADDHOTIP,ADDIP,REMOVEUSER,REMOVECITY,REMOVEHOTIP,REMOVEIP,LISTING,SIMULATION,EXIT};
void pressEnterToContinue(void);
int authentication(char *key);
void writeToUserFile(Users users);
void init(void);


#endif /* menu_h */
