#include "readFiles.h"

//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰VERIFICA O TOKEN DO FICHEIRO🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
int scanKey(char *line, char *key){
    for(int i=0; i<strlen(key);i++){
        if(line[i]!=key[i]){
            return INCORRECT_KEY;
        }
    }
    return CORRECT_KEY;
}

/*🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫  LEITURA DO MENU 🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*/

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

/*🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫LEITURA DAS CIDADES & PDIs🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*/

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
            
            /*🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
             *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
             *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫LEITURA DAS CIDADES🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
             *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
             *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*/
            
            strcpy(key, "@");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA NOME🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(cityName,line+strlen(key));
            }
            strcpy(key, "#");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA PAÍS🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(cityCountry,line+strlen(key));
            }
            strcpy(key, "§");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA MOEDA🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(cityCurrency,line+strlen(key));
                places = createIPList();
                insertCitiesList(cities,cityName,cityCountry,cityCurrency,places,0,BY_NAME);
            }
 
            /*🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
             *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
             *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫LEITURA PONTOS DE INTERESSE🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
             *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
             *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*/

             
            strcpy(key, "Name: ");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA NOME PDI🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(IPName,line+strlen(key));
            }
            strcpy(key, "- Category: ");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA CATEGORIA🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(IPCategory,line+strlen(key));
            }
            strcpy(key, "- Price: ");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA PRECO🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            if(scanKey(line,key)==CORRECT_KEY){
                IPPrice = atoi(line+strlen(key));
            }
            strcpy(key, "- Description: ");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA DESCRICAO🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(IPDescription,line+strlen(key));
            }
            strcpy(key, "\t_Monday: ");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA HORARIO🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
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
            strcpy(key, "- Address: ");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA MORADA🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(IPAddress,line+strlen(key));
            }
            strcpy(key, "- Phone: ");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA TELEFONE🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
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
            strcpy(key, "@");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA CIDADES FAVORITAS🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
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
                    strcpy(key, "°°°");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA PDI HOT🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
                    if(scanKey(line,key)==CORRECT_KEY){
                        strcpy(userIPName,line+strlen(key));
                        if(strcmp(userIPName,places->name)==0){
                            hotCounter++;
                        }
                    }
                    strcpy(key, "#");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA PDI FAVORITAS🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
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

/*🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫LEITURA DOS UTILIZADORES🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*/


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
            strcpy(key, "Name: ");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA NOME USER🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(userName,line+strlen(key));
            }
            strcpy(key, "- Address: ");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA MORADA🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(userAddress,line+strlen(key));
            }
            strcpy(key, "- Birth: ");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA DATA ANIVERSARIO🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(userBirth,line+strlen(key));
            }
            strcpy(key, "- Phone: ");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA TELEFONE🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
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
            strcpy(key, "Name: ");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA NOME USER🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            if(scanKey(line,key)==CORRECT_KEY){
                strcpy(userName,line+strlen(key));
            }
            strcpy(key, "@");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA CIDADES FAVORITAS🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
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
            strcpy(key, "°°°");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA DO PDI HOT🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
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
            strcpy(key, "#");//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LEITURA DOS PDI's FAVORITOS🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
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
