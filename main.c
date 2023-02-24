#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *dosya;

	dosya = fopen("binary.bin", "w");
	
	/* 
		Decimal To Binary
		
		integer say�y� �ncelikle say�n� kendisini 2ye b�l�p daha sonra b�l�m de�erleri 1 olana kadar 2ye b�l�yoruz
		�rnek 15 => 15/2 = kalan 1 b�l�m 7 => 7/2 kalan 1 b�l�m 3 => 3/2 kalan 1 b�l�m 1 buraya kadar 
		daha sonra son b�l�mden ba�layarak kalan de�erleri s�ral�yoruz
		sonu� = 1111
		
		�rnek 28 => 28/2 = kalan 0 b�l�m 14 => 14/2 kalan 0 b�l�m 7 => 7/2 kalan 1 b�l�m 3 => 3/2 kalan 1 b�l�m 1 buraya kadar 
		11100
		
		*/
	
	int i;
	for(i = 0; i<100; i++)
	{
		dosya = fopen("binary.bin", "a");


		int sayi = rand()%101; // rasgele say� olu�turma 0 ile 100 aras�nda 
					
		//fprintf(fptr, "say� => %d\n", sayi);
		

		int binary[7] = {0,0,0,0,0,0,0};

		// say�lar�m�z 1-100 aras�nda oldu�u i�in 7 elemanl� bir diziye ihtiya� duyuyoruz 2^7 = 128
		
		//printf("%d\n" , sayi);

		// 
				
		int j=0;
		while(floor(sayi/2) > 0) // b�l�m 1 olana kadar devam et 
		{
			
			binary[j] = sayi%2; // kalan� diziye aktar�yoruz
						
			sayi = floor(sayi/2); // say�y� 2 ye b�l�p tekrar say�ya esitliyoruz
			
			++j;
		}
		
		binary[j] = sayi%2; // son b�l�m� diziye aktarma i�lemi
		
		// �u ana kadar yap�lan dizilen say�lar�n tam tersi bizim binary sistemimizi olu�turuyor
		// o y�zden diziyi tersten bast�rmam�z gerek
		

		
		int k;
		
		for(k=6; k>=0; k--)
		{
			// NOT baz� say�lar�m�z 3-4 bit veya daha az bit ile g�sterilebilir dizinin boyutu fazla oldu�undan farkl� de�erler ortaya ��k�yor (bug)
			// bunu gidermek ad�na dizi i�erisindeki elemanlar 0 veya 1 ise dizinin i�idekini g�ster de�ilse 0 g�ster diyerek ��zd�m
			
			if(binary[k] == 1 || binary[k] == 0)
			{
				// printf("%d", binary[k]);
				
				fprintf(dosya, "%d", binary[k]);

			}
			
		}

		//printf("\n*********************************\n");
		
		//dosya = fopen("binary.txt", "a");
		//fprintf(dosya, "\n");
		
	}
	
	fclose(dosya);

		
	char karakter[7][20];
	int x=0;
	
	if((dosya = fopen("binary.txt", "rb") != NULL ))
	{
		
		while(!feof(dosya))
		{
			fscanf(dosya, "%s", &karakter[x]);
			printf("%s", karakter[x]);
			x++;
		}
	}
	else
	{
		printf("dosya bulunamad�");
	}
	
	
   
   
   
   
   fclose(dosya);
	
	return 0;
}



