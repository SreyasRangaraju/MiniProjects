#include <stdio.h>
#include <conio.h>

//Function Prototypes
void InitArray(int*, int);
int SearchArray(int[], int, int);
void DisplayArray(int[], int);

//Main Method
main()
{
      //Declaring Variables
      int const MAX = 25;
      int NumArray[MAX];
      int i, guess = 0;
      
      //Making the Numbers
      InitArray(NumArray[], MAX);
      
      //3-Guess Loop
      for (i = 0;i < 3;i++)
      {
          //Input guess
          printf("\nPlease guess a number between 0 and 100: ");
          scanf("%d", &guess);
          
          //Error-Checking guess
          if (guess >= 0 && guess <=100)
          {
          
              //Checking guess
              if(SearchArray(NumArray, MAX, guess) == 1)
              {
                  printf("%d is one of the lucky numbers. You win!", guess);
                  DisplayArray(NumArray, MAX);
                  getch();
                  i = 4;
              }
              
              else
              {
                  printf("%d is not one of the lucky numbers.", guess);
              }
          }
          
          else
          {
              printf("%d is not a valid number.", guess);
          }
      }
      
      //Display Losing Message/Do Nothing
      if(i == 3)
      {
           printf(" You Lose!");
           DisplayArray(NumArray, MAX);
           getch();
      }
}                         

//Function to Initialize Array
void InitArray(int* NumArray, int ArrayLength)
{
     int i, value;
     srand(time(NULL));
     
     for(i = 0;i < ArrayLength;i++, *NumArray++)
     {
           value = (rand() % 101);
           
           if (SearchArray(NumArray, ArrayLength, value) == 0)
           {
               *NumArray = value;
           }
           
           else
           {
               *NumArray--;
               i--;
           }
     }
}

//Function to Search Array
int SearchArray(int NumArray[], int ArrayLength, int Num)
{
     int i;
     
     for(i = 0;i < ArrayLength;i++)
     {
           if (NumArray[i] == Num)
           {
               return 1;
           }
     }
     return 0;
}

//Function to Display Array
void DisplayArray(int NumArray[], int ArrayLength)
{
     int i;
     
     printf("\nLucky Numbers: ");
     
     for(i = 0;i < ArrayLength;i++)
     {
           printf("%d ", NumArray[i]);
     }
}
