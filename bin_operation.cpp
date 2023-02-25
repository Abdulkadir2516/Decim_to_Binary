#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	// binary file reading and writing
	
	FILE *dd;
	char ad[20];
	dd=fopen("./binary.txt","r");
	if (dd == NULL)
	{
		printf("Sürücü veya dosya bulunamadý\n");

	}
	else
	{ 
		while (!feof(dd))
		{ 
			fgets(ad, 8, dd);
			printf("%s\n", ad);
		}
		
	fclose(dd);
	
	}

	
	return 0;
}
