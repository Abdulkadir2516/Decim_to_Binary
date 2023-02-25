#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	// binary file reading and writing
	
	FILE *dd;
	char bin[700];
	char ad[20];
	dd=fopen("./binary.txt","r");
	if (dd == NULL)
	{
		printf("Sürücü veya dosya bulunamadý\n");

	}
	else
	{ 
		int i =0;
		while (!feof(dd))
		{ 
			fgets(ad, 8, dd);
			
			int x;
			for(x = 0; x<7; x++)
			{
				bin[i] = ad[x];
				i++;
			}
			
			
		}
		
	fclose(dd);
	
	}
	
	int j;
	for(j=0; j<sizeof(bin); j=j+7)
	{
		int k;
		for(k=j; k<j+7; k++)
		{
			printf("%c", bin[k]);
		}
		printf("\n");
	}
	
	
	
	
	
	return 0;
}
