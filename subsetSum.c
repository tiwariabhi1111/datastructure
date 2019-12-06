#include<stdio.h>
void main()
{
int sum[6][17]={0},total=15;
int ele[5]={2,3,7,8,10};
int i,j,loc=0,temp;
for(i=0;i<=total;i++)
{
    sum[0][i]=i;
}
for(i=1;i<=5;i++)
{
    sum[i][0]=1;
}
 for(i=1;i<=5;i++)
 { 
    
     for(j=1;j<=total;j++)
    {
        if(i==1)
        {
        if(ele[loc]==sum[0][j])
          sum[i][j]=1;  
        else   sum[i+1][j]=0; 
        if(j==total) {loc++; }
        }
         else {
          
             if(ele[loc]>sum[0][j])
              {
                
                  sum[i][j]=sum[i-1][j];
                
             }
            if(ele[loc]<=sum[0][j])
             {
                  if(sum[i-1][j]==1) {sum[i][j]=1; }
                else
                 sum[i][j]=sum[i-1][j-ele[loc]];
            }
if(j==total) {loc++; }
               
         } 
     } 


 }
 
 printf("\n\n");
 for(i=0;i<=5;i++)
 {
     for(j=0;j<=total;j++){
     printf("%3d",sum[i][j]);}
     printf("\n");
 }
 
 if(sum[loc][total]==1)
 printf("\n***********found*****************\n");
 else
printf("\n**************not found***************\n");
}
