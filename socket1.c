/*Tugas Teori Bahasa Formal dan Otomata*/
/*Nama : Mathias Novianto  (13516021), Rizky Andyno Ramadhan (13516063)*/
/*Tanggal : 17 September 2017*/
/*Deskripsi : program yang menerima beberapa nilai yang merupakan state-state dari DFA, state pertama diasumsikan merupakan initial state*/


#include <stdio.h>
#include <string.h>

void copystring(char * dest, char * src, char * finalState, int * nFinal) {
/*Membentuk sebuah string yang telah dihilangkan tanda '*' nya, memasukan string tersebut ke finalState, dan menambahkan nilai nFinal*/
/*IS : menerima sebuah string*/
/*FS : menghasilkan string baru yang tanpa tanda '*', jika memiliki karakter '*', memasukan ke finalState, dan menambahkan nFinal*/
/*Jika tidak, mengcopy dari src ke dest*/
    int indeks = 1; //
    if (src[0] == '*') {
        while (src[indeks] != '\0') {//melakukan copy setiap character hingga menemukan NULL/'\0'
            dest[indeks-1] = src[indeks];
            indeks++;
        };
        dest[indeks-1] = '\0';
        strcpy(finalState, dest);//memasukan ke finalState
        *nFinal = *nFinal + 1;//menambahkan nilai nFinal
    } else {//jika tanda awal bukan '*', langsung copy string
        strcpy(dest, src);
    }
}


int main(){
    /* KAMUS */
    FILE *state_file;
    char state[20][20][15];//sebuah matriks of string, maksimal jumlah state=10
    char finalState[20][15];
    char temp1[15],temp2[15],temp3[15],temp4[15],temp5[15],temp6[15],temp7[15],temp8[15];
    char temp9[15],temp10[15],temp11[15],temp12[15],temp13[15],temp14[15];
    char jalurState[30][15];
    char tempInput[15];
    char listOfState[20][15];
    char cChar;
    char cString[15];
    char masukan[100];
    int rowKeBerapa,isFinal,j;
    int length=0;
    int i = 0;
    int first=0;
    int jumlahFinal = 0;
    int jumlahRow;
    char current_state[15];

    /* ALGORITMA */

    /*PENGISIAN STATE YG MUNGKIN*/
    strcpy(listOfState[0],"socket");
    strcpy(listOfState[1],"bind");
    strcpy(listOfState[2],"listen");
    strcpy(listOfState[3],"accept");
    strcpy(listOfState[4],"connect");
    strcpy(listOfState[5],"wait");
    strcpy(listOfState[6],"close");
    strcpy(listOfState[7],"blocking");
    strcpy(listOfState[8],"request");
    strcpy(listOfState[9],"receive");
    strcpy(listOfState[10],"read");
    strcpy(listOfState[11],"write");
    strcpy(listOfState[12],"abort");

    state_file =fopen("inputt.txt","r");
    if (!state_file || feof(state_file)){//jika ada error saat pembacaan file eksternal
        return 1;
    } else {
        /*PEMBACAAN STATE DFA DARI FILE EKSTERNAL*/
        while (!feof(state_file)){
            fscanf(state_file, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9,temp10,temp11,temp12,temp13,temp14);/*membaca satu baris yang secara berurutan terdiri dari state awal,
            jika dimasukkan karakter 0, dan jika dimasukkan karakter 1*/

            copystring(state[i][0],temp1,finalState[jumlahFinal],&jumlahFinal);
            strcpy(state[i][1],temp2);
            strcpy(state[i][2],temp3);
            strcpy(state[i][3],temp4);
            strcpy(state[i][4],temp5);
            strcpy(state[i][5],temp6);
            strcpy(state[i][6],temp7);
            strcpy(state[i][7],temp8);
            strcpy(state[i][8],temp9);
            strcpy(state[i][9],temp10);
            strcpy(state[i][10],temp11);
            strcpy(state[i][11],temp12);
            strcpy(state[i][12],temp13);
            strcpy(state[i][13],temp14);
            if(i == 0){
                strcpy(current_state, state[i][0]);//menjadikan start state
            }
            i++;
        };
        jumlahRow = i;

        /*MEMBACA MASUKAN DARI USER*/
        scanf("%s",&tempInput);
        if(strcmp(tempInput,"end")==0){
            printf("GAGAL CUY");
        }
        else{
            while(strcmp(tempInput,"end")!=0){
                /*SEARCHING CURRENT STATE DI BARIS KEBERAPA*/
                if(first==0){//jika pertama kali print ke layar, tanpa tanda -->
                    printf("%s",current_state);
                    first=1;
                }
                i=0;
                while(i<jumlahRow && (strcmp(state[i][0],current_state) != 0)){
                    i++;
                }
                rowKeBerapa=i;
                if (strcmp(tempInput,listOfState[0])==0) {
                    strcpy(current_state, state[rowKeBerapa][1]);
                } else if (strcmp(tempInput,listOfState[1])==0) {
                    strcpy(current_state, state[rowKeBerapa][2]);
                } else if (strcmp(tempInput,listOfState[2])==0) {
                    strcpy(current_state, state[rowKeBerapa][3]);
                } else if (strcmp(tempInput,listOfState[3])==0) {
                    strcpy(current_state, state[rowKeBerapa][4]);
                } else if (strcmp(tempInput,listOfState[4])==0) {
                    strcpy(current_state, state[rowKeBerapa][5]);
                } else if (strcmp(tempInput,listOfState[5])==0) {
                    strcpy(current_state, state[rowKeBerapa][6]);
                } else if (strcmp(tempInput,listOfState[6])==0) {
                    strcpy(current_state, state[rowKeBerapa][7]);
                } else if (strcmp(tempInput,listOfState[7])==0) {
                    strcpy(current_state, state[rowKeBerapa][8]);
                } else if (strcmp(tempInput,listOfState[8])==0) {
                    strcpy(current_state, state[rowKeBerapa][9]);
                } else if (strcmp(tempInput,listOfState[9])==0) {
                    strcpy(current_state, state[rowKeBerapa][10]);
                } else if (strcmp(tempInput,listOfState[10])==0) {
                    strcpy(current_state, state[rowKeBerapa][11]);
                } else if (strcmp(tempInput,listOfState[11])==0) {
                    strcpy(current_state, state[rowKeBerapa][12]);
                } else if (strcmp(tempInput,listOfState[12])==0) {
                    strcpy(current_state, state[rowKeBerapa][13]);
                }


                /*PENGOLAHAN STRING YANG DIDAPAT DARI USER*/


                i=0;

                /* PENCETAKAN STATE */
                if(first!=0){
                    printf("-->%s",current_state);
                }
                i=0;

                /*SEARCHING CURRENT STATE APAKAH ADA DI FINAL STATE*/
                while(i<jumlahFinal && (strcmp(finalState[i],current_state) != 0)){
                    i++;
                }


                scanf("%s",&tempInput);
            }
        }


        /*PENGECEKAN APAKAH STATE TERAKHIR MEUPAKAN FINAL STATE*/
        if(strcmp(finalState[i],current_state) == 0){
            isFinal=1;
        }
        else{
            isFinal=0;
        }
        printf("\n");

        /*PENCETAKAN KE LAYAR APAKAH STRING DITERIMA ATAU TIDAK*/
        if(isFinal==1){
            printf("VALID!\n");
        } else {
            printf("INVALID!\n");
        }
    };
    fclose(state_file);
    return 0;
}
