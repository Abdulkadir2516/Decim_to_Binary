#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	// binary file reading and writing
	
	FILE *dosya;
	char bin[700];
	char byte[7];
	dosya=fopen("./binary.txt","r");
	if (dosya == NULL)
	{
		printf("Sürücü veya dosya bulunamadý\n");

	}
	else
	{ 
		int i =0;
		while (!feof(dosya))
		{ 
			fgets(byte, 8, dosya);
			
			int x;
			for(x = 0; x<7; x++)
			{
				bin[i] = byte[x];
				i++;
			}
			
			
		}
		
	fclose(dosya);
	
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
	
	
	printf("Arama yapmak istediðiniz binary kodu giriniz: ");
	
	char bin_code[7];
	
	scanf("%s", bin_code);
	
	// arama
	int q;
	int say;
	for(q=0; q<sizeof(bin); q=q+7)
	{
		int w;
		int d = 0;
		say = 0;
		for(w=q; w<q+7; w++)
		{
			if(bin_code[d] == bin[w])
			{
				say++;
				
				if(say==7)
				{
					printf("bu sayý var");
					break;
			
				}
				
			}
			d++;
			
		}
		
	}
	
	

	
	
	
	return 0;
}
