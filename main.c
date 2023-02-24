#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *dosya;

	dosya = fopen("binary.bin", "w");
	
	/* 
		Decimal To Binary
		
		integer sayýyý öncelikle sayýný kendisini 2ye bölüp daha sonra bölüm deðerleri 1 olana kadar 2ye bölüyoruz
		örnek 15 => 15/2 = kalan 1 bölüm 7 => 7/2 kalan 1 bölüm 3 => 3/2 kalan 1 bölüm 1 buraya kadar 
		daha sonra son bölümden baþlayarak kalan deðerleri sýralýyoruz
		sonuç = 1111
		
		örnek 28 => 28/2 = kalan 0 bölüm 14 => 14/2 kalan 0 bölüm 7 => 7/2 kalan 1 bölüm 3 => 3/2 kalan 1 bölüm 1 buraya kadar 
		11100
		
		*/
	
	int i;
	for(i = 0; i<100; i++)
	{
		dosya = fopen("binary.bin", "a");


		int sayi = rand()%101; // rasgele sayý oluþturma 0 ile 100 arasýnda 
					
		//fprintf(fptr, "sayý => %d\n", sayi);
		

		int binary[7] = {0,0,0,0,0,0,0};

		// sayýlarýmýz 1-100 arasýnda olduðu için 7 elemanlý bir diziye ihtiyaç duyuyoruz 2^7 = 128
		
		//printf("%d\n" , sayi);

		// 
				
		int j=0;
		while(floor(sayi/2) > 0) // bölüm 1 olana kadar devam et 
		{
			
			binary[j] = sayi%2; // kalaný diziye aktarýyoruz
						
			sayi = floor(sayi/2); // sayýyý 2 ye bölüp tekrar sayýya esitliyoruz
			
			++j;
		}
		
		binary[j] = sayi%2; // son bölümü diziye aktarma iþlemi
		
		// þu ana kadar yapýlan dizilen sayýlarýn tam tersi bizim binary sistemimizi oluþturuyor
		// o yüzden diziyi tersten bastýrmamýz gerek
		

		
		int k;
		
		for(k=6; k>=0; k--)
		{
			// NOT bazý sayýlarýmýz 3-4 bit veya daha az bit ile gösterilebilir dizinin boyutu fazla olduðundan farklý deðerler ortaya çýkýyor (bug)
			// bunu gidermek adýna dizi içerisindeki elemanlar 0 veya 1 ise dizinin içidekini göster deðilse 0 göster diyerek çözdüm
			
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
		printf("dosya bulunamadý");
	}
	
	
   
   
   
   
   fclose(dosya);
	
	return 0;
}



