#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Function Prototypes
void Initialize(char*[][], int, int);
int Search(char*[][], char*, int);

//Main Method
main()
{
      //Declaring Variables
      int const MAX_NAMES = 2, MAX_NAMELENGTH = 15;
      char *strNames[MAX_NAMES][MAX_NAMELENGTH], name[MAX_NAMELENGTH];
      int pos = -1;
      
      //Initialze Array
      Initialize(strNames, MAX_NAMES, MAX_NAMELENGTH);
      
      //Ask Name
      printf("Please enter a name: ");
      scanf("%s", name);
      
      //Search Name
      pos = Search(strNames, name, MAX_NAMES);
      
      //Display Search Result
      if (pos != -1)
      {
              printf("The name you entered was name number %d", pos);
              getch();
              
      }
      else
      {
              printf("The name you entered was not found");
              getch();
      }
}

//Initialize Array
void Initialize(char *strNames[][3], int MAX_NAMES, int MAX_NAMELENGTH)
{
     *strNames[MAX_NAMES][MAX_NAMELENGTH];
     int i;
     for(i = 0; i < MAX_NAMES; i++)
     {
           printf("Please enter name %d ", i+1);
           scanf("%s", strNames[i]);
     }
}

//Search Array
int Search(char *strNames[][8], char *name, int MAX_NAMES)
{
    int i;
    for(i = 0; i < MAX_NAMES; i++)
    {
           if (strcmp(strNames[i], *name) == 0)
           {
              return i+1;
           }
    }
    return -1;
}
