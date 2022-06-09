#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 20
void merge(int *pin,int start,int finish);
void merge_sort(int *pin,int start,int finish);
void swap(int *a,int *b);
void print_array(int *pin,int n);
int main()
{
   int array[SIZE],i;
   srand(time(NULL));
     for(i=0;i<SIZE;i++)
     {
         array[i]=rand()%100;
     }
    
     merge_sort(array,0,SIZE-1);
     print_array(array,SIZE);
}
void merge_sort(int *pin,int start,int finish)
{
    int middle;
      
      if(start==finish)
      return;
      else if(start==finish-1)
      {  
          if(pin[start]>pin[finish])
        swap(&pin[start],&pin[finish]);
      }
      else
      {
          middle=(start+finish)/2;
          merge_sort(pin,start,middle);
          merge_sort(pin,middle+1,finish);
          merge(pin,start,finish);
      }
}
void merge(int *pinakas, int start, int finish)
{
	int C[SIZE];
	int i,j,k;
	int middle, n, m;
	
	middle=(start+finish)/2;
	
	/* 1os pinakas PIN[start..middle]=PIN[i..n] */	
	i=start;
	n=middle;
	/* 2os pinakas PIN[middle+1..finish]=PIN[j...m] */	
	j=middle+1;
	m=finish;
	/* C: sigxwneumenos pinakas */	
	k=0;
	
	/* 1. Sigxwneusi twn dio pinakwn */
	while (i<=n && j<=m)
	{
		if (pinakas[i]<pinakas[j])
		{
			C[k]=pinakas[i];
			k++;
			i++;
		}
		else
		{
			C[k]=pinakas[j];
			k++;
			j++;
		}
	}
	
	/* 2. Antigrafi tou pinaka pou perissevei sto telos tou sigxwneumenou pinaka */
	
	if (i==n+1) /* Eksantlithike o 1os pinakas */
	{
		while (j<=m)
		{
			C[k]=pinakas[j];
			k++;
			j++;
		}
	}
	else /* Eksantlithike o 2os pinakas */
	{
		while (i<=n)
		{
			C[k]=pinakas[i];
			k++;
			i++;
		}
	}	
	
	/* 3. Antigrafi tou C ston pinakas */
	
	k=0;
	
	i=start;
	while (i<=finish)
	{
		pinakas[i]=C[k];
		i++;
		k++;
	}
}

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void print_array(int *pin,int n)
{
    int i;
      printf("[");
      for(i=0;i<n-1;i++){
          printf("%d, ",pin[i]);
      }
      printf("]");
}
