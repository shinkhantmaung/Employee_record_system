#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"multi.h"

int main (){
    while(1){
    char  choice;
    int pass;
    system("cls");
    printf("------Welcome!------\n");
    printf("\n1. Add the record ");
    printf("\n2. View the record ");
    printf("\n3. Delete the record ");
    printf("\n4. Mofity the record ");
    printf("\n5. Exit ");
    printf("\nEnter : ");
    choice  = getche();
   switch(choice)
    {
        case '1':
        system("cls");
        case_1();
       choice  = getche();
        break;

        case '2':
        system("cls");
        case_2();
        choice  = getche();
        break;

        case '3':
        system("cls");
        case_3();
        choice = getche();
        break;

        case '4':
        system("cls");
        printf("Enter a password (4-Digit): ");
        scanf("%d",&pass);
        if(pass == 0000 ){
        case_4();
        }
        else{
        printf("Your Password isn't Worng");
        }
        choice = getche();
        break;

        case '5':
        exit(choice);

        default :
        printf("\nTry Again");
        break;
    }
    }
getchar();
return 0;
}
