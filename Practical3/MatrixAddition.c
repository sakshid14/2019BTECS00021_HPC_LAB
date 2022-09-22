#include<stdio.h>
#include<stdlib.h>
#include<omp.h>




int main()
{
	int tid;
	int i,j,d;
	int rows=250,cols=250;

	int a[250][250];
	int b[250][250];
	int c[250][250]={0};
	const int value = 1;
//	std::fill(*a, *a + 62500, value);
//	std::fill(*b, *b + 62500, value);
	for(int i=0;i<250;i++){
		for(int j=0;j<250;j++)
			a[i][j]=1;
	}
	for(int i=0;i<250;i++){
		for(int j=0;j<250;j++)
			b[i][j]=1;
	}
	double start,end;
	start=omp_get_wtime();

    for(int i=0;i<rows;i++)
    {
        #pragma omp parallel for reduction(+:d) num_threads(8)
         for(j=0;j<cols;j++)
        {
            printf("Thread:%d\n",omp_get_thread_num());
            c[i][j]=a[i][j]+b[i][j];
            d+=c[i][j];
        }
    }

printf("Values of Resultant Matrix C are as follows:\n");

for(i=0;i<rows;i++)
  for(j=0;j<cols;j++)
    {
       printf("Value of C[%d][%d]=%d\n",i,j,c[i][j]);
    }
    end=omp_get_wtime();

    printf("\n Time For Parallel Execution= %f",(end-start));
return 0;
}