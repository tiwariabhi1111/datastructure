#include <stdio.h>
int final[5]={100,100,100,100,100}, 
visited[5]={100,100,100,100,100};
 static int visitedValue=0,loc,count=0;
int findmin(int graph1[5][5])
{ 
   int i,min=1000,location,j,flag;
   printf("\nfinding array for traverse\n");
   for(i=0;i<5;i++)
  {
    printf("%5d",graph1[0][i]);   
  }
   printf("\nbefore iteration\n");
   for(i=0;i<5;i++)
  {
    printf("%5d",final[i]);   
  }
  printf("\n");
  for(i=0;i<5;i++)
  {
      flag=0;
      for(j=0;j<5;j++)
     {
      if(i==visited[j])
      flag=1;
      }
    if(flag!=1)
    {
        if(min>final[i])
        {
            min=final[i];
            location=i;
            // printf("%d\n",graph1[0][i]);
        }
    }
    
  }
  count++;
  if(count==1){
      visitedValue=min ;loc=location;
            printf("visited location:%d and visited element is:%d\n",location,min);

      return location;
  }
       
             

     printf("visited location:%d and visited element is:%d\n",location,min);
     for(i=0;i<5;i++)
       {
           if(final[i]>(visitedValue+graph1[0][i])) final[i]=visitedValue+graph1[0][i];
       }
        visitedValue=min ;loc=location;
    return location;
 
}

void findval(int graph[5][5],int start)
{
    int i,j,minimum, count=0,location,init=start;
    for(i=0;i<=5;i++)
    {
        // //put the node inside the visited array
        if(i==0){
        visited[count]=init;
      for(j=0;j<5;j++)
            final[j]=graph[0][j];
            
         }
        else {
          location= findmin(graph+init);
          count++;
           visited[count]=location;
          init=location;
          printf("\nafter iteration:");
          for(j=0;j<5;j++)
          printf("%4d",final[j]);
                    printf("\n");
        }
      
         
        
        // }
        
    }
}

int main() {
	int start=0,i;
	 int graph[5][5]={
	     {0,2,100,4,100},
	     {2,0,3,100,100},
	     {100,3,0,5,100},
	     {4,100,5,0,1},
	     {100,100,100,1,0}
	     
	 };
	  //printf("The initial graph is:\n\n");display(graph);
	  
	  findval(graph,start);
	  printf("the final array is:");
	  for(i=0;i<5;i++){
 printf("%4d",final[i]);}
	return 0;
}
