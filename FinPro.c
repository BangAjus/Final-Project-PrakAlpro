#include <stdio.h>
#include <stdlib.h>

struct data{
    char *nama, *harga;
    int qty;
}data[50];

int curr = 0;
int ulg = 1;
void baca(){
    FILE *baca = fopen("dagang.txt", "r");
    if(baca != NULL){
        printf("File ada!");
        while(!feof(baca)){
            if(ulg == 1){
                fscanf(baca, "%s", &data[curr].nama);
            }
            if(ulg == 2){
                fscanf(baca, "%s", &data[curr].harga);
            }
            if(ulg == 3){
                fscanf(baca, "%d", &data[curr].qty);
            }
            if(ulg == 4){
                ulg = 0;
                curr++;
            }
            ulg++;
        }
    }
    else{
        printf("File kosong!");
    }
    fclose(baca);
}
void tulis(){
    FILE *tulis = fopen("dagang.txt", "w");
    for(int i = 0; i < curr+1; i++){
        fprintf(tulis, "%s", data[i].nama);
        fprintf(tulis, "%s", data[i].harga);
        fprintf(tulis, "%d", data[i].qty);
        fprintf(tulis, "===");
    }
}
void tambah(int n){
    int t = curr;
    printf("Data yang ditambahkan : %d\n", n);
    for(int i = t+1; i < t+1+n; i++){
        printf("Masukkan nama barang : ");
        gets(data[i].nama);
        printf("Masukkan harga barang : ");
        gets(data[i].harga);
        printf("Masukkan kuantitas : ");
        scanf("%d", &data[i].qty);
        curr++;
    }
    tulis();
}
void cetak(){
    printf("Mencetak data : \n");
    for(int i = 0; i < curr+1; i++){
        puts(data[i].nama); printf("\n");
        puts(data[i].harga); printf("\n");
        printf("%d\n", data[i].qty);
    }
}
void transaksi(int a, int b){
    if(data[a].qty == 0){
        printf("Maaf, barang sudah habis....");
    }
    else{
        printf("%s sebanyak %d berhasil dibeli!", data[a].nama, b);
        data[a].qty -= b;
    }
}
int main(){
    return 0;
}