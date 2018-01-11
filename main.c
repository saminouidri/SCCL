#include <stdio.h>
#include <stdlib.h>
//#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <command.h>
#include <fcntl.h>
void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
void shutdown()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("shutdown -h now");
    #endif // defined

    #if defined(_WIN32) || defined(_WIN64)
        system("shutdown /s");
    #endif
}

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    char Host[100]="UNIX-based OS";
    int linux=1;
    #endif // defined

    #if defined(_WIN32) || defined(_WIN64)
    int win32=1;
    char Host[100]="WIN32";
    #endif


void ListDirectory();
void ChangeDirectory(char newdir[100]);



int main()
{
    char parameter[20], password[100];
    char newdir[100], namedir[100];
    char removefile[100];
    char filetbcop[100];
    char filetbcop2[100];
    char filecop[100];
    char newdir2[100];
    char dirdel[100];
    char makefiles[100];
    int out;
    int out2;
    FILE* file = NULL;
    FILE* file2 = NULL;
    static int sh_status = 1 ;
    int act_status;
    int cmd_status;
    char passwdcmp[100];

      FILE* file_create = fopen("passwd", "w");
        fclose(file_create);

        FILE* file2_create = fopen("status", "w");
        fclose(file2_create);

    ABOUT:printf("=================================\n");
    printf("   _____  _____   _____   _      \n");
    printf("  / ____|/ ____| / ____| | |  V 1.0\n");
    printf(" | (___ | |     | |      | |     \n");
    printf(" |____ )| |     | |      | |     \n");
    printf("  ____) | |____ | |____ _| |____ \n");
    printf(" |_____(_)_____(_)_____(_)______|\n");
    printf("=================================\n");
    printf("\n");



      printf("enter a password : ");
        scanf("%s", &password);


    file = fopen("passwd", "r+");
     if (file != NULL)

    {

        // File has been opened

    }

    else

    {

        // error message

        printf("Cannot find passwd\n");

    }
     fprintf(file,"%s",password);
     fclose(file);


    printf("Your password has been saved\n");
    char cmd[2];




    while(1)
    {



        PROMPT:printf("\nroot@SCCL # ");
        fflush(stdout);
        char command[10];
        scanf("%s", &command);
        //fgets(command, 10, stdin);
        //printf("%s", command);
        if (strcmp(command, "ls") == 0)
        {
            ListDirectory();
        }
        else if (strcmp(command,"cd") == 0)
        {
            if (win32==1)
            {
                printf("Path must be specified with double \\ \n");
            }
            printf("Enter a new directory/path : ");
            scanf("%s", &newdir);
            ChangeDirectory(newdir);
        }
        else if (strcmp(command,"mkdir") == 0)
        {
            printf("Enter a name for the new directory : ");
            scanf("%s", &namedir);
            mkdir(namedir);
        }
        else if (strcmp(command, "rm")== 0)
        {
            printf("Enter filename to be deleted : ");
            scanf("%s", &removefile);
            remove(removefile);
        }
        else if (strcmp(command, "cpy")== 0)

        {
            printf("Enter file to be copied : ");
            scanf("%s", &filetbcop);
            printf("nEnter new filename : ");
            scanf("%s", &filecop);
            rename(filetbcop, filecop);
        }
        else if (strcmp(command, "rmdir")==0)
        {
            printf("Enter empty directory to be deleted : ");
            scanf("%s", &dirdel);
            rmdir(dirdel);
        }
        else if (strcmp(command, "clear") == 0)
        {
            clear();
        }
        else if(strcmp(command, "makefile") ==0)
        {
            printf("Enter new filename : ");
            scanf("%s", &makefiles);
            FILE* makefile = fopen(makefiles, "w");
            fclose(makefile);

        }
        else if(strcmp(command, "shutdown")==0)
        {
            shutdown();
        }
        else if(strcmp(command, "time")==0)
        {
            time_t result = time(NULL);
            if(result != -1)
            {
                printf("The current time is %s\n",
               asctime(gmtime(&result)), (uintmax_t)result);
            }

        }
        else if(strcmp(command, "sysinfo")==0)
        {
            printf("%s host", Host);
        }
        else if(strcmp(command, "mv")==0)
        {
            if (win32==1)
            {
                printf("Path must be specified with double \\ \n");
            }
            printf("Enter file to be moved with path : ");
            scanf("%s", &filetbcop);
            printf("\nEnter new path with filename : ");
            scanf("%s", &filecop);
            rename(filetbcop, filecop);
        }
        else if(strcmp(command, "touch")==0)
        {
            char touch[100];
            printf("Enter filename to be created : ");
            scanf("%s", &touch);

            FILE* touchfile = fopen(touch,"w");

            fclose(touch);
        }
        else if(strcmp(command, "exit")==0)
        {
            exit(1);
        }
        else if(strcmp(command, "run")==0)
        {
            printf("Enter program to run : ");
            char program[100];
            scanf("%s", &program);
            if (win32==1)
            {
                system(program);
            }
            else
            {
                strcat("./", program);
                system(program);
            }
        }
        else if(strcmp(command, "help")==0)
        {
            printf("\nWelcome to the help section\n");
            printf("===============================\n");
            printf("1.Show a list of all commands\n");
            printf("2.Show a list of portable commands\n");
            printf("[Tip]Be sure to use the wdtd command for documentation on a specific command\n");
            printf("================================\n");
            int choice;
            scanf("%d", &choice);
            switch(choice)
            {
                case(1):
                printf("ls | cd | mkdir | rmdir | makefile | rm | cpy | mv | touch | time | shutdown | logout | sysinfo | clear | exit | run | help | about");
                break;

                case(2):
                printf("ls | cd | mkdir | rmdir | makefile | rm | cpy | mv | touch | time | logout | sysinfo | exit | help | about");
                break;
            }

        }
        else if(strcmp(command, "wdtd")==0)
        {
            printf("\nEnter the command : ");

            char wdtd[100];
            scanf("%s", &wdtd);
            WhatDo(wdtd);
        }
        else if(strcmp(command, "about")==0)
        {
            printf("== S.C.C.L  version 1.0==\n");
            printf("Published under GPLv3\n");
            printf("Author : Sami Nouidri\n");
            printf("=========================");

        }
        else if(strcmp(command, "logout")==0)
        {
            clear();
            int i=3;
            char lgoutpass[100];
            while(i!=0)
            {
                PASSCHECK:printf("Enter your password : ");
                scanf("%s", &lgoutpass);
                if (strcmp(password, lgoutpass)==0)
                {
                    goto PROMPT;
                }
                else
                {
                    printf("\nwrong password, you have %d more tries\n", i);
                    if (i==1)
                    {
                        exit(1);
                    }
                    i=i-1;

                }
            }


        }


    }




    return 0;
}
