#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
   struct employee
    {
        char name[50]; ///name of employee
        int id; ///id of employee
        int age; /// age of employee
        float  bs; /// basic salary of employee
        float total;///total for basic salary
        float total1; ///total salary for each month
        int salary;
    } e;
void case_1(){ ///for data collect
    int a,n,month;
    //int salary;
    int sum= 0 ;

    FILE*fptr;
   fptr=fopen("hello.txt","a+");
   if (fptr == NULL){
    printf("Can't open this file");
    exit(1);
   }
   printf("\nEnter number of employee :  ");
   scanf("%d",&n);
    printf("Enter number of month : ");
   scanf("%d",&month);

   for (int i =0 ; i<n; i++)
   {
   printf("\nEnter ID : ");
   scanf("%d",&e.id);
   printf("Enter name: ");
   scanf("%s",e.name);
   printf("Enter age: ");
   scanf("%d", &e.age);
   printf("Enter basic salary: ");
   scanf("%f", &e.bs);
   printf("Enter salary for (%d) month: ",month);
    for (a=0 ; a<month ; a++)
        {
        scanf("%d",&e.salary);
        sum=sum+e.salary;
        e.total=e.bs*month;
        e.total1= e.total - sum;
        }
    //printf("Total: %d",sum);

   fprintf(fptr,"\n%5d %20s %10d %16f %14f\n",e.id,e.name,e.age,e.total,e.total1);
   }
   printf("\nSuccessfully Added");
    fclose(fptr);
    }
void case_2(){ ///to show the data
    char c;
    FILE*fptr;
    fptr=fopen("hello.txt","r");
    if (fptr==NULL){
        printf("Can't open this file\n");
        exit(2);
    }
    printf("\n%5s %20s %10s %18s %12s\n","ID","NAME","AGE","Basic Salary","TO PAY");
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
}
void case_3(){ ///to delete the data
    FILE*fptr;
    fptr=fopen("hello.txt","w");
    fputs("", fptr);
    printf("Successfully Deleted");
    fclose(fptr);
}
void case_4(){ ///to mofity the data
    FILE * fPtr;
    FILE * fTemp;

    char buffer[100];
   // char newline[100];
    //char newline1[100];
    //char newline2[100];
    //char newline3[100];
    //char newline4[100];
    int line, count;

    printf("Enter line number to replace: ");
    scanf("%d", &line);

    fflush(stdin);

    printf("Enter new ID : ");
    scanf("%d",&e.id);
    printf("Enter new name : ");
    scanf("%s",e.name);
    printf("Enter new age : ");
    scanf("%d", &e.age);
    printf("Enter new basic salary : ");
    scanf("%f", &e.bs);
    printf("Enter new salary : ");
    scanf("%d",&e.salary);
    fPtr  = fopen("hello.txt", "r");
    fTemp = fopen("replace.tmp", "w+");

    if (fPtr == NULL || fTemp == NULL)
    {
        printf("\nUnable to open file.\n");
        exit(EXIT_SUCCESS);
    }
     count = 0;
    while ((fgets(buffer,100, fPtr)) != NULL)
    {
        count++;

        if (count == line)
        fprintf(fTemp,"%5d %20s %10d %16f %14f\n",e.id,e.name,e.age,e.total,e.total1);
        //fputc(" ",fTemp);
        //else
            fputc(" ", fTemp);
    }
    fclose(fPtr);
    fclose(fTemp);

    remove("hello.txt");

    rename("replace.tmp", "hello.txt");

    printf("\nSuccessfully ");
}
void case_5(){
     char c;
     int del_line, temp = 1;

    FILE*fp1, *fp2;
    fp1=fopen("hello.txt","r+");

     c = getc(fp1);
    while (c != EOF) {
        printf("%c", c);
        c = getc(fp1);
    }

    printf("\nEnter ID : ");
    scanf("%d", &del_line);
    rewind(fp1);

    fp2 = fopen("copy.txt", "w+");
    c = getc(fp1);

while (c != EOF) {
        if (c == ' ') {
            temp++;
        }

        if (temp != del_line){
        putc(c, fp2);
        }

        printf("Enter a name : ");
        putc(' ',fp2);
        fflush(stdin);

        while ((c = getchar()) != ' '){
                putc(c, fp2);
                fputs(" ", fp2);
                temp++;
            }
            c = getc(fp1);
            }

        fclose(fp1);
        fclose(fp2);

        remove("hello.txt");
        rename("copy.txt", "hello.txt");
        printf("Successfully\n");
}
