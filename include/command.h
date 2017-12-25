#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED


/*
Author :
Date Published :
License :
Description :
*/

void ListDirectory()
{
    DIR *dir;
    struct dirent *sd;
    dir = opendir(".");
    if (dir == NULL)
    {
        printf("Unable to read current directory\n");
        exit(1);
    }


        while( (sd=readdir(dir)) != NULL )
        {
            printf(".. %s\n", sd->d_name);
        }

    closedir(dir);
}

void ChangeDirectory(char newdir[100])
{

    chdir(newdir);

}

int WhatDo(char command[100])
{
    if (strcmp(command, "ls") == 0)
        {
            printf("\n[ls] List all files/directories in current active path");
        }
        else if (strcmp(command,"cd") == 0)
        {
            printf("\n[cd] changes current active directory to one specified by the user");
        }
        else if (strcmp(command,"mkdir") == 0)
        {
            printf("\n[mkdir] creates a directory in current active directory");
        }
        else if (strcmp(command, "rm")== 0)
        {
            printf("\n[rm] removes a specified file from current active directory");
        }
        else if (strcmp(command, "cpy")== 0)

        {
            printf("\n[cpy] creates a copy of a file specified by the user");
        }
        else if (strcmp(command, "rmdir")==0)
        {
            printf("\n[rmdir] removes a directory specified by the user");
        }
        else if (strcmp(command, "clear") == 0)
        {
            printf("\n[clear] clears the screen of all output ![Not portable]");
        }
        else if(strcmp(command, "makefile") ==0)
        {
            printf("\n[makefile] creates a file in current active directory");
        }
        else if(strcmp(command, "shutdown")==0)
        {
            printf("\n[shutdown] sets current machine state to power-off ![Not portable]");
        }
        else if(strcmp(command, "time")==0)
        {
            printf("\n[time] Outputs current system time and date");
        }
        else if(strcmp(command, "mv")==0)
        {
            printf("\n[mv] moves a file from one specified path to another. Path must be full and double \ in WIN32 systems");
        }
        else if(strcmp(command, "exit")==0)
        {
            printf("\n[exit] Terminates current session");
        }
        else if(strcmp(command, "run")==0)
        {
            printf("\n[run] runs a program specified by the user ![Not portable]");
        }
        else if(strcmp(command, "logout")==0)
        {
             printf("\n[logout] logs you out of your current session with 3 chances at entering your password");
        }
        else if(strcmp(command, "about")==0)
        {
            printf("\n[about] displays info about S.C.C.L including version number.");
        }

}

#endif // COMMAND_H_INCLUDED
