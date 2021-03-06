#include "readFiles.h"

//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°VERIFICA O TOKEN DO FICHEIROπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
int scanKey(char *line, char *key){
    for(int i=0; i<strlen(key);i++){
        if(line[i]!=key[i]){
            return INCORRECT_KEY;
        }
    }
    return CORRECT_KEY;
}

/*π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
 *π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
 *π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«  LEITURA DO MENU π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
 *π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
 *π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*/

void readMenu(){
    FILE *menu;
    char line[MAX_LINE];
    char tempPATH[MAX_PATH]="";
    strcat(tempPATH,PATH);
    menu = fopen(strcat(tempPATH,"Menu.txt"), "r");
    if (menu == NULL){
        printf("Could not open file Menu.txt");
    }else{
        while(fgets(line, MAX_LINE, menu) != NULL){
            printf("%s",line);
        }
    }
    fclose(menu);
}

/*π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
 *π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
 *π«π«π«π«π«π«π«π«π«π«π«π«LEITURA DAS CIDADES & PDIsπ«π«π«π«π«π«π«π«π«π«π«π«π«*
 *π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
 *π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*/

Cities readCities(){
    FILE *fp;
    char tempPATH[MAX_PATH], line[MAX_LINE], key[MAX_LINE];
    char cityName[MAX_NAME], cityCountry[MAX_NAME], cityCurrency[MAX_CURRENCY];
    char IPName[MAX_NAME], IPCategory[MAX_ADDRESS], IPDescription[MAX_DESCRIPTION],IPSchedule[7][MAX_SCHEDULE],IPAddress[MAX_ADDRESS],IPPhone[MAX_PHONE];
    int IPPrice = 0;
    
    Cities cities = createCitiesList();
    IPs places = createIPList();
    strcpy(tempPATH,PATH);
    fp = fopen(strcat(tempPATH,"Cities&IPs.txt"), "r");
    if (fp == NULL){
        printf("Could not open file");
    }else{
        while(fgets(line, MAX_LINE, fp) != NULL){
            
            /*π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
             *π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
             *π«π«π«π«π«π«π«π«π«π«π«π«LEITURA DAS CIDADESπ«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
             *π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
             *π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*/
            
            strcpy(key, "@");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA NOMEπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(cityName,line+strlen(key));
            }
            strcpy(key, "#");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA PAΓSπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(cityCountry,line+strlen(key));
            }
            strcpy(key, "Β§");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA MOEDAπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(cityCurrency,line+strlen(key));
                places = createIPList();
                insertCitiesList(cities,cityName,cityCountry,cityCurrency,places,0,BY_NAME);
            }
 
            /*π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
             *π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
             *π«π«π«π«π«π«π«π«π«π«π«π«LEITURA PONTOS DE INTERESSEπ«π«π«π«π«π«π«π«π«π«π«π«π«*
             *π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
             *π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*/

             
            strcpy(key, "Name: ");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA NOME PDIπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(IPName,line+strlen(key));
            }
            strcpy(key, "- Category: ");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA CATEGORIAπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(IPCategory,line+strlen(key));
            }
            strcpy(key, "- Price: ");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA PRECOπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
            if(scanKey(line,key)==CORRECT_KEY){
                IPPrice = atoi(line+strlen(key));
            }
            strcpy(key, "- Description: ");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA DESCRICAOπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(IPDescription,line+strlen(key));
            }
            strcpy(key, "\t_Monday: ");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA HORARIOπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(IPSchedule[Monday],line+strlen(key));
            }
            strcpy(key, "\t_Tuesday: ");
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(IPSchedule[Tuesday],line+strlen(key));
            }
            strcpy(key, "\t_Wednesday: ");
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(IPSchedule[Wednesday],line+strlen(key));
            }
            strcpy(key, "\t_Thursday: ");
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(IPSchedule[Thursday],line+strlen(key));
            }
            strcpy(key, "\t_Friday: ");
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(IPSchedule[Friday],line+strlen(key));
            }
            strcpy(key, "\t_Saturday: ");
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(IPSchedule[Saturday],line+strlen(key));
            }
            strcpy(key, "\t_Sunday: ");
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(IPSchedule[Sunday],line+strlen(key));
            }
            strcpy(key, "- Address: ");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA MORADAπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(IPAddress,line+strlen(key));
            }
            strcpy(key, "- Phone: ");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA TELEFONEπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(IPPhone,line+strlen(key));
                insertIPList(searchCitiesList(cities, cityName)->places,IPName,IPCategory,IPPrice,IPDescription,IPSchedule, IPAddress,IPPhone,0,0,BY_NAME);
            }
        }
    }
    fclose(fp);
    return cities;
}

Cities readCitiesPopularity(){
    FILE *fp;
    char tempPATH[MAX_PATH], line[MAX_LINE], key[MAX_LINE], userCityName[MAX_NAME];
    Cities city,cities = readCities();
    strcpy(tempPATH,PATH);
    fp = fopen(strcat(tempPATH,"Users.txt"), "r");
    if (fp == NULL){
        printf("Could not open file");
    }else{
        while(fgets(line, MAX_LINE, fp) != NULL){
            strcpy(key, "@");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA CIDADES FAVORITASπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(userCityName,line+strlen(key));
                city = searchCitiesList(cities, userCityName);
                city->popularity++;
                deleteCitiesList(cities, userCityName);
                insertCitiesList(cities, city->name, city->country, city->currency, city->places, city->popularity,BY_NAME);
            }
        }
    }
    fclose(fp);
    return cities;
}

Cities readPopularity(){
    FILE *fp;
    char tempPATH[MAX_PATH], line[MAX_LINE], key[MAX_LINE], cityName[MAX_NAME],userIPName[MAX_NAME];
    Cities auxCities=createCitiesList(),cities = readCitiesPopularity();
    IPs places;
    int hotCounter=0, popularity=0;
    strcpy(tempPATH,PATH);
    strcat(tempPATH, "Users.txt");
    cities=cities->next;
    while (cities) {
        insertCitiesList(auxCities, cities->name, cities->country, cities->currency, createIPList(), cities->popularity,BY_NAME);
        places = cities->places;
        places = places->next;
        while(places){
            hotCounter=0;
            popularity=0;
            fp = fopen(tempPATH, "r");
            if (fp == NULL){
                printf("Could not open file");
            }else{
                while(fgets(line, MAX_LINE, fp) != NULL){
                    strcpy(cityName,cities->name);
                    strcpy(key, "Β°Β°Β°");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA PDI HOTπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
                    if(scanKey(line,key)==CORRECT_KEY){
                        strcpy(userIPName,line+strlen(key));
                        if(strcmp(userIPName,places->name)==0){
                            hotCounter++;
                        }
                    }
                    strcpy(key, "#");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA PDI FAVORITASπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
                    if(scanKey(line,key)==CORRECT_KEY){
                        strcpy(userIPName,line+strlen(key));
                        if(strcmp(userIPName,places->name)==0){
                            popularity++;
                        }
                    }
                    
                }
            }
            insertIPList(searchCitiesList(auxCities, cityName)->places,places->name,places->category,places->price,places->description,places->schedule, places->address,places->phone,hotCounter,popularity, BY_NAME);
            fclose(fp);
            places = places->next;
        }
        cities = cities->next;
    }
    return auxCities;
}

/*π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
 *π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
 *π«π«π«π«π«π«π«π«π«π«π«π«LEITURA DOS UTILIZADORESπ«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
 *π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*
 *π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«π«*/


Users readUsers(){
    FILE *fp;
    char tempPATH[MAX_PATH], line[MAX_LINE], key[MAX_LINE];
    char userName[MAX_NAME], userAddress[MAX_ADDRESS], userBirth[MAX_DESCRIPTION],userPhone[MAX_PHONE];
    Users users = createUsersList();
    strcpy(tempPATH,PATH);
    fp = fopen(strcat(tempPATH,"Users.txt"), "r");
    if (fp == NULL){
        printf("Could not open file");
    }else{
        while(fgets(line, MAX_LINE, fp) != NULL){
            strcpy(key, "Name: ");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA NOME USERπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(userName,line+strlen(key));
            }
            strcpy(key, "- Address: ");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA MORADAπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(userAddress,line+strlen(key));
            }
            strcpy(key, "- Birth: ");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA DATA ANIVERSARIOπ°π°π°π°π°π°π°π°π°π°
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(userBirth,line+strlen(key));
            }
            strcpy(key, "- Phone: ");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA TELEFONEπ°π°π°π°π°π°π°π°π°π°π°π°π°π°
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(userPhone,line+strlen(key));
                insertUsersList(users,userName,userAddress,userBirth,userPhone, createCitiesList(), createIPList(), createIPList());
            }
        }
    }
    fclose(fp);
    return users;
}

Users readUsersPreferences(){
    FILE *fp;
    char tempPATH[MAX_PATH], line[MAX_LINE], key[MAX_LINE];
    char userName[MAX_NAME],userCityName[MAX_NAME],userPlaceName[MAX_NAME];
    Users users = readUsers();
    Cities cities;
    IPs hotIP, places;
    strcpy(tempPATH,PATH);
    fp = fopen(strcat(tempPATH,"Users.txt"), "r");
    if (fp == NULL){
        printf("Could not open file");
    }else{
        while(fgets(line, MAX_LINE, fp) != NULL){
            strcpy(key, "Name: ");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA NOME USERπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(userName,line+strlen(key));
            }
            strcpy(key, "@");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA CIDADES FAVORITASπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
            cities = readPopularity();
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(userCityName,line+strlen(key));
                while (cities) {
                    if(strcmp(cities->name,userCityName)==0){
                        insertCitiesList(searchUsersList(users, userName)->favoriteCities , cities->name, cities->country, cities->currency, cities->places,cities->popularity,BY_NAME);
                    }
                    cities = cities->next;
                }
            }
            strcpy(key, "Β°Β°Β°");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA DO PDI HOTπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
            cities = readPopularity();
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(userPlaceName,line+strlen(key));
                while (cities) {
                    hotIP = cities->places;
                    while (hotIP) {
                        if(strcmp(hotIP->name,userPlaceName)==0){
                            insertIPList(searchUsersList(users, userName)->hotIP , hotIP->name,hotIP->category,hotIP->price,hotIP->description,hotIP->schedule,hotIP->address,hotIP->phone,hotIP->hotCounter,hotIP->normalCounter, BY_NAME);
                        }
                        hotIP = hotIP->next;
                    }
                    cities = cities->next;
                }
            }
            strcpy(key, "#");//π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°LEITURA DOS PDI's FAVORITOSπ°π°π°π°π°π°π°π°π°π°π°π°π°π°π°π°
            cities = readPopularity();
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(userPlaceName,line+strlen(key));
                while (cities) {
                    places = cities->places;
                    while (places) {
                        if(strcmp(places->name,userPlaceName)==0){
                            insertIPList(searchUsersList(users, userName)->favoriteIPs , places->name,places->category,places->price,places->description,places->schedule,places->address,places->phone,places->hotCounter,places->normalCounter,BY_NAME);
                        }
                        places = places->next;
                    }
                    cities = cities->next;
                }
            }
        }
    }
    fclose(fp);
    return users;
}
