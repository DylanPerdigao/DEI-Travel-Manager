#include "menu.h"

//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰    "LIMPAR" O TERMINAL
void clearTerminal(){
    for(int i=0;i<MAX_TERMINAL;i++){
        printf("\n");
    }
}
//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰    Espera que o utilizador carregue no ENTER para continuar a navegar
void pressEnterToContinue(){
    char choiceInput[1];
    printf("🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰\n");
    printf("\n\t\t\tPRESS ENTER TO CONTINUE\n");
    printf("\n🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰\n");
    gets(choiceInput);
}

//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰    PEDE E RECUPERA UMA OPERACAO VALIDA
int insertValidOperation(){
    char choiceInput[1];
    int choice=0;
    printf("Selecione uma operação valida: ");
    gets(choiceInput);
    choice = atoi(choiceInput);
    return choice;
}
//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰    VERIFICA INPUT NOME
int checkName(char *name){
    int dim = (int) strlen(name);
    char c;
    for(int i=0; i<dim; i++){
        c = *(name+i);
        if(!(isalpha(c) || isspace(c))){
            printf("\nO NOME NAO É VALIDO\n");
            return INCORRECT_KEY;
        }
    }
    return CORRECT_KEY;
}
//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰    PEDE E RECUPERA O NOME DO LOGIN
char* insertLogin(int mode){
    char *userLogin = malloc(MAX_NAME*sizeof(char));
    switch (mode) {
        case REGISTER:
            do{
                printf("\nIntroduza o seu nome: ");
                gets(userLogin);
            }while(checkName(userLogin)==INCORRECT_KEY);
            strcat(userLogin, "\n");
            break;
        case REMOVEUSER:
            printf("\n\nIntroduza o nome do utilizador para removê-lo: ");
            gets(userLogin);
            strcat(userLogin, "\n");
            clearTerminal();
            break;
        default:
            printf("\nIntroduza o seu nome: ");
            gets(userLogin);
            strcat(userLogin, "\n");
            clearTerminal();
            break;
    }
    return userLogin;
}
//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰    VERIFICA INPUT DATA DE NASCIMENTO
int checkBirth(char *birth){
    int day=atoi(birth);
    int month=atoi(birth+3);
    int year=atoi(birth+6);
    if(day<0 ||day>31 || month<0 ||month>12 || year<1900 || year>THIS_YEAR){
        printf("\nA DATA DE NASCIMENTO NAO É VALIDA\n\n");
        return INCORRECT_KEY;
    }else{
        return CORRECT_KEY;
    }
}

//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰    VERIFICA INPUT TELEMOVEL
int checkPhone(char *phone){
    int dim = (int) strlen(phone);
    if(atoi(phone)==0 || dim<9){
        printf("\nO NUMERO DE TELEMOVEL NAO É VALIDO\n\n");
        return INCORRECT_KEY;
    }
    return CORRECT_KEY;
}

//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰    PREENCHER INFORMACOES UTILIZADORES
Users insertUserInformation(Users users, char *name, int mode){
    char address[MAX_ADDRESS];
    char birth[MAX_BIRTH_DATE];
    char phone[MAX_PHONE];
    Users user=createUsersList();
    printf("Introduza a sua morada: ");
    gets(address);
    strcat(address, "\n");
    do{
        printf("Introduza a sua data de nascimento (DD-MM-AAAA): ");
        gets(birth);
    }while(checkBirth(birth)==INCORRECT_KEY);
    strcat(birth, "\n");
    do{
        printf("Introduza o seu numero de telemovel: ");
        gets(phone);
    }while(checkPhone(phone)==INCORRECT_KEY);
    strcat(phone, "\n");
    switch (mode) {
        case EDITUSER:
            user = searchUsersList(users, name);
            deleteUsersList(users, name);
            insertUsersList(users, name, address, birth, phone, user->favoriteCities, user->hotIP, user->favoriteIPs);
            break;
        default:
            insertUsersList(users, name, address, birth, phone, createCitiesList(), createIPList(), createIPList());
            break;
    }
    
    return users;
}

//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰    AUTENTIFICAÇÃO DO UTILIZADOR
int authentication(char *key){
    Users users = readUsers();
    while (users) {
        if (strcmp(users->name,key)==0){
            return CORRECT_KEY;
        }
        users = users->next;
    }
    return INCORRECT_KEY;
}

//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰    CONTADOR DA POPULARIDADE TOTAL DOS PDI'S DE UMA LISTA DE CIDADES
int countIPTotalPopularity(Cities cities){
    int count=0;
    IPs places;
    while(cities){
        places=cities->places;
        while(places){
            count+=places->hotCounter;
            count+=places->normalCounter;
            places=places->next;
        }
        cities=cities->next;
    }
    return count;
}

//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰    CONTADOR DOS ELEMENTOS NAO REPETIDOS DE UM ARRAY
int countArrayElementsWithoutRepetitions(int dim,char array[dim][MAX_NAME]){
    int n=dim;
    for(int i = 0; i < dim; i++){
        for(int j = i+1; j < dim; j++){
            if(strcmp(array[j],array[i])==0){
                n--;
                break;//para nao contar duas vezes triplos, quadruplos, etc..
            }
        }
    }
    return n;
}

//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰    REMOVE CIDADES JA ESCOLLHIDAS PELO O UTILIZADOR
Cities removeUserCitiesFromCities(Cities userCities){
    Cities cities = readCities();
    while (userCities) {
        deleteCitiesList(cities, userCities->name);
        userCities=userCities->next;
    }
    return cities;
}
//🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰    REMOVE PDI's JA ESCOLLHIDOS PELO O UTILIZADOR
Cities removeUserIPsFromCities(IPs userPlaces){
    Cities cities = readPopularity();
    Cities aux=createCitiesList();
    IPs places;
    int count=0, pos=0, flag=0;
    while (cities) {
        count+=countIPs(cities->places);
        cities=cities->next;
    }
    char IPsNames[count][MAX_NAME];
    while (userPlaces) {
        strcpy(IPsNames[pos],userPlaces->name);
        pos++;
        userPlaces=userPlaces->next;
    }
    cities=readCities()->next;
    while (cities) {
        places=cities->places;
        insertCitiesList(aux, cities->name, cities->country, cities->currency, createIPList(), cities->popularity, BY_NAME);
        while(places){
            flag=0;
            for(int i=0;i<count;i++){
                if(strcmp(IPsNames[i],places->name)==0){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                insertIPList(searchCitiesList(aux, cities->name)->places, places->name,places->category,places->price,places->description,places->schedule,places->address,places->phone,places->hotCounter,places->normalCounter, BY_NAME);
            }
            places=places->next;
        }
        cities=cities->next;
    }
    
    return aux;
}

/*🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫 ESTATISTICAS DA VIAGEM  🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*/

float statCities(Cities tripCities){
    Users users = readUsersPreferences();
    Cities userCities;
    int totalUsers = countUsers(users);
    float percentCities=0;
    int x=0;
    char arrayUsers[totalUsers][MAX_NAME];
    tripCities=tripCities->next;
    while (tripCities){
        users=readUsersPreferences();
        while (users) {
            userCities = users->favoriteCities;
            while (userCities) {
                if(strcmp(tripCities->name, userCities->name)==0){
                    strcpy(arrayUsers[x],users->name);
                    x++;
                }
                userCities=userCities->next;
            }
            users=users->next;
        }
        tripCities=tripCities->next;
    }
    x = countArrayElementsWithoutRepetitions(x,arrayUsers);
    percentCities = 100*(float)x / (float) totalUsers;
    return percentCities;
}

float statHotIP(Cities tripCities){
    Users users = readUsersPreferences();
    IPs tripHotIP, userHotIP;
    int totalUsers = countUsers(users);
    float percentHotIP=0.0;
    int x=0;
    char arrayUsers[totalUsers][MAX_NAME];
    tripCities=tripCities->next;
    
    while (tripCities){
        tripHotIP = tripCities->places->next;
        while (tripHotIP) {
            users = readUsersPreferences();
            while (users) {
                if(users->hotIP->next){
                    userHotIP = users->hotIP->next;
                    if(strcmp(tripHotIP->name, userHotIP->name)==0){
                        strcpy(arrayUsers[x],users->name);
                        x++;
                    }
                }
                users=users->next;
            }
            tripHotIP=tripHotIP->next;
        }
        tripCities=tripCities->next;
        
    }
    x = countArrayElementsWithoutRepetitions(x,arrayUsers);
    percentHotIP = 100*(float)x / (float) totalUsers;
    return percentHotIP;
}

float statIPs(Cities tripCities){
    Cities cities = readPopularity();
    int totalIPPopularity=0,tripIPPopularity=0;
    float percentIPs=0;
    
    //STEP 1: total de pontos de preferência dos PdI incluídos
    tripIPPopularity = countIPTotalPopularity(tripCities);
    //STEP 2: total dos pontos de preferência de todos os PdI existentes 
    totalIPPopularity = countIPTotalPopularity(cities);
    
    percentIPs = 100*(float)tripIPPopularity / (float) totalIPPopularity;
    return percentIPs;
}


/*🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫 ESCREVER NO FICHEIRO  🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*/

void writeToUserFile(Users users){
    FILE *userFile;
    char tempPATH[200];
    char tempName[2*MAX_NAME];
    char tempAddress[2*MAX_ADDRESS];
    char tempBirth[2*MAX_BIRTH_DATE];
    char tempPhone[2*MAX_PHONE];
    char tempCityName[MAX_NAME];
    char tempPlaceName[MAX_NAME];
    strcpy(tempPATH,PATH);
    Cities cities;
    IPs hotIP, places;
    userFile = fopen(strcat(tempPATH,"Users.txt"), "w");
    if (userFile == NULL){//--------------------------------------------------------------------Verifica se o ficheiro existe
        printf("Could not open User file");
    }else{
        users=users->next;
        while(users) {//--------------------------------------------------------------------Percorre os utilizadores
            strcpy(tempName,"Name: ");
            strcat(tempName,users->name);
            fputs(tempName, userFile);
            cities = createCitiesList();
            cities = users->favoriteCities;
            cities=cities->next;
            while(cities!=NULL){
                strcpy(tempCityName,"@");
                strcat(tempCityName, cities->name);
                fputs(tempCityName, userFile);
                cities = cities->next;
            }
            hotIP = createIPList();
            hotIP = users->hotIP;
            hotIP=hotIP->next;
            while(hotIP!=NULL){
                strcpy(tempPlaceName,"°°°");
                strcat(tempPlaceName, hotIP->name);
                fputs(tempPlaceName, userFile);
                hotIP = hotIP->next;
            }
            places = createIPList();
            places = users->favoriteIPs;
            places=places->next;
            while(places!=NULL){
                strcpy(tempPlaceName,"#");
                strcat(tempPlaceName, places->name);
                fputs(tempPlaceName, userFile);
                places = places->next;
            }
            strcpy(tempAddress,"- Address: ");
            strcat(tempAddress,users->address);
            fputs(tempAddress, userFile);
            strcpy(tempBirth,"- Birth: ");
            strcat(tempBirth,users->birth);
            fputs(tempBirth, userFile);
            strcpy(tempPhone,"- Phone: ");
            strcat(tempPhone,users->phone);
            fputs(tempPhone, userFile);
            fputs("🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰\n", userFile);
            users=users->next;
        }
        fclose(userFile);
    }
}

/*🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫 MENU DO PROGRAMA  🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*
 *🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫🀫*/

void init(){
    char name[MAX_NAME];
    char userLogin[MAX_NAME];
    char userCityName[MAX_NAME];
    char userPlaceName[MAX_NAME];
    int choice=0;
    int cityCounter=0;
    int placeCounter=0;
    int IPCounter=0;
    Users user;
    Users users=readUsersPreferences();
    Cities cities;
    Cities userCities;
    Cities popularCities;
    Cities tripCities=createCitiesList();
    Cities tripCitiesForStats=createCitiesList();
    IPs places;
    IPs auxPlaces=createIPList();
    IPs otherPlaces;
    IPs userPlaces;
    IPs userHotIP;
    clearTerminal();
    while(choice>=0){
        switch(choice){
                //🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰REGISTO DO UTILIZADOR🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            case REGISTER:
                strcpy(name, insertLogin(REGISTER));
                writeToUserFile(insertUserInformation(users, name, REGISTER));
                clearTerminal();
                printf("OPERAÇÃO EFETUADA COM SUCESSO\n\n");
                choice=DEFAULT;
                break;
                //🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰MODIFICAR INFORMACOES UTILIZADOR🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            case EDITUSER:
                strcpy(userLogin, insertLogin(ADDCITY));
                if (authentication(userLogin)==INCORRECT_KEY){
                    printf("O UTILIZADOR NAO EXISTE!\n\n");
                }else{
                    writeToUserFile(insertUserInformation(users, userLogin, EDITUSER));
                }
                clearTerminal();
                printf("OPERAÇÃO EFETUADA COM SUCESSO\n\n");
                choice=DEFAULT;
                break;
             //🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰ADICIONAR CIDADES FAVORITAS🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            case ADDCITY:
                strcpy(userLogin, insertLogin(ADDCITY));
                if (authentication(userLogin)==INCORRECT_KEY){
                    printf("O UTILIZADOR NAO EXISTE!\n\n");
                }else{
                    user = searchUsersList(users, userLogin);
                    userCities = user->favoriteCities;
                    cityCounter = countCities(userCities);
                    if(cityCounter>=MAX_FAV_CITIES){
                        printf("O UTILIZADOR JA ESCOLHEU AS TRÊS CIDADES!\n\n");
                        choice=DEFAULT;
                        break;
                    }
                    while (cityCounter<MAX_FAV_CITIES && strcmp(userCityName,"\n")!=0) {
                        cities=removeUserCitiesFromCities(userCities);
                        printf("\nLISTA DAS CIDADES ESCOLHIDAS: \n");
                        printCitiesList(userCities, CITIES_ONLY);
                        printf("\n\nEscolha até três das seguintes cidades (copiando o nome). Se quiser menos de 3 cidades, não preencha.\n\n");
                        printCitiesList(cities, CITIES_ONLY);
                        cityCounter++;
                        printf("\nCopie o nome da cidade n°%d: ",cityCounter);
                        gets(userCityName);
                        strcat(userCityName,"\n");
                        while(cities) {
                            if(strcmp(cities->name,userCityName)==0){
                                insertCitiesList(userCities, cities->name, cities->country, cities->currency, cities->places,0, BY_NAME);
                                break;
                            }
                            cities = cities->next;
                        }
                    }
                    deleteUsersList(users, user->name);
                    insertUsersList(users, user->name, user->address, user->birth, user->phone, user->favoriteCities, user->favoriteIPs, user->favoriteIPs);
                    writeToUserFile(users);
                    clearTerminal();
                    printf("OPERAÇÃO EFETUADA COM SUCESSO\n\n");
                }
                choice=DEFAULT;
                break;
                //🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰ADICIONAR PONTO DE INTERESSE HOT🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            case ADDHOTIP:
                strcpy(userLogin, insertLogin(ADDHOTIP));
                if (authentication(userLogin)==INCORRECT_KEY){
                    printf("O UTILIZADOR NAO EXISTE!\n\n");
                }else{
                    placeCounter = countIPs(searchUsersList(users, userLogin)->hotIP);
                    if(placeCounter<1){
                        user = searchUsersList(users, userLogin);
                        userPlaces = user->hotIP;
                        printf("\nO VOSSO PONTO DE INTERESSE: \n");
                        printIPList(userPlaces);
                        cities = readPopularity()->next;
                        printf("\n\nEscolha um unico ponto de interesse (copiando o nome).\n\n");
                        printCitiesList(readCities(), CITIES_WITH_IP);
                        printf("\nCopie o nome do ponto de interesse 'Hot' (EM MAIUSCULAS): ");
                        gets(userPlaceName);
                        strcat(userPlaceName,"\n");
                        placeCounter++;
                        
                        while (cities) {
                            places = cities->places;
                            while (places) {
                                if(strcmp(places->name,userPlaceName)==0){
                                    insertIPList(userPlaces, places->name,places->category,places->price,places->description,places->schedule,places->address,places->phone,0,0, BY_NAME);
                                }
                                places = places->next;
                            }
                            cities = cities->next;
                        }
                        deleteUsersList(users, user->name);
                        insertUsersList(users, user->name, user->address, user->birth, user->phone, user->favoriteCities, userPlaces, user->favoriteIPs);
                        writeToUserFile(users);
                        clearTerminal();
                        printf("OPERAÇÃO EFETUADA COM SUCESSO\n\n");
                    }else{
                        printf("O PONTO DE INTERESSE JÁ FOI ESCOLHIDO\n\n");
                    }
                }
                choice=DEFAULT;
                break;
                //🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰ADICIONAR PONTO DE INTERESSE FAVORITO🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            case ADDIP:
                strcpy(userLogin, insertLogin(ADDIP));
                if (authentication(userLogin)==INCORRECT_KEY){
                    printf("O UTILIZADOR NAO EXISTE!\n\n");
                }else{
                    user = searchUsersList(users, userLogin);
                    userPlaces = user->favoriteIPs;
                    while (strcmp(userPlaceName,"\n")!=0) {
                        printf("\nLISTA DOS PONTOS DE INTERESSE ESCOLHIDOS: \n");
                        printIPList(userPlaces);
                        printf("\n\nEscolha pontos de interesse (copiando o nome).\n\n");
                        cities = removeUserIPsFromCities(userPlaces);
                        printCitiesList(cities, CITIES_WITH_IP);
                        printf("\nCopie o nome do ponto de interesse n°%i (EM MAIUSCULAS): ", countIPs(userPlaces)+1);
                        gets(userPlaceName);
                        strcat(userPlaceName,"\n");
                        while (cities) {
                            places = cities->places;
                            while (places) {
                                if(strcmp(places->name,userPlaceName)==0){
                                    insertIPList(userPlaces, places->name,places->category,places->price,places->description,places->schedule,places->address,places->phone,0,0, BY_NAME);
                                }
                                places = places->next;
                            }
                            cities = cities->next;
                        }
                    }
                    deleteUsersList(users, user->name);
                    insertUsersList(users, user->name, user->address, user->birth, user->phone, user->favoriteCities, user->hotIP, userPlaces);
                    writeToUserFile(users);
                    clearTerminal();
                    printf("OPERAÇÃO EFETUADA COM SUCESSO\n\n");
                }
                choice=DEFAULT;
                break;
                //🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰REMOVER O UTILIZADOR🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            case REMOVEUSER:
                printf("\nLISTA DOS UTILIZADORES: \n");
                printUsersList(users);
                strcpy(userLogin, insertLogin(REMOVEUSER));
                if (authentication(userLogin)==INCORRECT_KEY){
                    printf("O UTILIZADOR NAO EXISTE!\n\n");
                }else{
                    deleteUsersList(users, userLogin);
                    writeToUserFile(users);
                    printf("OPERAÇÃO EFETUADA COM SUCESSO\n\n");
                }
                choice=DEFAULT;
                break;
                //🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰REMOVER UMA CIDADE🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            case REMOVECITY:
                strcpy(userLogin, insertLogin(REMOVECITY));
                if (authentication(userLogin)==INCORRECT_KEY){
                    printf("O UTILIZADOR NAO EXISTE!\n\n");
                }else{
                    printf("\nLISTA DAS VOSSAS CIDADES: \n");
                    cities=searchUsersList(users, userLogin)->favoriteCities;
                    printCitiesList(cities, CITIES_ONLY);
                    printf("\nIntroduza o nome da cidade para removê-la: ");
                    gets(userCityName);
                    strcat(userCityName,"\n");
                    deleteCitiesList(searchUsersList(users, userLogin)->favoriteCities, userCityName);
                    writeToUserFile(users);
                    clearTerminal();
                    printf("OPERAÇÃO EFETUADA COM SUCESSO\n\n");
                }
                choice=DEFAULT;
                break;
                //🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰REMOVER UM PONTO DE INTERESSE HOT🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            case REMOVEHOTIP:
                strcpy(userLogin, insertLogin(REMOVEHOTIP));
                if (authentication(userLogin)==INCORRECT_KEY){
                    printf("O UTILIZADOR NAO EXISTE!\n\n");
                }else{
                    printf("\nO PONTO DE INTERESSE 'HOT' ESCOLHIDO: \n");
                    places=searchUsersList(users, userLogin)->hotIP;
                    printIPList(places);
                    printf("\nIntroduza o nome do ponto de interesse para removê-lo (EM MAIUSCULAS): ");
                    gets(userPlaceName);
                    strcat(userPlaceName,"\n");
                    deleteIPList(searchUsersList(users, userLogin)->hotIP, userPlaceName);
                    writeToUserFile(users);
                    clearTerminal();
                    printf("OPERAÇÃO EFETUADA COM SUCESSO\n\n");
                }
                choice=DEFAULT;
                break;
                //🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰REMOVER UM PONTO DE INTERESSE🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            case REMOVEIP:
                strcpy(userLogin, insertLogin(REMOVEIP));
                if (authentication(userLogin)==INCORRECT_KEY){
                    printf("O UTILIZADOR NAO EXISTE!\n\n");
                }else{
                    printf("\nLISTA DOS PONTOS DE INTERESSE ESCOLHIDOS: \n");
                    places=searchUsersList(users, userLogin)->favoriteIPs;
                    printIPList(places);
                    printf("\nIntroduza o nome do ponto de interesse para removê-lo (EM MAIUSCULAS): ");
                    gets(userPlaceName);
                    strcat(userPlaceName,"\n");
                    deleteIPList(searchUsersList(users, userLogin)->favoriteIPs, userPlaceName);
                    writeToUserFile(users);
                    clearTerminal();
                    printf("OPERAÇÃO EFETUADA COM SUCESSO\n\n");
                }
                choice=DEFAULT;
                break;
                //🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰LISTAGEM POR POPULARIDADE🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            case LISTING:
                clearTerminal();
                cities = readPopularity();
                cities=cities->next;
                popularCities = createCitiesList();
                while(cities){
                    places = cities->places->next;
                    insertCitiesList(popularCities,cities->name,cities->country,cities->currency,createIPList(),cities->popularity,BY_POPULARITY);
                    while(places) {
                        insertIPList(searchCitiesList(popularCities, cities->name)->places, places->name, places->category, places->price, places->description, places->schedule, places->address, places->phone, places->hotCounter, places->normalCounter, BY_POPULARITY);
                        places=places->next;
                    }
                    cities=cities->next;
                }
                printCitiesList(popularCities, CITIES_WITH_IP);
                pressEnterToContinue();
                clearTerminal();
                choice=DEFAULT;
                break;
                //🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰SIMULACAO DA VIAGEM🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            case SIMULATION:
                strcpy(userLogin, insertLogin(SIMULATION));
                if (authentication(userLogin)==INCORRECT_KEY){
                    printf("O UTILIZADOR NAO EXISTE!\n\n");
                }else{
                    if(countCities(searchUsersList(users, userLogin)->favoriteCities)==MAX_FAV_CITIES){
                        userCities = searchUsersList(users, userLogin)->favoriteCities->next;
                        while (userCities) {
                            insertCitiesList(tripCities, userCities->name, userCities->country, userCities->currency, createIPList(), userCities->popularity, BY_POPULARITY);
                            insertCitiesList(tripCitiesForStats, userCities->name, userCities->country, userCities->currency, createIPList(), userCities->popularity, BY_POPULARITY);
                            userHotIP = searchUsersList(users, userLogin)->hotIP->next;
                            userPlaces = searchUsersList(users, userLogin)->favoriteIPs->next;
                            otherPlaces = userCities->places->next;
                            IPCounter = 0;
                            places = userCities->places->next;
                            
                            auxPlaces = places;
                            while (places && userHotIP &&IPCounter<MAX_TRIP_IP) {
                                if(strcmp(places->name, userHotIP->name)==0){
                                    insertIPList(searchCitiesList(tripCities, userCities->name)->places, userHotIP->name, userHotIP->category, userHotIP->price, userHotIP->description, userHotIP->schedule, userHotIP->address, userHotIP->phone, 10*userHotIP->hotCounter, 10*userHotIP->normalCounter, BY_POPULARITY);
                                    insertIPList(searchCitiesList(tripCitiesForStats, userCities->name)->places, userHotIP->name, userHotIP->category, userHotIP->price, userHotIP->description, userHotIP->schedule, userHotIP->address, userHotIP->phone, userHotIP->hotCounter, userHotIP->normalCounter, BY_POPULARITY);
                                    strcpy(userPlaceName,userHotIP->name);
                                    deleteIPList(auxPlaces, userPlaceName);
                                    IPCounter++;
                                    userHotIP=userHotIP->next;
                                }
                                places=places->next;
                            }
                            places=auxPlaces;
                            while (places && userPlaces &&IPCounter<MAX_TRIP_IP) {
                                if(strcmp(places->name, userPlaces->name)==0){
                                    insertIPList(searchCitiesList(tripCities, userCities->name)->places, userPlaces->name, userPlaces->category, userPlaces->price, userPlaces->description, userPlaces->schedule, userPlaces->address, userPlaces->phone, 10*userPlaces->hotCounter, 10*userPlaces->normalCounter, BY_POPULARITY);
                                    insertIPList(searchCitiesList(tripCitiesForStats, userCities->name)->places, userPlaces->name, userPlaces->category, userPlaces->price, userPlaces->description, userPlaces->schedule, userPlaces->address, userPlaces->phone, userPlaces->hotCounter, userPlaces->normalCounter, BY_POPULARITY);
                                    strcpy(userPlaceName,userPlaces->name);
                                    deleteIPList(auxPlaces, userPlaceName);
                                    IPCounter++;
                                    userPlaces=userPlaces->next;
                                }
                                places=places->next;
                            }
                            places = auxPlaces;
                            while (auxPlaces && otherPlaces && IPCounter<MAX_TRIP_IP) {
                                if(strcmp(auxPlaces->name, otherPlaces->name)==0){
                                    insertIPList(searchCitiesList(tripCities, userCities->name)->places, otherPlaces->name, otherPlaces->category, otherPlaces->price, otherPlaces->description, otherPlaces->schedule, otherPlaces->address, otherPlaces->phone, otherPlaces->hotCounter, otherPlaces->normalCounter, BY_POPULARITY);
                                    insertIPList(searchCitiesList(tripCitiesForStats, userCities->name)->places, otherPlaces->name, otherPlaces->category, otherPlaces->price, otherPlaces->description, otherPlaces->schedule, otherPlaces->address, otherPlaces->phone, otherPlaces->hotCounter, otherPlaces->normalCounter, BY_POPULARITY);
                                    IPCounter++;
                                    otherPlaces=otherPlaces->next;
                                }
                                auxPlaces=auxPlaces->next;
                            }
                            userCities=userCities->next;
                        }
                        printf("🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰\n");
                        printf("SIMULAÇÃO DA VIAGEM:\n\n");
                        printCitiesList(tripCities, CITIES_WITH_IP);
                        printf("🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰\n");
                        printf("\n Percentagem de utilizadores que tem pelo menos um local favorito entre os incluídos na viagem: %.2f%%\n",statCities(tripCitiesForStats));
                        printf("\n Percentagem de utilizadores cujo PdI “hot” está incluído nesta viagem: %.2f%%\n", statHotIP(tripCitiesForStats));
                        printf("\n Percentagem das preferências de PdI: %.2f%%\n\n", statIPs(tripCitiesForStats));
                        pressEnterToContinue();
                        clearTerminal();
                    }else{
                        printf("O UTILIZADOR NÃO TEM %d CIDADES!\n\n", MAX_FAV_CITIES);
                    }
                }
                choice=DEFAULT;
                break;
                //🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰PARAR O PROGRAMA🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            case EXIT:
                clearTerminal();
                exit(0);
                break;
                //🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰MENU PRINCIPAL🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰
            default:
                //ABIR O MENU
                readMenu();
                //PEDE PARA ESCOLHER A OPCAO
                choice = insertValidOperation();
                //RESET VARIAVEIS
                users = readUsersPreferences();
                tripCities = createCitiesList();
                tripCitiesForStats = createCitiesList();
                userHotIP = createIPList();
                userPlaces = createIPList();
                places = createIPList();
                destroyUsersList(users);
                destroyIPList(userHotIP);
                destroyIPList(userPlaces);
                destroyIPList(places);
                destroyCitiesList(tripCities);
                destroyCitiesList(tripCitiesForStats);
                if(choice!=EXIT){
                    users = readUsersPreferences();
                    tripCities = createCitiesList();
                    tripCitiesForStats = createCitiesList();
                    userHotIP = createIPList();
                    userPlaces = createIPList();
                    places = createIPList();
                }
                strcpy(userPlaceName,"NULL");
                strcpy(userCityName,"NULL");
                cityCounter=0;
                IPCounter=0;
                clearTerminal();
                break;
        }
    }
}
