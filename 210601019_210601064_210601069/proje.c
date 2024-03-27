#include <stdio.h>

int il_plaka_kodu[6];
int mv_kontenjani[6];
int parti_oy[6][6];
int parti_oy2[6][6];
int parti_vekil[6][6];
float oy_yuzdesi[6][6];
char parti_ad[6][6];
int doldurulan_kontenjan[6];
int toplam_oy_sayisi[6];



int toplam_oy_hesapla(int ii){
    unsigned int sum=0;
    int i=0;
    for(i=0; i<6; i++){
        sum += parti_oy[ii][i];
    }
    return sum;
}

void mv_hesapla(int i){
    int max_oy=0;
    int j=0;
    for(j=0; j<6; j++){
        parti_oy2[i][j] = parti_oy[i][j];
    }
        
    while(1){
	
        for(j=0; j<6; j++){
            if(parti_oy2[i][j] > max_oy){
                max_oy = parti_oy2[i][j];
            }
        }
        for(j=0; j<6; j++){
            if(parti_oy2[i][j] == max_oy){
                parti_oy2[i][j] /= 2;
                parti_vekil[i][j] += 1;
                doldurulan_kontenjan[i]++;
            }
        }
        max_oy = 0;
        if(doldurulan_kontenjan[i] == mv_kontenjani[i]){
            break;
        }
    }
}

void yuzde_hesapla(int i){
    int j=0;
    for(j=0; j<6; j++){
        oy_yuzdesi[i][j] = ((float)parti_oy[i][j] / (float)toplam_oy_sayisi[i])*100; 
    }
}

void birincileri_yazdir(){
    printf("\n");
    int birincilik = 0;
    char tempchar;
    int i=0;
    for(i=0; i<6; i++){
        switch(i){
            case 0:
            tempchar = 'A';
            break;
            
            case 1:
            tempchar = 'B';
            break;
            
            case 2:
            tempchar = 'C';
            break;
            
            case 3:
            tempchar = 'D';
            break;
            
            case 4:
            tempchar = 'E';
            break;
            
            case 5:
            tempchar = 'F';
            break;
        }
        
        int j=0;
        for(j=0; j<5; j++){
            if(parti_ad[j][0] == tempchar){
                birincilik = birincilik + 1;
            }
        }
        printf("%c Partisi, birinci oldugu il sayisi:%d \n", tempchar, birincilik);
        birincilik = 0;
    }
}

int main()
{   
    printf("plaka kodu, mv kontenjani, a,b,c,d,e,f partilerinin aldigi oy bilgilerini gir.");
    
    int s=0;
    for(s=0; s<5; s++){
        scanf("%i %i %i %i %i %i %i %i \n", 
        &il_plaka_kodu[s], &mv_kontenjani[s], 
        &parti_oy[s][0], &parti_oy[s][1], &parti_oy[s][2], 
        &parti_oy[s][3], &parti_oy[s][4], &parti_oy[s][5]);
        
    parti_ad[s][0]   = 'A';
    parti_ad[s][1]   = 'B';
    parti_ad[s][2]   = 'C';
    parti_ad[s][3]   = 'D';
    parti_ad[s][4]   = 'E';
    parti_ad[s][5]   = 'F';
    doldurulan_kontenjan[s] = 0;
    toplam_oy_sayisi[s] = toplam_oy_hesapla(s);
    }
    
    unsigned int sortlist[6] = {0,0,0,0,0,0};
    int i=0, j=0, k=0;
    

    // Turkiye geneli
    mv_kontenjani[5] = mv_kontenjani[0] + mv_kontenjani[1] + mv_kontenjani[2] + mv_kontenjani[3] + mv_kontenjani[4];
    
    parti_oy[5][0]   = parti_oy[0][0] + parti_oy[1][0] + parti_oy[2][0] + parti_oy[3][0] + parti_oy[4][0] ;
    parti_oy[5][1]   = parti_oy[0][1] + parti_oy[1][1] + parti_oy[2][1] + parti_oy[3][1] + parti_oy[4][1] ;
    parti_oy[5][2]   = parti_oy[0][2] + parti_oy[1][2] + parti_oy[2][2] + parti_oy[3][2] + parti_oy[4][2] ;
    parti_oy[5][3]   = parti_oy[0][3] + parti_oy[1][3] + parti_oy[2][3] + parti_oy[3][3] + parti_oy[4][3] ;
    parti_oy[5][4]   = parti_oy[0][4] + parti_oy[1][4] + parti_oy[2][4] + parti_oy[3][4] + parti_oy[4][4] ;
    parti_oy[5][5]   = parti_oy[0][4] + parti_oy[1][5] + parti_oy[2][5] + parti_oy[3][5] + parti_oy[4][5] ;
    toplam_oy_sayisi[5] = toplam_oy_hesapla(5);
    parti_ad[5][0]   = 'A';
    parti_ad[5][1]   = 'B';
    parti_ad[5][2]   = 'C';
    parti_ad[5][3]   = 'D';
    parti_ad[5][4]   = 'E';
    parti_ad[5][5]   = 'F';
    
    unsigned int temp = 0;
    char tempchar;
    for(i=0; i<6; i++){
        if(i != 5){
            printf("Il Plaka Kodu: %d\n", il_plaka_kodu[i]);
        } else{
            printf("Turkiye Geneli \n");
        }
        printf("Milletvekili Kontenjani: %d\n", mv_kontenjani[i]);
        printf("Gecerli Oy Sayisi: %d\n", toplam_oy_sayisi[i]);
        printf("\t Oy Sayisi \t Oy Yuzdesi \t MV Sayisi\n");
        printf("\t _________ \t __________ \t _________\n");
        
        // bubble sort
        temp = 0;
        for(j=0; j<6; j++){
            for(k = j+1; k<6; k++){
                if(parti_oy[i][j] < parti_oy[i][k]){
                    temp = parti_oy[i][j];
                    parti_oy[i][j] = parti_oy[i][k];
                    parti_oy[i][k] = temp;
                    
                    tempchar = parti_ad[i][j];
                    parti_ad[i][j] = parti_ad[i][k];
                    parti_ad[i][k] = tempchar;
                }
            }
        }
        
        // mv hesapla
        mv_hesapla(i);
        
        // ortalama oy hesapla
        yuzde_hesapla(i);
        
        for(j=0; j<6; j++){
            printf("%c P. \t %d \t \t %% %.2f \t \t %d \n", parti_ad[i][j], parti_oy[i][j],
            oy_yuzdesi[i][j], parti_vekil[i][j]);
        }
        getchar();
    }
    

     printf("\n");
     printf("Iktidar partisi: %c\n", parti_ad[5][0]);
     printf("Ana muhalefet partisi: %c\n", parti_ad[5][1]);
    
    
    // Birinciler listesi
   // birincileri_yazdir();
    
    printf("Program sonlandi.\n");
    return 0;
}
