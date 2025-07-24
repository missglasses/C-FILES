#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char familyName[30];
    int male[3];   // index 0: father, index 1: children, index 2: other members
    int female[3]; // index 0: mother, index 1: children, index 2: other members
} Household;

typedef struct node {
    Household data;
    struct node *next;
} HouseholdNode, *HHRegistry;

typedef struct {
    Household households[50];
    int count;
} RegistryArrayList;


// Function prototypes
void initRegistry(HHRegistry *list);
RegistryArrayList createRegistry();
Household createHousehold(char familyName[], int male_count[], int female_count[]);
void addHousehold(HHRegistry *list, Household h);
void displayRegistry(HHRegistry list);
void populateRegistryData(RegistryArrayList *list, int sequence, int count);
void displayRegistryArray(RegistryArrayList list);
void displayRegistryList(HHRegistry list);

int main() {
    HHRegistry registry;
    RegistryArrayList baseData;
    int seq, n;

    initRegistry(&registry);
    baseData = createRegistry();

    printf("Enter sequence: ");
    scanf("%d", &seq);
    printf("Enter count: ");
    scanf("%d", &n);

    // [1] To do code for populating baseData based on sequence and number of elements
    // baseData
    populateRegistryData(&baseData, seq, n);

    // End of [1]

    printf("\nBase Data:\n");
    displayRegistryArray(baseData);

    // [2] To do code for add all baseData into the registry
    
    for (int i=0; i<baseData.count; i++){
        addHousehold(&registry, baseData.households[i]);
        
    }

    // End of code [2]

    // Display the registry
    printf("\nRegistry List:\n");
    displayRegistryList(registry);


    return 0;
}

// Function to initialize the registry
void initRegistry(HHRegistry *list) {
    *list = NULL;
}

// Function to initialize the registry array
RegistryArrayList createRegistry() {
    RegistryArrayList list;

    list.count = 0;

    return list;
}

// Function to create a household
Household createHousehold(char familyName[], int male_count[], int female_count[]) {
    Household h;
    strcpy(h.familyName, familyName);
    for (int i = 0; i < 3; i++) {
        h.male[i] = male_count[i];
        h.female[i] = female_count[i];
    }
    return h;
}

// Function to add a household in sorted order based on familyName
void addHousehold(HHRegistry *list, Household h) {
    // [3] To do code logic
    
     HouseholdNode *newHousehold = malloc(sizeof(HouseholdNode));
//   HHRegistry newHousehold= malloc(sizeof(HHRegistry));

  if(newHousehold==NULL){
    exit(1);
    }
    
    
    newHousehold->data=h;
    newHousehold->next=NULL;
    
  
    //    strcmp((param, param)==0);
    HouseholdNode **curr = list;
    int j=0;
    int i=0;
     while (*curr != NULL && strcmp((*curr)->data.familyName, h.familyName) < 0) {
        curr = &((*curr)->next);
    }
    
     newHousehold->next = *curr;
    *curr = newHousehold;
    
   
    // End of code [3]
}

// Function to display the registry in a tabular format
void displayRegistryList(HHRegistry list) {
    printf("%-3s | %-20s | %-12s | %-12s\n", "No", "Family Name", "Male Count", "Female Count");
    printf("----------------------------------------------------------\n");
    int index = 1;
    while (list != NULL) {
        printf("%-3d | %-20s | %-12d | %-12d\n", index, list->data.familyName,
               list->data.male[0] + list->data.male[1] + list->data.male[2],
               list->data.female[0] + list->data.female[1] + list->data.female[2]);
        list = list->next;
        index++;
    }
}

// Function to populate registry data based on the sequence
void populateRegistryData(RegistryArrayList *list, int sequence, int count) {
    // Sample data for demonstration
    Household sampleHouseholds[50] = {
        {"CALUNSAG", {1, 2, 1}, {1, 1, 0}},
        {"LLAGUNO", {1, 1, 0}, {1, 2, 1}},
        {"OLMO", {1, 0, 0}, {1, 1, 0}},
        {"EDAÑO", {1, 2, 1}, {1, 0, 0}},
        {"GERODIAS", {1, 1, 1}, {1, 1, 1}},
        {"LEPATAN", {1, 0, 0}, {1, 2, 0}},
        {"CATUBIG", {1, 1, 0}, {1, 2, 1}},
        {"DELA CRUZ", {1, 0, 0}, {1, 1, 0}},
        {"DELUSA", {1, 2, 1}, {1, 0, 0}},
        {"DIEZ", {1, 1, 1}, {1, 1, 1}},
        {"LOMBRINO", {1, 0, 0}, {1, 2, 0}},
        {"YBANEZ", {1, 1, 0}, {1, 2, 1}},
        {"REVALDE", {1, 0, 0}, {1, 1, 0}},
        {"MASION", {1, 2, 1}, {1, 0, 0}},
        {"JADMAN", {1, 1, 1}, {1, 1, 1}},
        {"MAYOL", {1, 0, 0}, {1, 2, 0}},
        {"VILLAN", {1, 1, 0}, {1, 2, 1}},
        {"SALIMBOT", {1, 0, 0}, {1, 1, 0}},
        {"VILLA", {1, 2, 1}, {1, 0, 0}},
        {"CABANTOC", {1, 1, 1}, {1, 1, 1}},
        {"YROGIROG", {1, 0, 0}, {1, 2, 0}},
        {"LARGO", {1, 1, 0}, {1, 2, 1}},
        {"AGUILAR", {1, 0, 0}, {1, 1, 0}},
        {"FERNANDEZ", {1, 2, 1}, {1, 0, 0}},
        {"DEL MAR", {1, 1, 1}, {1, 1, 1}},
        {"SEARES", {1, 0, 0}, {1, 2, 0}},
        {"DUMANAT", {1, 1, 0}, {1, 2, 1}},
        {"ALVEZ", {1, 0, 0}, {1, 1, 0}},
        {"QUINAL", {1, 2, 1}, {1, 0, 0}},
        {"RUFILA", {1, 1, 1}, {1, 1, 1}},
        {"ABORDO", {1, 0, 0}, {1, 2, 0}},
        {"MAHINAY", {1, 1, 0}, {1, 2, 1}},
        {"PAGALAN", {1, 0, 0}, {1, 1, 0}},
        {"RABANES", {1, 2, 1}, {1, 0, 0}},
        {"ACUPINPIN", {1, 1, 1}, {1, 1, 1}},
        {"RUHANA", {1, 0, 0}, {1, 2, 0}},
        {"LINGLING", {1, 1, 0}, {1, 2, 1}},
        {"TAGAAN", {1, 0, 0}, {1, 1, 0}},
        {"FLORES", {1, 2, 1}, {1, 0, 0}},
        {"LADERA", {1, 1, 1}, {1, 1, 1}},
        {"CIUDADANO", {1, 0, 0}, {1, 2, 0}},
        {"ROLLO", {1, 1, 0}, {1, 2, 1}},
        {"DURAN", {1, 0, 0}, {1, 1, 0}},
        {"PACHECO", {1, 2, 1}, {1, 0, 0}},
        {"ACHAS", {1, 1, 1}, {1, 1, 1}},
        {"PRADO", {1, 0, 0}, {1, 2, 0}},
        {"TORING", {1, 1, 0}, {1, 2, 1}},
        {"CATUBAO", {1, 0, 0}, {1, 1, 0}},
        {"LIBETARIO", {1, 2, 1}, {1, 0, 0}},
        {"MASAYON", {1, 1, 1}, {1, 1, 1}}
    };

    int start = 0, move;
    if (sequence == 1) {
        start = 0; // odd positions
        move = 2;
    } else if (sequence == 2) {
        start = 1; // even positions
        move = 2;
    } else if (sequence == 3) {
        start = 0; // first half
        move = 1;
    } else if (sequence == 4) {
        start = 3; // second half
        move = 1;
    }

    for (int i = 0, add = 0; add < count && (start + i) < 25; i = i + move) {
        list->households[list->count++] = sampleHouseholds[start + i];
        add++;
    }
}

// Function to display the registry array in a tabular format
void displayRegistryArray(RegistryArrayList list) {
    printf("%-3s | %-20s | %-12s | %-12s\n", "No", "Family Name", "Male Count", "Female Count");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < list.count; i++) {
        printf("%-3d | %-20s | %-12d | %-12d\n", i + 1, list.households[i].familyName,
               list.households[i].male[0] + list.households[i].male[1] + list.households[i].male[2],
               list.households[i].female[0] + list.households[i].female[1] + list.households[i].female[2]);
    }
}

