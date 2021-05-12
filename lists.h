#ifndef lists_h
#define lists_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#define CITIES_ONLY 0
#define CITIES_WITH_IP 1
#define BY_NAME 0
#define BY_POPULARITY 1
#define MAX_LINE 1000
#define MAX_NAME 50
#define MAX_ADDRESS 100
#define MAX_DESCRIPTION 1000
#define MAX_SCHEDULE 15
#define MAX_BIRTH_DATE 12
#define MAX_PHONE 21
#define MAX_CURRENCY 6
#define MAX_POPULARITY 1000

enum weekDays {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

typedef struct IPList *IPs;
typedef struct IPList {
    char name[MAX_NAME];
    char category[MAX_ADDRESS];
    int price;
    char description[MAX_DESCRIPTION];
    char schedule[7][MAX_SCHEDULE];
    char address[MAX_ADDRESS];
    char phone[MAX_PHONE];
    int hotCounter;
    int normalCounter;
    int popularity;
    IPs next;
}InterestPoint;

typedef struct cityList *Cities;
typedef struct cityList {
    char name[MAX_NAME];
    char country[MAX_NAME];
    char currency[MAX_CURRENCY];
    IPs places;
    int popularity;
    Cities next;
}City;

typedef struct userList *Users;
typedef struct userList {
    char name[MAX_NAME];
    char address[MAX_ADDRESS];
    char birth[MAX_BIRTH_DATE];
    char phone[MAX_PHONE];
    Cities favoriteCities;
    IPs hotIP;
    IPs favoriteIPs;
    Users next;
}User;

Cities createCitiesList(void);
void insertCitiesList(Cities list, char *name,char *country,char *currency, IPs places, int popularity,  int sortingMode);
int emptyCitiesList(Cities list);
Cities destroyCitiesList(Cities list);
int fullCitiesList(Cities list);
void searchInCitiesList(Cities list, char *key, Cities *previous, Cities *actual);
void searchInCitiesListByPopularity(Cities list, int key, Cities *previous, Cities *actual);
void deleteCitiesList(Cities list, char *item);
Cities searchCitiesList(Cities list, char *item);
void printCitiesList(Cities List, int mode);
int countCities(Cities list);

IPs createIPList(void);
void insertIPList(IPs list, char *name, char *category, int price,char *description, char schedule[7][MAX_SCHEDULE], char *address, char *phone, int hotCounter, int normalCounter, int sortingMode);
int emptyIPList(IPs list);
IPs destroyIPList(IPs list);
int fullIPList(IPs list);
void searchInIPList(IPs list, char *key, IPs *previous, IPs *actual);
void searchInIPListByPopularity(IPs list, int key, IPs *previous, IPs *actual);
void deleteIPList(IPs list, char *item);
IPs searchIPList(IPs list, char *item);
void printIPList(IPs List);
int countIPs(IPs list);

Users createUsersList(void);
void insertUsersList(Users list, char *name, char *address, char *birth ,char *phone,  Cities favoriteCities, IPs hotIP, IPs favoriteIPs);
int emptyUsersList(Users list);
Users destroyUsersList(Users list);
int fullUsersList(Users list);
void searchInUsersList(Users list, char *key, Users *previous, Users *actual);
void deleteUsersList(Users list, char *item);
Users searchUsersList(Users list, char *item);
void printUsersList(Users List);
int countUsers(Users list);



#endif /* lists_h */
