#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ID;

struct patient
{
    char name[25];
    char doadmit[25];
    int id;
    int contact;
    char desease[25];
    char doctor[25];
};

struct patient p;
//--------------------------------------normal functions-------------------------
void cover();
void welcome();
void loginPage();
void mainmenu();
//--------------------------------------menu functions-------------------------
void addpatient();
void searchpatient();
void updpatient();
void patientlist();
void dltpatient();
void ex();

int generateID();

int main()
{
    system("cls");
    cover();
    getch();
    system("cls");
    welcome();
    loginPage();
    printf("\n\n\n\n\n\n\n\n\n\n");
    return 0;
}
void cover()
{
    printf("\n\n\t\t\t\t\t\t\tPROJECT NAME:\n");
    printf("\n\n\t\t\t\t\t\t  PATIENT MANAGEMENT SYSTEM  \n");
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\tTeam members:  \n");
    printf("\n\n\t\t\t\t\t     1. Mobinul Islam Tanim (0112230487)");
    printf("\n\n\t\t\t\t\t     2. Zareen Bushra (0112230248)");
    printf("\n\n\t\t\t\t\t     3. Nowshin Nawar  (0112230331)");

    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
}

void welcome()
{
    printf("------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t   MANAGEMENT SYSTEM\n");
    printf("------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\n\t\t\t\t\tWelcome to our Patient management system\n");
    getch();
}

void loginPage()
{
    int i=0;
    char username[25];
    char pass[25];
    char conusername[25]="abc";
    char conpass[25]="abc";
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\tConfirm your identity to access our data!\n");

a:
    printf("\n\n\t\t\t\t\tUsername: ");
    gets(username);
    printf("\t\t\t\t\tPassword: ");
    gets(pass);
    if(strcmp(username,conusername)==0 && strcmp(conpass,pass)==0)
    {
        printf("\n\n\n\n\t\t\t\t\tLogin Successful");
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
        getch();
    }
    else
    {
        printf("\n\n\t\t\t\t\tSORRY, Username or Password is incorrect");
        printf("\n\n\t\t\t\t\tPlease try again(%d choice left)",2-i);
        i++;
        if(i>2)
        {
            printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
            getch();
            main();
        }
        else
            goto a;
    }
    mainmenu();
    return;
}

void mainmenu()
{
b:
    system("cls");
    printf("------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t   MAIN-MENU\n");
    printf("------------------------------------------------------------------------------------------------------------------------");

    printf("\n\n\n\n\t\t\t\t\t  1. Add Patient details\n");
    printf("\n\t\t\t\t\t  2. Search Patient details\n");
    printf("\n\t\t\t\t\t  3. update Patient details\n");
    printf("\n\t\t\t\t\t  4. List of remaining Patients\n");
    printf("\n\t\t\t\t\t  5. Delete Patient details\n");
    printf("\n\t\t\t\t\t  6. Exit\n");

    printf("\n\n\n\t\t\tChoose your option and enter  [ Only digits ] between (1-6):");
    char choice;
    scanf(" %c",&choice);
    switch(choice)
    {
    case '1':
        addpatient();
        break;
    case '2':
        searchpatient();
        break;
    case '3':
        updpatient();
        break;
    case '4':
        patientlist(p);
        break;
    case '5':
        dltpatient();
        break;
    case '6':
        ex();
        break;
    default:
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\tInvalid choice. Try again ...");
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
        getch();
        goto b;
    }
}

void addpatient()
{
    system("cls");
    printf("------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t   ADD PATIENT DETAILS\n");
    printf("------------------------------------------------------------------------------------------------------------------------");

    printf("\n\n\n\n\n");
    printf("\t\t\tNote: use Underscore(_) instead of white space( )\n\n");
    printf("\t\t\tPatient name : ");
    scanf("%s",p.name);
    p.name[0]=toupper(p.name[0]);
    printf("\t\t\tPatients Admitted Date(dd/mm/yyyy) : ");
    getchar();
    scanf("%s",p.doadmit);
    printf("\t\t\tPatients contact : +880");
    scanf("%d",&p.contact);
    printf("\t\t\tDisease : ");
    scanf("%s",p.desease);
    p.desease[0]=toupper(p.desease[0]);
    printf("\t\t\tAppointed Doctor : ");
    scanf("%s",p.doctor);
    p.doctor[0]=toupper(p.doctor[0]);

    p.id=generateID();
    printf("\n\n\t\t\t\t\t\tPatient ID = %d\n",p.id);
    printf("\n\n\t\t\t\t\tRequested to remember your Patient ID");

    FILE *fptr;
    fptr=fopen("Patientlist.txt","a");

    fprintf(fptr,"%d %s %s %d %s %s\n",p.id,p.name,p.doadmit,p.contact,p.desease,p.doctor);

    printf("\n\n\n\n\n\n\n\n\t\t\t\t\tInformation Stored Successfully");
    fclose(fptr);
    getch();
    char c2;

    printf("\n\n\t\t\t\tDo you want to add more patient details (Y/N):");
c:
    {
        scanf(" %c",&c2);
    }
    switch(toupper(c2))
    {
    case 'N':
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue Main_Menu...");
        getch();
        mainmenu();
        break;
    case 'Y':
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
        getch();
        addpatient();
        break;
    default:
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\tEnter Y or N :");
        goto c;
    }
}

void searchpatient()
{
    system("cls");
    printf("------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t   SEARCH INFO\n");
    printf("------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\n\n\n");
    printf("\t\t\tNote: use Underscore(_) instead of white space( )\n\n");
    char ch;
    printf("\n\t\t\t\t\t\t1. Search by ID\n");
    printf("\n\t\t\t\t\t\t2. Search by Name\n");
    printf("\n\t\t\t\t\t    Enter your choice(1/2): ");
    scanf(" %c",&ch);
    int pat_id,flag=0;
    char pat_name[25];
    switch(ch)
    {
    case '1':
        printf("\n\n\n\t\t\t\t\tEnter patient id : ");
        scanf("%d",&pat_id);
        FILE *r;
        r=fopen("Patientlist.txt","r");

        while(fscanf(r,"%d %s %s %d %s %s\n",&p.id,p.name,p.doadmit,&p.contact,p.desease,p.doctor)!=EOF)
        {

            if(p.id==pat_id)
            {
                flag++;
                printf("\n\n\n\t\t\t\t\tPatient ID: %d\n\n\t\t\t\t\tPatient Name: %s\n\n\t\t\t\t\tAppointed Date: %s\n\n\t\t\t\t\tContact Info: +880%d\n\n\t\t\t\t\tMedical Term: %s\n\n\t\t\t\t\tAppointed Doctor: %s\n",p.id,p.name,p.doadmit,p.contact,p.desease,p.doctor);
            }
        }
        fclose(r);
        break;
    case '2':
        printf("\n\n\n\t\t\t\t\tEnter patient name: ");
        scanf("%s",&pat_name);
        pat_name[0]=toupper(pat_name[0]);

        r=fopen("Patientlist.txt","r");

        while(fscanf(r,"%d %s %s %d %s %s\n",&p.id,p.name,p.doadmit,&p.contact,p.desease,p.doctor)!=EOF)
        {
            if(strcmp(p.name,pat_name)==0)
            {
                flag++;
                printf("\n\n\n\t\t\t\t\tPatient ID: %d\n\n\t\t\t\t\tPatient Name: %s\n\n\t\t\t\t\tAppointed Date: %s\n\n\t\t\t\t\tContact Info: +880%d\n\n\t\t\t\t\tMedical Term: %s\n\n\t\t\t\t\tAppointed Doctor: %s\n",p.id,p.name,p.doadmit,p.contact,p.desease,p.doctor);
            }
        }
        fclose(r);
        break;
    }
    if(flag==0)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t     SORRY...........The data is not Here  :(\n");
        printf("\n\n\t\t\t\t     Please Enter The Correct Name or ID\n");
        getch();
        searchpatient();
    }
    else
    {
d:
        printf("\n\n\n\t\t\t\tSearch Another Patient?? (Y/N): ");
        char ch;
        scanf(" %c",&ch);
        ch=toupper(ch);
        switch(ch)
        {
        case 'N':

            printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue Main Menu...");
            getch();
            mainmenu();
            break;
        case 'Y':
            printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
            getch();
            searchpatient();
            break;

        default:
            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\t\t\tEnter Y or N :");
            goto d;
        }
    }
}

void updpatient()
{
    system("cls");
    printf("------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t   UPDATE DETAILS\n");
    printf("------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\n\n\n");
    printf("\t\t\tNote: use Underscore(_) instead of white space( )\n\n");
    printf("\n\n\n\t\t\t\t\tEnter Patient id:");
    int pat_id;
    scanf("%d",&pat_id);
    char name[25],doadmit[25],desease[25],doctor[25];
    int contact;

    printf("\n\n\n\t\t\t\t\t\tUPDATE INFORMATION");
    printf("\n\t\to-------------------------------------------------------------------------------------------------o");
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("Patientlist.txt","r");
    fp2=fopen("copylist.txt","a");
    int flag=0;

    while(fscanf(fp1,"%d %s %s %d %s %s\n",&p.id,p.name,p.doadmit,&p.contact,p.desease,p.doctor)!=EOF)
    {
        if(p.id!=pat_id)
        {
            fprintf(fp2,"%d %s %s %d %s %s\n",p.id,p.name,p.doadmit,p.contact,p.desease,p.doctor);
        }
        else
        {
            printf("\n\n\n\t\t\t\t\tEnter patient Name: ");
            scanf(" %s",name);
            name[0]=toupper(name[0]);
            printf("\n\t\t\t\t\tDate of Admit: ");
            scanf(" %s",doadmit);
            printf("\n\t\t\t\t\tEnter Contact Information: +880");
            scanf("%d",&contact);
            printf("\n\t\t\t\t\tDesease: ");
            scanf(" %s",desease);
            desease[0]=toupper(desease[0]);

            printf("\n\t\t\t\t\tAppointed Doctor: ");
            scanf(" %s",doctor);
            doctor[0]=toupper(doctor[0]);
            fprintf(fp2,"%d %s %s %d %s %s\n",p.id,name,doadmit,p.contact,desease,doctor);
            flag++;
        }
    }
    fclose(fp1);
    fclose(fp2);

    remove("Patientlist.txt");
    rename("copylist.txt","Patientlist.txt");
    if(flag==0)
    {
        printf("\n\n\n\n\t\t\t\t\tDid not match with this id");
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPress any key to try again...");
        getch();
        updpatient();
    }

    else
    {
        printf("\n\n\n\n\n\t\t\t\t\tInformation Updated successfully\n\n");
k:
        printf("\n\n\n\t\t\t\t\tUpdate Another Patient info?(y/n): ");
        char ch;
        scanf(" %c",&ch);
        ch=toupper(ch);
        switch(ch)
        {
        case 'N':
            printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPress any key to check Patient list");
            getch();
            patientlist();
            break;
        case 'Y':
            printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
            getch();
            updpatient();
            break;

        default:
            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\t\t\tEnter Y or N Stupid:");
            goto k;
        }
    }
}

void patientlist()
{

    system("cls");
    printf("------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t   PATIENT LIST\n");
    printf("------------------------------------------------------------------------------------------------------------------------");

    FILE *r;
    r=fopen("Patientlist.txt","r");
    printf("\n\n\t\tID\tNAME\tDATE-OF-ADMIT\tCONTACT-INFO\tMEDICAL_TERM\tDOCTOR\n");
    printf("------------------------------------------------------------------------------------------------------------------------");

    while(fscanf(r,"%d %s %s %d %s %s\n",&p.id,p.name,p.doadmit,&p.contact,p.desease,p.doctor)!=EOF)
    {

        printf("\n\n\t%d\t%s\t%s\t+880%d\t\t%s\t\t%s\n",p.id,p.name,p.doadmit,p.contact,p.desease,p.doctor);
    }
    fclose(r);
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue Main Menu...");
    getch();
    mainmenu();
}

void dltpatient()
{
    system("cls");
    printf("------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t   DELLETE INFO\n");
    printf("------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\n\n\n");
    printf("\t\t\tNote: use Underscore(_) instead of white space( )\n\n");
    printf("\n\n\n\t\t\t\t\tEnter patient id:");
    int pat_id;
    scanf("%d",&pat_id);
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("Patientlist.txt","r");
    fp2=fopen("copylist.txt","w");

    while(fscanf(fp1,"%d %s %s %d %s %s\n",&p.id,p.name,p.doadmit,&p.contact,p.desease,p.doctor)!=EOF)
    {
        if(p.id!=pat_id)
        {
            fprintf(fp2,"%d %s %s %d %s %s\n",p.id,p.name,p.doadmit,p.contact,p.desease,p.doctor);
        }
    }
    fclose(fp1);
    fclose(fp2);

    remove("Patientlist.txt");
    rename("copylist.txt","Patientlist.txt");

    printf("\n\n\n\n\n\t\t\t\t\tInformation Deleted successfully\n\n");
k:
    printf("\n\n\n\t\t\t\t\tDelete Again(Y/N): ");
    char ch;
    scanf(" %c",&ch);
    ch=toupper(ch);
    switch(ch)
    {
    case 'N':
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPress any key to check Patient list");
        getch();
        patientlist();
        break;
    case 'Y':
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
        getch();
        dltpatient();
        break;

    default:
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\tEnter Y or N Stupid:");
        goto k;
    }
}
void ex()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\tThanks for Visiting Our management System");
    return ;
}

int generateID()
{
    int id;
    FILE *r;
    r=fopen("id.text","r");
    fscanf(r,"%d",&ID);
    fclose(r);
    id=ID;
    ID++;
    r=fopen("id.text","w");
    fprintf(r,"%d",ID);
    fclose(r);

    return id;
}
