#include<stdio.h>
int main()
{
   int arr1[3][3],arr2[3][3],arr3[3][3];
   int i, j, k;
   printf("Enter the Elements of Array 1: \n");
   for(int i=0;i<3;i++)
   {
       for(int j=0;j<3;j++)
         scanf("%d", &arr1[i][j]);
    }
    printf("Enter the Elements of Array2: \n");
    for(i=0;i<3;i++)
    {
       for(j=0;j<3;j++)
         scanf("%d", &arr2[i][j]);
    }
    printf("Output Matrix:\n");
    for(i=0;i<3;i++)
    {
       for(j=0;j<3;j++)
       {
           arr3[i][j]=0;
           for(k=0;k<3;k++)
               arr3[i][j]=arr3[i][j]+(arr1[i][k]*arr2[k][j]);
           printf("%d ", arr3[i][j]);
       }
    printf("\n");
    }
    return 0;
}