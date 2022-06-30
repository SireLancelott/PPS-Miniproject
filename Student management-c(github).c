#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define Student struct Stud

void add(FILE * fp);
void modify(FILE * fp);
void displayAll(FILE * fp);
void displayOne(FILE * fp);
FILE * del(FILE * fp);



struct Stud
{
    char name[100];
    char dept[50];
    int roll;
    int age;
    char class[50];
    char email[100];
};

int main()
{
    int choice;
    Student s;
    FILE * fp;
    char another;
    if((fp=fopen("db.txt","rb+"))==NULL)
    {
        if((fp=fopen("db.txt","wb+"))==NULL)
        {
            printf("Can't create or open Database.");
            return 0;
        }
    }

    //Open File Here
    while(1)
    {

    
        printf("\n+-------------------------------------+");
        printf("\n|~~~~~~STUDENT MANAGEMENT SYSTEM~~~~~~|");
        printf("\n+-------------------------------------+");
        printf("\n|1) Add a student                     |");
        printf("\n|2) View all the students             |");
        printf("\n|3) View an individual student        |");
        printf("\n|4) Modify a student                  |");
        printf("\n|5) Delete a student                  |");
        printf("\n|6) Quit                              |");
        printf("\n+-------------------------------------+");
        printf("\nEnter Your Option : ");
        scanf("%d",&choice);
        getchar();
        

        switch(choice)
        {
            case 1:
                add(fp);
                break;
            case 2:
                displayAll(fp);
                break;
            case 3:
                displayOne(fp);
                break;
            case 4:
                modify(fp);
                break;
            case 5:
                fp=del(fp);
                break;
            case 6:
                return 1;
                break;
        }
    }

}


void add(FILE * fp)
{

    char another='y';
    Student s;    int i;

    fseek(fp,0,SEEK_END);
    while(another=='y'||another=='Y')
    {


        printf("\nEnter full name of student: ");
        fflush(stdin);
        fgets(s.name,100,stdin);
        s.name[strlen(s.name)-1]='\0';

        printf("\nEnter department name: ");
        fflush(stdin);
        fgets(s.dept,50,stdin);
        s.dept[strlen(s.dept)-1]='\0';

        printf("\nEnter the roll number: ");
        scanf("%d",&s.roll);
        getchar();

        printf("\nEnter the Age: ");
        scanf("%d",&s.age);
        getchar();

        printf("\nEnter the Class: ");
        fflush(stdin);
        fgets(s.class,100,stdin);
        s.class[strlen(s.class)-1]='\0';

        printf("\nEnter E-mail: ");
        fflush(stdin);
        fgets(s.email,100,stdin);
        s.email[strlen(s.email)-1]='\0';


        fwrite(&s,sizeof(s),1,fp);

        printf("\nAdd another student?(Y/N)?");
        fflush(stdin);
        another=getchar();
    }
}
    


//To delete a student

FILE * del(FILE * fp)
{

    Student s;
    int flag=0,tempRoll,siz=sizeof(s);
    FILE *ft;

    if((ft=fopen("temp.txt","wb+"))==NULL)
    {
        printf("\nt!!! ERROR !!!\n");
        system("pause");
        return fp;
    }

    printf("\nEnter Roll number of Student to Delete the Record:");
    scanf("%d",&tempRoll);

    rewind(fp);


    while((fread(&s,siz,1,fp))==1)
    {
        if(s.roll==tempRoll)
        {
            flag=1;
            printf("\nRecord Deleted for");
            printf("\nName:%s\nDepartment:%s\nRoll number:%d\n",s.name,s.dept,s.roll);
            continue;
        }

        fwrite(&s,siz,1,ft);
    }


    fclose(fp);
    fclose(ft);

    remove("db.txt");
    rename("temp.txt","db.txt");

    if((fp=fopen("db.txt","rb+"))==NULL)
    {
        printf("ERROR");
        return  NULL;
    }

    if(flag==0) printf("\nNO STUDENT FOUND WITH THE INFORMATION\n");

    printf("\n");
    
    return fp;
}

//To display all students

void displayAll(FILE * fp)
{
    Student s;
    int i,siz=sizeof(s);

    rewind(fp);

    int empty=1;
    while((fread(&s,siz,1,fp))==1)
    {
        empty=0;
        printf("\nName : %s",s.name);
        printf("\nDepartment : %s",s.dept);
        printf("\nRoll Number : %d",s.roll);
        printf("\nAge: %d",s.age);
        printf("\nClass: %s",s.class);
        printf("\nEmail: %s",s.email);
        printf(" \n");


    }
    if (empty==1){
        printf("\nNo student records found!!!");}
    
    
    
}


//To display one student 
void displayOne(FILE *fp)
{

    int tempRoll,flag,siz,i;
    Student s;
    char another='y';

    siz=sizeof(s);

    while(another=='y'||another=='Y')
    {
        flag=0;
        printf("\nEnter Roll Number: ");
        scanf("%d",&tempRoll);
        getchar();

        rewind(fp);

        while((fread(&s,siz,1,fp))==1)
        {
            if(s.roll==tempRoll)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            printf("\nName : %s",s.name);
            printf("\nDepartment : %s",s.dept);
            printf("\nRoll Number : %d",s.roll);
            printf("\nAge: %d",s.age);
            printf("\nClass: %s",s.class);
            printf("\nE-mail: %s",s.email);
            printf(" \n");

        }
        else printf("\n!!!! ERROR RECORD NOT FOUND !!!!");


    printf("\nShow another student information? (Y/N)?");
    fflush(stdin);
    another=getchar();
    }

}



void modify(FILE * fp)
{

    Student s;
    int i,flag=0,tempRoll,siz=sizeof(s);


    printf("\nEnter Roll Number of Student to MODIFY the Record : ");
    scanf("%d",&tempRoll);
    getchar();

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        if(s.roll==tempRoll)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        fseek(fp,-siz,SEEK_CUR);
        printf("\nRecord Found\n");
        printf("\nStudent Name: %s",s.name);
        printf("\nStudent Roll: %d\n",s.roll);
        printf("\nEnter New Data for the student");

        printf("\nEnter Full Name of Student: ");
        fflush(stdin);
        fgets(s.name,100,stdin);
        s.name[strlen(s.name)-1]='\0';

        printf("\nEnter Department: ");
        fflush(stdin);
        fgets(s.dept,50,stdin);
        s.dept[strlen(s.dept)-1]='\0';

        printf("\nEnter Roll number: ");
        scanf("%d",&s.roll);
        getchar();


        printf("\nEnter the Age: ");
        scanf("%d",&s.age);
        getchar();

        printf("\nEnter the class: ");
        fflush(stdin);
        fgets(s.class,50,stdin);
        s.class[strlen(s.class)-1]='\0';

        printf("\nEnter the E-mail: ");
        fflush(stdin);
        fgets(s.email,50,stdin);
        s.email[strlen(s.email)-1]='\0';


        fwrite(&s,sizeof(s),1,fp);


        printf("Details modified successfully!");
        printf(" ");
    }

    else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");

    printf("\n\n\t");
    

}