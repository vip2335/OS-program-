#include<stdio.h>
main()
{
 int s,i,j,k,flag1=0,flag2=0;
 printf("Enter the no. of states: ");
 scanf("%d",&s);
 int mat[s][5],count=0;
 int ar[s][2];
 int asso[s+1];
 
 printf("Enter the matrix of states & outputs for different inputs: \n");
 for(i=0;i<s;i++)
 { 
  for(j=0;j<5;j++)
  {
   scanf("%d",&mat[i][j]);  
  }
 }
 


 for(k=1;k<=s;k++)
 {
  for(i=1;i<5;i+=2)
  {
   for(j=0;j<4;j++)
   {
    if(mat[j][i]==k && mat[j][i+1]==0)
    { flag1=1; asso[k]=0; }
    if(mat[j][i]==k && mat[j][i+1]==1)
    { flag2=1; asso[k]=1; }
   }
  
  }       /*ar is an array storing the no. of states in which the particular state will be divided
         and asso is an array storing the o/p of the states that won't be divided
         */
  if(flag1==1 && flag2==1)
  {
   ar[k-1][0]=k;
   ar[k-1][1]=2;
  }
  else
  {
   ar[k-1][0]=k;
   ar[k-1][1]=1;
  }
  flag1=0; flag2=0;
 }

 int sum=0;
 for(i=0;i<s;i++)
 {
  printf("%d %d\n",i+1,ar[i][1]);
  sum+=ar[i][1];
 }
 printf("\n Total new states will be %d",sum);
 
  int mat2[sum][5],l;
 k=0;
 
 for(i=0;i<sum;i++)  /* this & next two for() forms the intermediate table between the miley and moore wherein the states have been divided */
 {
  count=ar[mat[k][0]-1][1];
  while(count)
  {
   for(j=0,l=0;j<5;j++,l++)
   {
    mat2[i][j]=mat[k][l];
   }
   count--;
   if(count==0)
   { 
    k++;
   }
   else i++;
  }
 }

 
 for(i=0;i<sum;i++)   /* this loop changes the names of the divided states(in next state columns) e.g. changes 2 to 20 if o/p is 0  */
 {
  for(j=1;j<5;j+=2)
  {
   if(ar[mat2[i][j]-1][1]!=1)
   {
    mat2[i][j]=(mat2[i][j]*10)+mat2[i][j+1];
   }
  }
 }
 
 for(i=0;i<sum;i++)  /* this loop changes the state names in the present state column e.g. if 2 is divided into two states then 20 & 21  */
 {
  if(ar[mat2[i][0]-1][1]!=1)
  { 
   mat2[i][0]=mat2[i][0]*10;
   i++;
   mat2[i][0]=(mat2[i][0]*10)+1;;
  }
 }

 printf("\n The new table is: \n"); /* intermediate table printed*/
 for(i=0;i<sum;i++)
 {
  printf("\n");
  for(j=0;j<5;j++)
  printf("%d ",mat2[i][j]);
 }

 int momat[sum][4]; /* final matrix for moore table representation */
 for(i=0;i<2;i++)
 {
  for(j=0;j<sum;j++)
  {
   momat[j][i]=mat2[j][i];
  }
 }
 for(i=3,j=0;j<sum;j++)  //column for i=2 not copied to momat
 momat[j][i-1]=mat2[j][i];
 
 for(i=3,j=0;j<sum;j++)  //for loop for filling the o/p column of the moore table
 {
  if(momat[j][0]>=10)
  momat[j][i]=momat[j][0]%10;
  else if(momat[j][0]<10)
  {
   momat[j][i]=asso[momat[j][0]];
  }
 }

 printf("\n The moore table is: \n");
 /* if condn to add a new row to the moore table if the first output is not 0 */
 if(momat[0][3]==1)
 { 
  printf("s ");
  for(j=1;j<3;j++)
  printf("%d ",momat[0][j]);
  printf("%d",0);  
 }

 for(i=0;i<sum;i++)
 {
  printf("\n");
  for(j=0;j<4;j++)
  printf("%d ",momat[i][j]);
 }
}
