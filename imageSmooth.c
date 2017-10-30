#include <stdio.h>
#include <ctype.h>
#include <conio.h>

main()
{
      int Row = 0, Col = 0;
      
      //Reading in Image Array
      printf("Please enter the number of rows of pixels in the image: \n");
      scanf("%d", &Row);
     
      printf("Please enter the number of columns of pixels in the image: \n");
      scanf("%d", &Col);
      
      int Image[Row][Col];
      
      printf("Type in the pixel numbers in order: ");
      
      int i, j;
      for(i = 0;i < Row;i++)
      {
            for(j = 0;j < Col; j++)
            {
                  scanf("%d", &Image[i][j]);
            }     
      }
      
      //Displaying Image Array
      for(i = 0;i < Row;i++)
      {
            for(j = 0;j < Col; j++)
            {
                  printf("\t%d", Image[i][j]);
            }    
            printf("\n"); 
      }
      getch();
      printf("\n");
      
      //Making Smoothed Image Array
      int ImageSmoothed[Row][Col];
      for(i = 0;i < Row;i++)
      {
            for(j = 0;j < Col; j++)
            {
                 //Top Row
                 if (i == 0)
                 {
                       //Top Left
                       if (j == 0)
                       {
                             ImageSmoothed[i][j] = (Image[i+1][j] + Image[i][j+1] + Image[i][j])/3;
                       }
                       
                       //Top Right
                       else if (j == Col - 1)
                       {
                             ImageSmoothed[i][j] = (Image[i+1][j] + Image[i][j-1] + Image[i][j])/3;
                       }
                       
                       //Top Middle
                       else
                       {
                             ImageSmoothed[i][j] = (Image[i][j-1] + Image[i][j+1] + Image[i+1][j] + Image[i][j])/4;
                       }
                 }
                 
                 //Bottom Row
                 else if (i == Row - 1)
                 {
                      //Bottom Left
                      if (j == 0)
                      {
                            ImageSmoothed[i][j] = (Image[i-1][j] + Image[i][j+1] + Image[i][j])/3;
                      }
                      
                      //Bottom Right
                      else if (j == Col - 1)
                      {
                            ImageSmoothed[i][j] = (Image[i-1][j] + Image[i][j-1] + Image[i][j])/3;
                      }
                       
                      //Bottom Middle 
                      else
                      {
                            ImageSmoothed[i][j] = (Image[i][j-1] + Image[i][j+1] + Image[i-1][j] + Image[i][j])/4;
                      }
                 }
                 
                 //Left Middle
                 else if (j == 0)
                 {
                      ImageSmoothed[i][j] = (Image[i][j+1] + Image[i+1][j] + Image[i-1][j] + Image[i][j])/4;
                 }
                 
                 //Right Middle
                 else if (j == Col - 1)
                 {
                      ImageSmoothed[i][j] = (Image[i][j-1] + Image[i+1][j] + Image[i-1][j] + Image[i][j])/4;
                 }
                 
                 //Middle Numbers
                 else
                 {
                     ImageSmoothed[i][j] = (Image[i][j-1] + Image[i+1][j] + Image[i-1][j] + Image[i][j+1] + Image[i][j])/5;
                 }
            }    
      }
      
      //Displayed Smoothed Image Array
      for(i = 0;i < Row;i++)
      {
            for(j = 0;j < Col; j++)
            {
                  printf("\t%d", ImageSmoothed[i][j]);
            }    
            printf("\n"); 
      }
      getch();
      
      
}
