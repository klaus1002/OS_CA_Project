#include<stdio.h>

int  main()
{



float PRIO[4],AVG_waittime;
float ARI_time[4], P_ID[4];
float WAIT_time[4],T_ARD_time[4];
float BUR_time[4],Minima,ToTaL=0,ToTaL_2=0;
float TEM;
float Turn_AR_Avg;
float Estimated_time[4];
float  Final_Turn_ARND;
float Final_WAit=0;
float WAIT_avg;

ARI_time[0]=0;
ARI_time[1]=5;
ARI_time[2]=13;
ARI_time[3]=17;

BUR_time[0]=20;
BUR_time[1]=36;
BUR_time[2]=19;
BUR_time[3]=42;

int i,j=0;
int o=1,p=1;
int n=4;

P_ID[0]=1;
P_ID[1]=2;
P_ID[2]=3;
P_ID[3]=4;


printf("\n\nValues Given in the problem are:- \n\n");

printf("process | Arrival-Time | Burst-Time \n");

printf("--------------------------------------\n");

 printf("P[0]            %0.0lf            %0.0lf        \n",ARI_time[0],BUR_time[0]);
 printf("P[1]            %0.0lf            %0.0lf        \n",ARI_time[1],BUR_time[1]);
 printf("P[2]           %0.0lf            %0.0lf         \n",ARI_time[2],BUR_time[2]);
 printf("P[3]           %0.0lf            %0.0lf         \n",ARI_time[3],BUR_time[3]);

printf("--------------------------------------\n");




/*Arranging  according to Burst time,
Execution time and Arrival Time

*/





long int k = 1;
float b_time = 0;

j=0;
  while(j<n)
  {
    b_time = b_time + BUR_time[j];
    Minima = BUR_time[k];

    for(i=k;i<n;i++)
    {
      if((b_time >= ARI_time[i])&&(BUR_time[i]<Minima))
      {
        TEM = BUR_time[k];
        BUR_time[k] = BUR_time[i];
        BUR_time[i] = TEM;

        TEM = ARI_time[k];
        ARI_time[k] = ARI_time[i];
        ARI_time[i] = TEM;

        TEM = P_ID[k];
        P_ID[k] = P_ID[i];
        P_ID[i] = TEM;
      }
    }
    k++;
    j++;
  }
  WAIT_time[0] = 0;




  /* we have  prioritize the processes according to the
  formulae

  Priority = 1+ Waiting time / Estimated run time
  */





  i=1;
  while(i<n)
  {
    ToTaL += BUR_time[i-1];

    WAIT_time[i] = ToTaL - ARI_time[i];
    Final_WAit += WAIT_time[i];
    i++;
  }
 WAIT_avg =Final_WAit/4;

  i=0;
  while(i<n)
  {
    ToTaL_2 += BUR_time[i];
    T_ARD_time[i] = ToTaL_2 - ARI_time[i];
    Final_Turn_ARND += T_ARD_time[i];
    i++;
  }
  Turn_AR_Avg=Final_Turn_ARND/4;




printf("\n\n\n**** Now Values are according to Burst time **** \n\n");

  printf(" process | Arrival-Time | Burst-Time |  Waiting-Time  |  Turn-AroundTime  \n");
  printf("---------------------------------------------------------------------------\n");

printf("  P[%0.0lf]           %0.0lf           %0.0lf               %0.0lf                 %0.0lf          \n",P_ID[0],ARI_time[0],BUR_time[0],WAIT_time[0],T_ARD_time[0]);
printf("  P[%0.0lf]          %0.0lf           %0.0lf               %0.0lf                 %0.0lf          \n",P_ID[1],ARI_time[1],BUR_time[1],WAIT_time[1],T_ARD_time[1]);
printf("  P[%0.0lf]           %0.0lf           %0.0lf              %0.0lf                 %0.0lf          \n",P_ID[2],ARI_time[2],BUR_time[2],WAIT_time[2],T_ARD_time[2]);
printf("  P[%0.0lf]          %0.0lf           %0.0lf              %0.0lf                %0.0lf          \n",P_ID[3],ARI_time[3],BUR_time[3],WAIT_time[3],T_ARD_time[3]);

    printf("---------------------------------------------------------------------------\n");






Estimated_time[0] = BUR_time[0];
  i=0;

  while(i<n)
  {
    Estimated_time[i] = Estimated_time[i-1] + BUR_time[i];
i=i+1;
  }
i=0;


  while(i<n)
  {
    PRIO[i] = 1+WAIT_time[i]/Estimated_time[i];
   i=i+1;
  }






 printf("\n\n\n\n*** As per the condition given in the problem:-  ");
  printf("\n\n**** PRIORITY = 1 + (Waiting time / Estimated run time) ****\n\n");

  printf("\n process  | Arrival-Time  | Burst-Time  | Waiting-Time  | TurnAround Time  \n");
  printf("----------------------------------------------------------------------------\n");

  printf("  P[%.0f]%15.0f%15.0lf%15.0lf%17.0lf\n",P_ID[0],ARI_time[0],BUR_time[0],WAIT_time[0],T_ARD_time[0]);
 for(i=n-1;i>0;i--)
  {
       printf("  P[%.0f]%15.0f%15.0lf%15.0lf%17.0lf\n",P_ID[i],ARI_time[i],BUR_time[i],WAIT_time[i],T_ARD_time[i]);
  }

  printf("----------------------------------------------------------------------------\n");

   printf("\n\n\n*** Average Turn Around Time :   %lf ***\n",Turn_AR_Avg);
  printf("*** Average Waiting Time     :   %lf ***\n\n\n\n\n\n\n\n",WAIT_avg);




}
