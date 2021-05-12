#include <string.h>
#include "lists.h"

/*🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫OPERACOES LISTAS CIDADES🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*/

Cities createCitiesList(){
    Cities aux;
    aux = (Cities) malloc (sizeof (City));
    if (aux != NULL) {
        strcpy(aux->name, "NULL\n");
        strcpy(aux->country, "NULL\n");
        strcpy(aux->currency, "NULL\n");
        aux->places = createIPList();
        aux->popularity = 0;
        aux->next = NULL;
    }
    return aux;
}

int emptyCitiesList(Cities list){
    return (list->next == NULL ? 1 : 0);
}

Cities destroyCitiesList(Cities list){
    Cities tempPtr;
    while (emptyCitiesList(list) == 0) {
        tempPtr = list;
        list = list->next;
        free(tempPtr);
    }
    free(list);
    return NULL;
}

int fullCitiesList(Cities list){
    return 0;
}

void searchInCitiesList(Cities list, char *key, Cities *previous, Cities *actual) {
    *previous = list;
    *actual = list->next;
    while ((*actual) != NULL && (strcmp((*actual)->name,key)<0)) {
        *previous = *actual;
        *actual = (*actual)->next;
    }
    if ((*actual) != NULL && strcmp((*actual)->name,key) != 0){
        *actual = NULL;
    }
}

void searchInCitiesListByPopularity(Cities list, int key, Cities *previous, Cities *actual) {
    *previous = list;
    *actual = list->next;
    while ((*actual) != NULL && (*actual)->popularity > key){
        *previous = *actual;
        *actual = (*actual)->next;
    }
    if ((*actual) != NULL && (*actual)->popularity != key){
        *actual = NULL;
    }
}

void insertCitiesList(Cities list, char *name, char *country, char *currency, IPs places, int popularity, int sortingMode){
    Cities new;
    Cities previous, useless;
    new = (Cities) malloc(sizeof(City));
    if (new != NULL) {
        memmove(new->name,name,strlen(name) + 1);               //strcpy(new->name,name);
        memmove(new->country,country,strlen(country) + 1);      //strcpy(new->country,country);
        memmove(new->currency,currency,strlen(currency) + 1);   //strcpy(new->currency,currency);
        new->places=places;
        new->popularity = popularity;
        switch (sortingMode) {
            case BY_POPULARITY:
                searchInCitiesListByPopularity(list, popularity, &previous, &useless);
                break;
            default:
                searchInCitiesList(list, name, &previous, &useless);
                break;
        }
        new->next = previous->next;
        previous->next = new;
    }
}
void deleteCitiesList(Cities list, char *item){
    Cities previous;
    Cities actual;
    searchInCitiesList(list, item, &previous, &actual);
    if (actual != NULL) {
        previous->next = actual->next;
        free(actual);
    }
}

Cities searchCitiesList(Cities list, char *item){
    Cities previous;
    Cities actual;
    searchInCitiesList(list, item, &previous, &actual);
    return (actual);
}

void printCitiesList(Cities list, int mode){
    Cities l = list->next;
    while (l){
        switch (mode){
            case CITIES_WITH_IP:
                printf("%s", l->name);
                printIPList(l->places);
                break;
            default:
                printf("\t%s", l->name);
                break;
        }
        l=l->next;
    }
}

int countCities(Cities list){
    Cities l = list->next;
    int i=0;
    while (l){
        i++;
        l=l->next;
    }
    return i;
}

/*🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫OPERACOES LISTAS PONTOS DE INTERESSE🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*/

IPs createIPList(){
    IPs aux;
    aux = (IPs) malloc (sizeof(InterestPoint));
    if (aux != NULL) {
        strcpy(aux->name, "NULL\n");
        strcpy(aux->category, "NULL\n");
        aux->price = 0;
        strcpy(aux->description, "NULL\n");
        for(int day=0; day<7;day++){
            strcpy(aux->schedule[day], "NULL\n");
        }
        strcpy(aux->address, "NULL\n");
        strcpy(aux->phone, "NULL\n");
        aux->hotCounter = 0;
        aux->normalCounter=0;
        aux->popularity = 0;
        aux->next = NULL;
    }
    return aux;
}

int emptyIPList(IPs list){
    return (list->next == NULL ? 1 : 0);
}

IPs destroyIPList(IPs list){
    IPs tempPtr;
    while (emptyIPList(list) == 0) {
        tempPtr = list;
        list = list->next;
        free(tempPtr);
    }
    free(list);
    return NULL;
}

int fullIPList(IPs list){
    return 0;
}

void searchInIPList(IPs list, char *key, IPs *previous, IPs *actual) {
    *previous = list;
    *actual = list->next;
    while ((*actual) != NULL && (strcmp((*actual)->name,key)<0)) {
        *previous = *actual;
        *actual = (*actual)->next;
    }
    if ((*actual) != NULL && strcmp((*actual)->name,key) != 0){
        *actual = NULL;
    }
}

void searchInIPListByPopularity(IPs list, int key,IPs *previous, IPs *actual) {
    *previous = list;
    *actual = list->next;
    while ((*actual) != NULL && ((*actual)->popularity > key)){
        *previous = *actual;
        *actual = (*actual)->next;
    }
    if ((*actual) != NULL && ((*actual)->popularity != key)){
        *actual = NULL;
    }
}

void insertIPList(IPs list,char *name, char *category, int price,char *description, char schedule[7][MAX_SCHEDULE], char *address, char *phone, int hotCounter, int normalCounter, int sortingMode){
    IPs new;
    IPs previous, useless;
    new = (IPs) malloc(sizeof(InterestPoint));
    if (new != NULL) {
        memmove(new->name,name,strlen(name) + 1);                                   //strcpy(new->name,name);
        memmove(new->category, category,strlen(category) + 1);                      //strcpy(new->category, category);
        new->price = price;
        memmove(new->description, description,strlen(description) + 1);             //strcpy(new->description, description);
        for(int day=0; day<7;day++){
            memmove(new->schedule[day], schedule[day],strlen(schedule[day]) + 1);   //strcpy(new->schedule[day], schedule[day]);
        }
        memmove(new->address, address,strlen(address) + 1);                         //strcpy(new->address, address);
        memmove(new->phone, phone,strlen(phone) + 1);                               //strcpy(new->phone, phone);
        new->hotCounter = hotCounter;
        new->normalCounter = normalCounter;
        new->popularity = (MAX_POPULARITY*hotCounter)+normalCounter;
        switch (sortingMode) {
            case BY_POPULARITY:
                searchInIPListByPopularity(list,new->popularity, &previous, &useless);
                break;
            default:
                searchInIPList(list, name, &previous, &useless);
                break;
        }

        new->next = previous->next;
        previous->next = new;
    }
}
void deleteIPList(IPs list, char *item){
    IPs previous;
    IPs actual;
    searchInIPList(list, item, &previous, &actual);
    if (actual != NULL) {
        previous->next = actual->next;
        free (actual);
    }
}

IPs searchIPList(IPs list, char *item){
    IPs previous;
    IPs actual;
    searchInIPList(list, item, &previous, &actual);
    return (actual);
}

void printIPList(IPs list){
    IPs l = list->next;
    while (l){
        printf("\t%s", l->name);
        l=l->next;
    }
}

int countIPs(IPs places){
    int counter=-1;
    while (places) {
        counter++;
        places=places->next;
    }
    return counter;
}
/*🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫OPERACOES LISTAS USERS🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*/


Users createUsersList(){
    Users aux;
    aux = (Users) malloc (sizeof (User));
    if (aux != NULL) {
        strcpy(aux->name, "NULL\n");
        strcpy(aux->address, "NULL\n");
        strcpy(aux->birth, "NULL\n");
        strcpy(aux->phone, "NULL\n");
        aux->favoriteCities = createCitiesList();
        aux->hotIP = createIPList();
        aux->favoriteIPs = createIPList();
        aux->next = NULL;
    }
    return aux;
}

int emptyUsersList(Users list){
    return (list->next == NULL ? 1 : 0);
}

Users destroyUsersList(Users list){
    Users tempPtr;
    while (emptyUsersList(list) == 0) {
        tempPtr = list;
        list = list->next;
        free(tempPtr);
    }
    free(list);
    return NULL;
}

int fullUsersList(Users list){
    return 0;
}

void searchInUsersList(Users list, char *key, Users *previous, Users *actual) {
    *previous = list;
    *actual = list->next;
    while ((*actual) != NULL && (strcmp((*actual)->name,key)<0)) {
        *previous = *actual;
        *actual = (*actual)->next;
    }
    if ((*actual) != NULL && strcmp((*actual)->name,key) != 0){
        *actual = NULL;
    }
}

void insertUsersList(Users list,char *name, char *address, char *birth, char *phone, Cities favoriteCities, IPs hotIP, IPs favoriteIPs){
    Users new;
    Users previous, useless;
    new = (Users) malloc(sizeof(User));
    if (new != NULL) {
        memmove(new->name,name,strlen(name) + 1);                   //strcpy(new->name,name);
        memmove(new->address, address,strlen(address) + 1);         //strcpy(new->address, address);
        memmove(new->birth, birth,strlen(birth) + 1);               //strcpy(new->birth, birth);
        memmove(new->phone, phone,strlen(phone) + 1);               //strcpy(new->phone, phone);
        new->favoriteCities = favoriteCities;
        new->hotIP = hotIP;
        new->favoriteIPs = favoriteIPs;
        searchInUsersList(list, name, &previous, &useless);
        new->next = previous->next;
        previous->next = new;
    }
}
void deleteUsersList(Users list, char *item){
    Users previous;
    Users actual;
    searchInUsersList(list, item, &previous, &actual);
    if (actual != NULL) {
        previous->next = actual->next;
        free (actual);
    }
}

Users searchUsersList(Users list, char *item){
    Users previous;
    Users actual;
    searchInUsersList(list, item, &previous, &actual);
    return (actual);
}

void printUsersList(Users list){
    Users l = list->next;
    while (l){
        printf("\t%s", l->name);
        l=l->next;
    }
}

int countUsers(Users users){
    int counter=-1;
    while(users) {
        counter++;
        users=users->next;
    }
    return counter;
}
