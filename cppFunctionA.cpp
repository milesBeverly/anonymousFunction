#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <mpi.h>

int main(void){
  int var1, var2, var3, i, var4, var5;
  int var6 = 2;
  int var7 = 1;

  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &var2);
  MPI_Comm_rank(MPI_COMM_WORLD, &var3);
  srandom((unsigned)time(NULL) + var3);
  var5 = random() % 10;

      if (var3 % var6 == 0){

          printf("IF----");

          printf("Process %d generates: %d\n", var3, var5);

          for (i = 0; i < var2; i++)
          {
              MPI_Recv(&var5, 1, MPI_INT, i, var3 , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
               var1 += var5;  
               printf("Current var1=: %d\n", var1);

          }

          printf("The NEW var6 is:%d\n", var6);
          var6 *= 2;
          var7 *= 2;

      }

      else if (var3 % var6 == var7){
          printf("ELSE----");
          printf("Process %d generates: %d\n", var3, var5);
          MPI_Send(&var5, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
      }
      else
         if (var3==0)
            printf("var1=: %d\n", var1);

  MPI_Finalize();

  return 0;
}