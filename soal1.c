/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : Data Manipulation and External Files
 *   Hari dan Tanggal    : 27 April 2026
 *   Nama (NIM)          : Muhammad Adli Syauqi (13224082)
 *   Nama File           : soal1.c
 *   Deskripsi           : Program menerima sekuens bilangan sampai diterima -1 kemudian melakukan sorting dan mencari median dengan dynamic array
 *  
 */

 #include <stdio.h>
 #include <stdlib.h>

 int main(){
    int capacity = 5;
    int *array = (int *)malloc(capacity*sizeof(int));

    int input;
    scanf("%d", &input);

    int i = 0;
    while(input != -1){
        if(capacity <= i){
            capacity *= 2;
            array = (int *)realloc(array, capacity);
        }

        array[i] = input;
        i++;
        scanf("%d", &input);
    }

    // for(int j = 0; j < i; j++){
    //     printf("%d ", array[j]);
    // }

    int temp;
    // sorting
    for(int j = 0; j < i-1; j++){
        for(int k = 0; k < i-j-1; k++){
            if(array[k] > array[k+1]){
                temp = array[k+1];
                array[k+1] = array[k];
                array[k] = temp;
            }
        }
    }

    printf("COUNT %d\n", i);

    printf("SORTED ");
    for(int j = 0; j < i; j++){
        printf("%d ", array[j]);
    }
    printf("\n");

    float median = 0;

    printf("MEDIAN ");
    if(i%2 == 1){ // i = 7, median = 3, = (i-1)/2
        printf("%d\n", array[(i-1)/2]);
    }else{ //  i = 8, median = 3 (i/2)-1 dan 4 (i/2)
        median = (float)((array[(i/2)-1]+array[(i/2)])/2);
        printf("%.2f\n", median);
    }
 }
