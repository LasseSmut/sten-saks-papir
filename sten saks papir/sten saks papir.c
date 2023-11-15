#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

#define RESET_COLOR "\033[0m"
#define GREEN_COLOR "\033[0;32m"
#define RED_COLOR "\033[0;31m"
#define ORANGE_COLOR "\033[0;33m"


bool jegHarValgt = false;
int score = 0;
int botscore = 0;
int uafgjort = 0;
int valgAfSpilLoad = 0;
int tom = 2;



int gemFiler () {
    FILE *inputFile = fopen("gemspil.txt", "r+");
    FILE *tempFile = fopen("temp.txt", "w");

    if (!inputFile || !tempFile) {
        printf("fil oprettet, for at spil videre skal du genstarte spillet\n");
        FILE *inputFile = fopen("gemspil.txt", "a+");
        fprintf(inputFile, "0 0 0\n 0 0 0 \n 0 0 0");
    }

    int denLinjeDenErPa = 0;
    int forrigeScore, forrigeBotScore, forrigeUafgjort;

    while (fscanf(inputFile, "%d %d %d", &forrigeScore, &forrigeBotScore, &forrigeUafgjort) == 3) {
        denLinjeDenErPa++;

        if (denLinjeDenErPa == valgAfSpilLoad) {

            fprintf(tempFile, "%d %d %d\n", score, botscore, uafgjort);
        } else {
            fprintf(tempFile, "%d %d %d\n", forrigeScore, forrigeBotScore, forrigeUafgjort);
        }
    }

    if (denLinjeDenErPa < valgAfSpilLoad) {
        fprintf(tempFile, "%d %d %d\n", score, botscore, uafgjort);
    }
    fclose(inputFile);
    fclose(tempFile);

    remove("gemspil.txt");
    rename("temp.txt", "gemspil.txt");

    return 0;


}
int loadFiler () {
        FILE *file = fopen("gemspil.txt", "r");
        if(file!=NULL) {
            int linjeStop = 0;
            while(fscanf(file,"%d %d %d", & score, & botscore, & uafgjort)==3){
                linjeStop++;
                if (linjeStop == valgAfSpilLoad) {
                    break;
                }
            }
            fclose(file);


}
}
int sten() {
    printf("du har valgt sten\n");
}

int saks() {
    printf("du har valgt saks\n");
}

int papir() {
    printf("du har valgt papir\n");
}
void setColor(const char *color) {
    printf("%s", color);
}


int vinder() {
    setColor(GREEN_COLOR);
    printf("du vandt \n");
    setColor(RESET_COLOR);
    score += 1;
}

int taber() {
    setColor(RED_COLOR);
    printf("du tabte \n");
    setColor(RESET_COLOR);
    botscore += 1;
}
int uafgjortBesked() {
    setColor(ORANGE_COLOR);
    printf("uafgjort\n");
    setColor(RESET_COLOR);
    uafgjort += 1;

}

int printscore () {
    printf("Din score: %i \nBottens score: %i \nUafgjort: %i", score, botscore, uafgjort);
}

int hvemVinder () {

    if (botscore < score) {
        setColor(GREEN_COLOR);
        printf("\nDu vinder!!\n");
        setColor(RESET_COLOR);
    }
    else if (botscore > score) {
        setColor(RED_COLOR);
        printf("\nbotten vinder!!\n");
        setColor(RESET_COLOR);
    }
    else {
        setColor(ORANGE_COLOR);
        printf("\nuafgjort!!\n");
        setColor(RESET_COLOR);
    }
}



int main() {
    bool startSpil = false;
    int choice;
    int bottensvalg;
    int start;
    int screenHandler = 1;
    int valgAfSpil;
    int ValgAfSave;

    while (screenHandler == 1){
        printf("\n\nvalg: \n");
        printf("1. Start spil\n");
        printf("2. load et spil\n");
        printf("3. ga ud\n");
         {
            scanf("%d", &start);
        }
        switch (start) {
            case 1:
                            system("cls");
            screenHandler = 2;
            break;

            case 2:
                            system("cls");
            screenHandler = 3;
            break;

            case 3:
                system("cls");
                printf("\nVi ses!...\n");
                return 0;

            default:
                printf("proev igen.\n");
        }
    }


    if (screenHandler == 3){
        printf("\n\n indtast det spil du vil vaelge at spille 1-3: \n");


        printf("\n\n indtast 4 for at ga tilbage \n");

         {
            scanf("%d", &valgAfSpil);
        }
        switch (valgAfSpil) {
            case 1:
                            system("cls");
                printf("du har loaded spil 1 \n");
                valgAfSpilLoad = 1;
                loadFiler();
                screenHandler = 2;
                break;
            case 2:
                            system("cls");
                printf("du har loaded spil 2\n");
                valgAfSpilLoad = 2;
                loadFiler();
                screenHandler = 2;
                break;
            case 3:
                            system("cls");
                printf("du har loaded spil 3 \n");
                valgAfSpilLoad =3;
                loadFiler();
                screenHandler = 2;
                break;
            case 4:
                            system("cls");
                screenHandler = 2;
                break;

            default:
                printf("ugyldig.\n");


        }
    }



    while (screenHandler == 2) {
        printf("\n\nvalg: \n");
        printf("1. sten\n");
        printf("2. saks\n");
        printf("3. papir\n");
        printf("4. gemspil\n");
        printf("5. jeg gider ik mere\n");

         {
            scanf("%d", &choice);
            bottensvalg = rand() % 3+1;

        }


        switch (choice) {
            case 1:
                system("cls");
                sten();
                jegHarValgt = true;
                break;
            case 2:
                system("cls");
                saks();
                jegHarValgt = true;
                break;
            case 3:
                system("cls");
                papir();
                jegHarValgt = true;
                break;
            case 4:
                screenHandler = 4;
                jegHarValgt = false;
                break;

            case 5:
                                system("cls");
                printscore();
                hvemVinder();
                printf("\nVi ses!...\n");
                return 0;

            default:
                printf("proev igen.\n");
        }
        if (screenHandler == 4) {
        printf("\n\nvaelg de slot du vil gemme i: \n");
        printf("1.\n");
        printf("2.\n");
        printf("3.\n");
         {
            scanf("%d", &ValgAfSave);
        }
        switch (ValgAfSave) {
            case 1:
            system("cls");
            valgAfSpilLoad = 1;
            gemFiler();
            screenHandler = 2;
            printf("du har gemt dit spil i slot 1\n");
            break;

            case 2:
            system("cls");
            valgAfSpilLoad = 2;
            gemFiler();
            screenHandler = 2;
            printf("du har gemt dit spil i slot 2\n");
            break;

            case 3:
            system("cls");
            valgAfSpilLoad = 3;
            gemFiler();
            screenHandler = 2;
            printf("du har gemt dit spil i slot 3\n");
            break;

            default:
                printf("proev igen.\n");
        }

        }


        if (jegHarValgt == true) {
        switch (bottensvalg) {
            case 1:
                printf("botten har valgt sten \n");
                break;
            case 2:
                printf("botten har valgt saks \n");
                break;
            case 3:
                printf("botten har valgt papir \n");
                break;

            default:
                printf("ugyldig.\n");


        }



        if (bottensvalg == choice) {
            uafgjortBesked();
            printscore();

        }
        else if ((bottensvalg == 1 && choice == 3) || (bottensvalg == 2 && choice == 1) || (bottensvalg == 3 && choice == 2)) {
            vinder();
            printscore();

        } else {
            taber();
            printscore();
        }
    }
    }
}



