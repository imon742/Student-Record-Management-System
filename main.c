#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <string.h>

#include<time.h>

#define MAX_YR  9999

#define MIN_YR  1900

#define MAX_SIZE_USER_NAME 30

#define MAX_SIZE_PASSWORD  20

#define FILE_NAME  "studentRecordSystem.bin"

#define MAX_FATHER_NAME 50

#define MAX_STUDENT_NAME 50

#define MAX_STUDENT_ADDRESS 300

#define FILE_HEADER_SIZE  sizeof(sFileHeader)





struct login

{

char name[100];

char username[20];

char password[20];

};



//Used Function

void admission_centre();
void student_centre();
void about_us();
void payment();
void user();
void Add_info();
void show_list();
void teacher_centre();
void add_teacher();
void show_teacher();








void delay(unsigned int mseconds)

{

    clock_t goal = mseconds + clock();

    while (goal > clock());

}



typedef struct

{

    int yyyy;

    int mm;

    int dd;

} Date;

typedef struct

{

    char username[MAX_SIZE_USER_NAME];

    char password[MAX_SIZE_PASSWORD];

} sFileHeader;

typedef struct        						 // to call in program

{

    unsigned int student_id;					 // declare the integer data type

    char fatherName[MAX_FATHER_NAME];			// declare the charecter data type

    char studentName[MAX_STUDENT_NAME];		// declare the character data type

    char studentAddr[MAX_STUDENT_ADDRESS];		// declare the character data type

    Date studentJoiningDate;					// declare the integer data type
} s_StudentInfo;

void printMessageCenter(const char* message)

{

    int len =0;

    int pos = 0;

    len = (78 - strlen(message))/2;

    printf("\t\t\t");

    for(pos =0 ; pos < len ; pos++)

    {



        printf(" ");

    }

    printf("%s",message);

}







void headMessage(const char *message)

{

    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t");

for(int i=0;i<75;i++)



{

 printf("_");

 delay(10);
fflush(stdin);
}


    printf("\n\t\t\t###########################################################################");

    printf("\n\t\t\t############                                                   ############");

    printf("\n\t\t\t############          Student Record Management System         ############");

    printf("\n\t\t\t############                                                   ############");

    printf("\n\t\t\t###########################################################################");

    printf("\n\t\t\t---------------------------------------------------------------------------\n");

    printMessageCenter(message);

    printf("\n\t\t\t----------------------------------------------------------------------------");

}











void welcomeMessage()

{

    headMessage("");

    printf("\n\n\n\n\n");

    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");

    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

    printf("\n\t\t\t        =                  WELCOME                  =");

    printf("\n\t\t\t        =                    TO                     =");

    printf("\n\t\t\t        =               Student Record              =");

    printf("\n\t\t\t        =                 MANAGEMENT                =");

    printf("\n\t\t\t        =                   SYSTEM                  =");

    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

    printf("\n\n\n\t\t\t Enter any key to continue.....");

    getch();

}











registe()

{

FILE *log;

log=fopen("login12.txt", "w");

struct login l;

headMessage("REGISTATION CENTER:");



printf("\n\n\n\t\t\t Enter Full Name : \n\n\t\t\t ");

scanf("%s", l.name);



headMessage("REGISTATION CENTER:");

printf("\n\n\n\t\t\t Enter username: \n\n\t\t\t ");

scanf("%s", l.username);

printf("\n\n\n\t\t\t Enter password: \n\n\t\t\t ");

scanf("%s", l.password);



fwrite(&l,sizeof(l),1,log);



fclose(log);



printf("\n\n\n\t\t\tLogin with user username and password ");

printf(" \n\n\n\t\t\tPress any key to continue.....\n" ) ;

getch();

system ("CLS");

login();

}

login()

{

    char username[200],password[20];

    FILE *log;

    log=fopen("login12.txt","r");

    struct login l;

headMessage("USER LOGIN");

    printf("\n\n\n\t\t\tUser Name: \n\n\t\t\t ");

    scanf("%s",&username);

    printf("\n\n\n\t\t\tPassword: \n\n\t\t\t ");

    scanf("%s",&password);



    while(fread(&l,sizeof(l),1,log))

    {

        if(strcmp(username,l.username)==0 &&strcmp(password, l.password)==0)

        {

            user1();

        }

        else

        {

            printf("\n\n\n\t\t\tPlease Enter correct UserID and Password");



        }



    }

    fclose(log);

}























int isNameValid(const char *name)

{

    int validName = 1;

    int len = 0;

    int index = 0;

    len = strlen(name);

    for(index =0; index <len ; ++index)

    {

        if(!(isalpha(name[index])) && (name[index] != '\n') && (name[index] != ' '))

        {

            validName = 0;

            break;

        }

    }

    return validName;

}







int  IsLeapYear(int year)

{

    return (((year % 4 == 0) &&

             (year % 100 != 0)) ||

            (year % 400 == 0));

}







int isValidDate(Date *validDate)

{

    if (validDate->yyyy > MAX_YR ||

            validDate->yyyy < MIN_YR)

        return 0;

    if (validDate->mm < 1 || validDate->mm > 12)

        return 0;

    if (validDate->dd < 1 || validDate->dd > 31)

        return 0;

    if (validDate->mm == 2)

    {

        if (IsLeapYear(validDate->yyyy))

            return (validDate->dd <= 29);

        else

            return (validDate->dd <= 28);

    }



    if (validDate->mm == 4 || validDate->mm == 6 ||

            validDate->mm == 9 || validDate->mm == 11)

        return (validDate->dd <= 30);

    return 1;

}





void addStudentInDataBase()

{

    s_StudentInfo addStudentInfoInDataBase = {0};

    FILE *fp = NULL;

    int status = 0;

    fp = fopen(FILE_NAME,"ab+");

    if(fp == NULL)

    {

        printf("File is not opened\n");

        exit(1);

    }

    headMessage("ADD NEW Students");

    printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");

    printf("\n\t\t\t---------------------------------------------------------------------------\n");

    printf("\n\t\t\tStudent ID  = ");

    fflush(stdin);

    scanf("%u",&addStudentInfoInDataBase.student_id);

    do

    {

        printf("\n\t\t\tFather Name  = ");

        fflush(stdin);

        fgets(addStudentInfoInDataBase.fatherName,MAX_FATHER_NAME,stdin);

        status = isNameValid(addStudentInfoInDataBase.fatherName);

        if (!status)

        {

            printf("\n\t\t\tName contain invalid character. Please enter again.");

        }

    }

    while(!status);

    do

    {

        printf("\n\t\t\tStudent Name  = ");

        fflush(stdin);

        fgets(addStudentInfoInDataBase.studentName,MAX_STUDENT_NAME,stdin);

        status = isNameValid(addStudentInfoInDataBase.studentName);

        if (!status)

        {

            printf("\n\t\t\tName contain invalid character. Please enter again.");

        }

    }

    while(!status);

    do

    {

        printf("\n\t\t\tStudent Address  = ");

        fflush(stdin);

        fgets(addStudentInfoInDataBase.studentAddr,MAX_FATHER_NAME,stdin);

        status = isNameValid(addStudentInfoInDataBase.studentAddr);

        if (!status)

        {

            printf("\n\t\t\tName contain invalid character. Please enter again.");

        }

    }

    while(!status);

    do

    {



        printf("\n\t\t\tEnter date in format (day/month/year): ");

        scanf("%d/%d/%d",&addStudentInfoInDataBase.studentJoiningDate.dd,&addStudentInfoInDataBase.studentJoiningDate.mm,&addStudentInfoInDataBase.studentJoiningDate.yyyy);

        status = isValidDate(&addStudentInfoInDataBase.studentJoiningDate);

        if (!status)

        {

            printf("\n\t\t\tPlease enter a valid date.\n");

        }

    }

    while(!status);

    fwrite(&addStudentInfoInDataBase,sizeof(addStudentInfoInDataBase), 1, fp);



fclose(fp);

}





// search student

void searchStudent()

{

    int found = 0;

    int studentId =0;

    s_StudentInfo addStudentInfoInDataBase = {0};

    FILE *fp = NULL;

    fp = fopen(FILE_NAME,"rb");

    if(fp == NULL)

    {

        printf("\n\t\t\tFile is not opened\n");

        exit(1);

    }

    headMessage("SEARCH STUDENTS");

    //put the control on student detail

    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)

    {

        fclose(fp);

        printf("\n\t\t\tFacing issue while reading file\n");

        exit(1);

    }

    printf("\n\n\t\t\tEnter Student ID NO to search:");

    fflush(stdin);

    scanf("%u",&studentId);

    while (fread (&addStudentInfoInDataBase, sizeof(addStudentInfoInDataBase), 1, fp))

    {

        if(addStudentInfoInDataBase.student_id == studentId)

        {

            found = 1;

            break;

        }

    }

    if(found)

    {

        printf("\n\t\t\tStudent id = %d\n",addStudentInfoInDataBase.student_id);

        printf("\n\t\t\tStudent name = %s",addStudentInfoInDataBase.studentName);

        printf("\t\t\tFather Name = %s",addStudentInfoInDataBase.fatherName);

        printf("\n\t\t\tStudent Address = %s",addStudentInfoInDataBase.studentAddr);

        printf("\t\t\tStudent Admission Date(day/month/year) =  (%d/%d/%d)",addStudentInfoInDataBase.studentJoiningDate.dd,

               addStudentInfoInDataBase.studentJoiningDate.mm, addStudentInfoInDataBase.studentJoiningDate.yyyy);

    }

    else

    {

        printf("\n\t\t\tNo Record");

    }

    fclose(fp);

    printf("\n\n\n\t\t\tPress any key to go to main menu.....");

    fflush(stdin);

    getchar();

}



void viewStudent()

{

    int found = 0;

    s_StudentInfo addStudentInfoInDataBase = {0};

    FILE *fp = NULL;

    unsigned int countStudent = 1;

    headMessage("VIEW STUDENT DETAILS");

    fp = fopen(FILE_NAME,"rb");

    if(fp == NULL)

    {

        printf("File is not opened\n");

        exit(1);

    }

    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)

    {

        fclose(fp);

        printf("Facing issue while reading file\n");

        exit(1);

    }

    while (fread (&addStudentInfoInDataBase, sizeof(addStudentInfoInDataBase), 1, fp))

    {

        printf("\n\t\t\tStudent Count = %d\n\n",countStudent);

        printf("\t\t\tStudent id = %u\n",addStudentInfoInDataBase.student_id);

        printf("\t\t\tStudent Name = %s",addStudentInfoInDataBase.studentName);

        printf("\t\t\tFather Name = %s",addStudentInfoInDataBase.fatherName);

        printf("\t\t\tStudent Address = %s",addStudentInfoInDataBase.studentAddr);

        printf("\t\t\tStudent Admission Date(day/month/year) =  (%d/%d/%d)\n\n",addStudentInfoInDataBase.studentJoiningDate.dd,

               addStudentInfoInDataBase.studentJoiningDate.mm, addStudentInfoInDataBase.studentJoiningDate.yyyy);



        found = 1;

        ++countStudent;

    }

    fclose(fp);

    if(!found)

    {

        printf("\n\t\t\tNo Record");

    }

    printf("\n\n\t\t\tPress any key to go to main menu.....");

    fflush(stdin);

    getchar();

}

// Delete student entry

void deleteStudent()

{

    int found = 0;

    int studentDelete = 0;

    sFileHeader fileHeaderInfo = {0};

    s_StudentInfo addStudentInfoInDataBase = {0};

    FILE *fp = NULL;

    FILE *tmpFp = NULL;

    headMessage("Delete Student Details");

    fp = fopen(FILE_NAME,"rb");

    if(fp == NULL)

    {

        printf("File is not opened\n");

        exit(1);

    }

    tmpFp = fopen("tmp.bin","wb");

    if(tmpFp == NULL)

    {

        fclose(fp);

        printf("File is not opened\n");

        exit(1);

    }

    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);

    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, tmpFp);

    printf("\n\t\t\tEnter Student ID NO. for delete:");

    scanf("%d",&studentDelete);

    while (fread (&addStudentInfoInDataBase, sizeof(addStudentInfoInDataBase), 1, fp))

    {

        if(addStudentInfoInDataBase.student_id != studentDelete)

        {

            fwrite(&addStudentInfoInDataBase,sizeof(addStudentInfoInDataBase), 1, tmpFp);

        }

        else

        {

            found = 1;

        }

    }

    (found)? printf("\n\t\t\tRecord deleted successfully....."):printf("\n\t\t\tRecord not found");

    fclose(fp);

    fclose(tmpFp);

    remove(FILE_NAME);

    rename("tmp.bin",FILE_NAME);

}

void updateCredential(void)

{

    sFileHeader fileHeaderInfo = {0};

    FILE *fp = NULL;

    unsigned char userName[MAX_SIZE_USER_NAME] = {0};

    unsigned char password[MAX_SIZE_PASSWORD] = {0};

    headMessage("Update Credential");

    fp = fopen(FILE_NAME,"rb+");

    if(fp == NULL)

    {

        printf("File is not opened\n");

        exit(1);

    }

    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);

    if (fseek(fp,0,SEEK_SET) != 0)

    {

        fclose(fp);

        printf("\n\t\t\tFacing issue while updating password\n");

        exit(1);

    }

    printf("\n\n\t\t\tNew Username:");

    fflush(stdin);

    fgets(userName,MAX_SIZE_USER_NAME,stdin);

    printf("\n\n\t\t\tNew Password:");

    fflush(stdin);

    fgets(password,MAX_SIZE_PASSWORD,stdin);

    strncpy(fileHeaderInfo.username,userName,sizeof(userName));

    strncpy(fileHeaderInfo.password,password,sizeof(password));

    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);

    fclose(fp);

    printf("\n\t\t\tYour Password has been changed successfully");

    printf("\n\t\t\ttLogin Again:");

    fflush(stdin);

    getchar();

    exit(1);

}







































//Display admin_pannel

void admin_pannel()

{

    int choice = 0;

    do

    {

        headMessage("ADMIN PANEL OF THE PROJECT:");

        printf("\n\n\n\t\t\t1. Admission centre");

        printf("\n\t\t\t2. Student centre");
         printf("\n\t\t\t3. Teacher centre ");

        printf("\n\t\t\t4. Search");

        printf("\n\t\t\t5. About us");

      printf("\n\t\t\t6. Change password");

        printf("\n\t\t\t7. Back");
         printf("\n\t\t\t8. EXIT");

        printf("\n\n\n\t\t\tEnter choice => ");

        scanf("%d",&choice);

        switch(choice)

        {

        case 1:

            admission_centre();

            break;

        case 2:

student_centre();

            break;
case 3:

teacher_centre();

            break;


        case 4:

            searchStudent();

            break;

        case 5:

            about_us2();

            break;

        case 6:

            updateCredential();

            break;
       case 7:



      ui();
            break;

        case 8:

            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");

            exit(1);

            break;

        default:

            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");

        }

    }

    while(choice!=0);                                        //

}







void menu1()

{

    int choice = 0;

    do

    {

        headMessage("MAIN MENU");

        printf("\n\n\n\t\t\t1.Add Student");

        printf("\n\t\t\t2.Search Student");

        printf("\n\t\t\t3.View Student");

        printf("\n\t\t\t4.Delete Student");

        printf("\n\t\t\t5.Update Password");

        printf("\n\t\t\t0.Exit");

        printf("\n\n\n\t\t\tEnter choice => ");

        scanf("%d",&choice);

        switch(choice)

        {

        case 1:

            addStudentInDataBase();

            break;

        case 2:

            searchStudent();

            break;

        case 3:

            viewStudent();

            break;

        case 4:

            deleteStudent();

            break;

        case 5:

            updateCredential();

            break;

        case 0:

            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");

            exit(1);

            break;

        default:

            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");

        }

    }

    while(choice!=0);

}













void ui()

{

     headMessage("User Interface");

    printf("\n\n\n\t\t\t1. USER LOGIN ");

printf("\n\n\n\t\t\t2. ADMIN LOGIN");

printf("\n\n\n\t\t\t3. Exit");


printf("\n\n\n\n\t\t\t****************************************************************************\n");

int ch;

printf("\n\n\n\t\t\t ->  Enter your Choice:\n\n\n\t\t\t");

scanf("%d", &ch);

printf("\n\n\t>>Welcome to admin pannel\n \t \n*****************************************\n");

switch(ch)

{

case 1:

user();

break;

case 2:

adminlogin();

break;

case 3:



printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");

            exit(1);

            break;



printf("\n\n\n\t\t\t Enter any key to continue.....");

    getch();



            break;

default:

printf("Wrong Input\n");

}



}

















//Admin login password



void adminlogin()

{
    fflush(stdin);
    unsigned char userName[MAX_SIZE_USER_NAME] = {0};

    unsigned char password[MAX_SIZE_PASSWORD] = {0};

    int L=0;

    sFileHeader fileHeaderInfo = {0};

    FILE *fp = NULL;

    headMessage("Admin Login");

    fp = fopen(FILE_NAME,"rb");

    if(fp == NULL)

    {

        printf("File is not opened\n");

        exit(1);

    }

    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);

    fclose(fp);

    do

    {

        printf("\n\n\n\t\t\t\tUsername:");

        fgets(userName,MAX_SIZE_USER_NAME,stdin);

        printf("\n\t\t\t\tPassword:");

        fgets(password,MAX_SIZE_PASSWORD,stdin);

        if((!strcmp(userName,fileHeaderInfo.username)) && (!strcmp(password,fileHeaderInfo.password)))

        {

            admin_pannel ();

        }

        else

        {

            printf("\t\t\t\tLogin Failed Enter Again Username & Password\n\n");

            L++;

        }

    }

    while(L<=3);

    if(L>3)

    {

        headMessage("Login Failed");

        printf("\t\t\t\tSorry,Unknown User.");

        getch();

        system("cls");

    }

}

int isFileExists(const char *path)

{

    FILE *fp = fopen(path, "rb");

    int status = 0;

    if (fp != NULL)

    {

        status = 1;

        // File exists hence close file

        fclose(fp);

    }

    return status;

}

void init()

{

    FILE *fp = NULL;

    int status = 0;

    const char defaultUsername[] ="team 7\n";

    const char defaultPassword[] ="123\n";

    sFileHeader fileHeaderInfo = {0};

    status = isFileExists(FILE_NAME);

    if(!status)

    {

        //create the binary file

        fp = fopen(FILE_NAME,"wb");

        if(fp != NULL)

        {

            //Copy default password

            strncpy(fileHeaderInfo.password,defaultPassword,sizeof(defaultPassword));

            strncpy(fileHeaderInfo.username,defaultUsername,sizeof(defaultUsername));

            fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);

            fclose(fp);

        }

    }

}




// For add teacher

void add_teacher()
{

    fflush(stdin);
    system("cls");
    char name[20],sub[10];
    FILE *ptr;
    ptr=fopen("teacher.txt","a");
headMessage("ADD TEACHER INFO");
printf("\n\n\t\t\tENTER DETAILS BELOW:");

    printf("\n\t\t\t---------------------------------------------------------------------------\n");

    printf("\n\t\t\tEnter Name  = ");
    scanf("%s",name);
    printf("\n\t\t\tEnter subject = ");
    fprintf(ptr,"%s ",name);
    scanf("%s",sub);
    fprintf(ptr,"%s\n",sub);
    printf("\n\n\n\t\t\tSucessfully Added\n");
printf("\n\n\n\t\t\t Enter any key to continue.....");

    getch();

    fclose(ptr);
}





void show_teacher(){
    fflush(stdin);
    system("cls");
    char name[20],sub[10];
    FILE *ptr;
    ptr=fopen("teacher.txt","r");
    while (fscanf(ptr,"%s %s",name,sub)!=EOF)
    {
        printf("\n\t\t\t Teacher Name  = %s\n\t\t\t Subjec  = %s\n",name,sub);
    }
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();

    fclose(ptr);

}







void admission_centre()

{

    int choice = 0;

    do

    {

        headMessage("Admission Centre:");

        printf("\n\n\n\t\t\t1. New Admission");

        printf("\n\t\t\t2. Show information uploaded by user ");

        printf("\n\t\t\t3. Admission cancellation ");

       printf("\n\t\t\t4. Back ");
        printf("\n\t\t\t5. EXIT ");





        printf("\n\n\n\t\t\tEnter choice => ");

        scanf("%d",&choice);

        switch(choice)

        {

        case 1:

            addStudentInDataBase();

            break;

        case 2:

            show_list();

            break;

        case 3:

            deleteStudent();

            break;

case 4:



admin_pannel();
            break;

        case 5:

            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");

            exit(1);

            break;

        default:

            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");

        }

    }

    while(choice!=0);

}

















void student_centre()

{

    int choice = 0;

    do

    {

        headMessage("STUDENT CENTRE:");

        printf("\n\n\n\t\t\t1. Student Record ");
        printf("\n\t\t\t2. Teacher List ");

        printf("\n\t\t\t3. Payment ");

       printf("\n\t\t\t6. Back ");
       printf("\n\t\t\t4. EXIT ");





        printf("\n\n\n\t\t\tEnter choice => ");

        scanf("%d",&choice);

        switch(choice)

        {

        case 1:

            viewStudent();

            break;

        case 2:

            show_teacher();
            break;
case 3:

            payment();

            break;






case 6:



admin_pannel();
            break;

        case 4:

            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");

            exit(1);

            break;

        default:

            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");

        }

    }

    while(choice!=0);

}



void teacher_centre()

{

    int choice = 0;

    do

    {

        headMessage("TEACHER CENTRE:");

        printf("\n\n\n\t\t\t1. Add New Teacher");

        printf("\n\t\t\t2. Teacher Name and Subject List");

       printf("\n\t\t\t3. Back ");
        printf("\n\t\t\t4. EXIT ");






        printf("\n\n\n\t\t\tEnter choice => ");

        scanf("%d",&choice);

        switch(choice)

        {

        case 1:

             add_teacher();



            break;

        case 2:

            show_teacher();

            break;





        case 3:


            admin_pannel();

            break;
        case 4:


            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");

            exit(1);

            break;


                default:

            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");

        }

    }

    while(choice!=0);

}

void about_us()

{

    int choice = 0;

    do

    {

        headMessage("ABOUT US:");

        printf("\n\n\n\t\t\t1. History ");

        printf("\n\t\t\t2. Contract Infotmation");

       printf("\n\t\t\t3. Back ");
        printf("\n\t\t\t4. EXIT ");






        printf("\n\n\n\t\t\tEnter choice => ");

        scanf("%d",&choice);

        switch(choice)

        {

        case 1:

             headMessage("HISTORY:");

            printf("\n\n\n Bangladesh University of Business and Technology (BUBT) was established under the Private University Act in the year 2003 modelled on North American Universities, with the approval of the University Grants Commission (UGC) and the Ministry of Education, Government of Bangladesh.\n It was founded by Dhaka Commerce College, Mirpur- 2, Dhaka, and is managed by a Board of Trustees and a Syndicate. BUBT is one of the leading universities in the private sector of Bangladesh. It has been providing quality education and training since its very inception. \nAt present BUBT has established itself as a top ranking Private University in the country, not only by fulfilling all of the requirements of the Private University Act, 2010, but also by maintaining the standard of education, research facilities, transparent examination system, updated academic programs, necessary physical infrastructures, co-curricular and extra-curricular activities, modern facilities for the students and a disciplined environment.\n\n");

printf("\n\n\n\t\t\t Enter any key to continue.....");

    getch();



            break;

        case 2:

            headMessage("CONTRACT INFORMATION:");

printf("\n\n\n\t\t\t Nazmul Islam Imon (19202103240)\n");

printf("\n\t\t\t SM Raziur Rahman Pushon (19202103214)\n");

printf("\n\t\t\t Nushrat Jahan Liza (19202103235)\n");



printf("\n\n\n\t\t\t  Contact Number:\n");



printf("\n\t\t\t  Nazmul Islam Imon ( 01717-202172)\n");

printf("\n\t\t\t  SM Raziur Rahman Pushon (01737-059309)\n");

printf("\n\t\t\t  Nushrat Jahan Liza (01769-555883)\n");

printf("\n\n\n\t\t\t Enter any key to continue.....");

    getch();



            break;





        case 3:


            user1();

            break;
        case 4:


            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");

            exit(1);

            break;


        default:

            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");

        }

    }

    while(choice!=0);

}




void about_us2()

{

    int choice = 0;

    do

    {

        headMessage("ABOUT US:");

        printf("\n\n\n\t\t\t1. History ");

        printf("\n\t\t\t2. Contract Infotmation");

       printf("\n\t\t\t3. Back ");
        printf("\n\t\t\t4. EXIT ");






        printf("\n\n\n\t\t\tEnter choice => ");

        scanf("%d",&choice);

        switch(choice)

        {

        case 1:

             headMessage("HISTORY:");

            printf("\n\n\n Bangladesh University of Business and Technology (BUBT) was established under the Private University Act in the year 2003 modelled on North American Universities, with the approval of the University Grants Commission (UGC) and the Ministry of Education, Government of Bangladesh.\n It was founded by Dhaka Commerce College, Mirpur- 2, Dhaka, and is managed by a Board of Trustees and a Syndicate. BUBT is one of the leading universities in the private sector of Bangladesh. It has been providing quality education and training since its very inception. \nAt present BUBT has established itself as a top ranking Private University in the country, not only by fulfilling all of the requirements of the Private University Act, 2010, but also by maintaining the standard of education, research facilities, transparent examination system, updated academic programs, necessary physical infrastructures, co-curricular and extra-curricular activities, modern facilities for the students and a disciplined environment.\n\n");

printf("\n\n\n\t\t\t Enter any key to continue.....");

    getch();



            break;

        case 2:

            headMessage("CONTRACT INFORMATION:");

printf("\n\n\n\t\t\t Nazmul Islam Imon (19202103240)\n");

printf("\n\t\t\t SM Raziur Rahman Pushon (19202103214)\n");

printf("\n\t\t\t Nushrat Jahan Liza (19202103235)\n");



printf("\n\n\n\t\t\t  Contact Number:\n");



printf("\n\t\t\t  Nazmul Islam Imon ( 01717-202172)\n");

printf("\n\t\t\t  SM Raziur Rahman Pushon (01737-059309)\n");

printf("\n\t\t\t  Nushrat Jahan Liza (01769-555883)\n");

printf("\n\n\n\t\t\t Enter any key to continue.....");

    getch();



            break;





        case 3:


            admin_pannel();

            break;
        case 4:


            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");

            exit(1);

            break;


        default:

            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");

        }

    }

    while(choice!=0);

}








void payment()

{

    int choice = 0;

    do

    {

        headMessage("PAYMENT:");

        printf("\n\n\n\t\t\t1. Bkash ");

        printf("\n\t\t\t2. Rocket ");

       printf("\n\t\t\t3. Nogod ");

       printf("\n\t\t\t4. Bank ");

       printf("\n\t\t\t5. Back ");

       printf("\n\t\t\t6. EXIT ");







        printf("\n\n\n\t\t\tEnter choice => ");

        scanf("%d",&choice);

        switch(choice)

        {

        case 1:
headMessage("BKASH PAYMENT:");

            printf("\n\n\n\t\t\t Send the amount in THIS Bkash 0171111111");

printf("\n\n\n\t\t\t Enter any key to continue.....");

    getch();



            break;

        case 2:
headMessage("ROCKET PAYMENT:");
            printf("\n\n\n\t\t\t Send the amount in THIS Rocket 0171111111");

printf("\n\n\n\t\t\t Enter any key to continue.....");

    getch();

            break;

case 3:
headMessage("NOGOD PAYMENT:");

            printf("\n\n\n\t\t\t Send the amount in THIS Nogod 0171111111");

printf("\n\n\n\t\t\t Enter any key to continue.....");

    getch();

            break;

case 4:
headMessage("BANK PAYMENT:");
            printf("\n\n\n\t\t\t Send the amount inTHIS Bank acc XXX-XXX-XXXXX");

printf("\n\n\n\t\t\t Enter any key to continue.....");

    getch();

            break;



case 5:



student_centre();
            break;



        case 6:

            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");

            exit(1);

            break;

        default:

            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");

        }

    }

    while(choice!=0);

}





//user section section

void Add_info()
{
    headMessage("UPLOAD YOUR INFORMATION");
char name[30];
FILE *fptr;
int class;

float shift, section;
fptr = fopen("emp.txt", "w+");
if (fptr == NULL)
{
printf("File does not exists \n");
return;
}
printf("\n\t\t\tEnter the class\n\t\t\t");
scanf("%d", &class);
fprintf(fptr, "\n\t\t\tclass= %d\n\t\t\t", class);
printf("\n\t\t\tEnter the name \n\t\t\t");
scanf("%s", name);
fprintf(fptr, "\n\t\t\tName= %s\n\t\t\t", name);
printf("\n\t\t\tEnter the Shift\n\t\t\t");
scanf("%f", &shift);
fprintf(fptr, "\n\t\t\tShift= %.2f\n\t\t\t", shift);
printf("\n\t\t\tEnter the Section\n\t\t\t");
scanf("%f", &section);
fprintf(fptr, "\n\t\t\tSection= %.2f\n\t\t\t", section);
fclose(fptr);

FILE *fp;
char buff[255];
fp = fopen("emp.txt", "r");
headMessage("CONFIRM INFORMATION");
while(fscanf(fp, "%s", buff)!=EOF){

printf("\n\t\t\t%s \n", buff);

}
printf("\n\n\n\t\t\t Press Enter to *CONFIRM*.....");
getch();
fclose(fp);

}


void show_list()
{
    headMessage("USER UPLODED INFORMATION");
FILE *fp;
char buff[255];
fp = fopen("emp.txt", "r");
while(fscanf(fp, "%s", buff)!=EOF){
printf("\n\t\t\t%s \n", buff);
}
printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
fclose(fp);
}











void user()

{

    int choice = 0;

    do

    {

        headMessage("USER PANNEL:");

        printf("\n\n\n\t\t\t1. Register ");

        printf("\n\t\t\t2. Login ");

       printf("\n\t\t\t3. Back ");
       printf("\n\t\t\t4. EXIT ");








        printf("\n\n\n\t\t\tEnter choice => ");

        scanf("%d",&choice);

        switch(choice)

        {

                case 1:



        system("CLS");

        registe();

            break;

        case 2:

            system("CLS");

        login();

            break;

        case 3:



ui();
            break;
case 4:

            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");

            exit(1);

            break;


        default:

            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");

        }

    }

    while(choice!=0);

}































void user1()

{

    int choice = 0;

    do

    {

        headMessage("USER PANNEL:");

        printf("\n\n\n\t\t\t1. Send information to Admin");

        printf("\n\t\t\t2. View Admitted Student ");
        printf("\n\t\t\t3. Teacher List ");

       printf("\n\t\t\t4. Search ");

       printf("\n\t\t\t5. History ");

       printf("\n\t\t\t6. Back ");
       printf("\n\t\t\t7. EXIT ");








        printf("\n\n\n\t\t\tEnter choice => ");

        scanf("%d",&choice);

        switch(choice)

        {

                case 1:

            Add_info();

            break;

        case 2:

         viewStudent();
            break;
        case 3:

         show_teacher();
            break;


        case 4:

            searchStudent();

            break;

        case 5:

            about_us();

            break;

        case 6:


            user();

            break;
        case 7:

            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");

            exit(1);

            break;


        default:

            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");

        }

    }

    while(choice!=0);

}



int main()

{
void addStudentInDataBase();


    init();

    welcomeMessage();

ui();

    adminlogin();

    return 0;

}
