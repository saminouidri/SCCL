![SCCL](https://imgur.com/3K6NZJN.jpg)
## What is SCCL?
SCCL is a simple UNIX-like command line written in C. It is in NO way meant to replace any existing CLIs or Shell such as BASH.
SCCL is an educational project I undertook to challenge myself in writing a simple CLI using the most basic C syntax.
## Features :
*Basic File manipulation and sysadmin commands builtin with UNIX-Like syntax


*Cross-Platform and portable


*Intuitive and easy-to-use

## Yet to be implemented :
*Networking commands to fetch files and transfer data on the net such as "wget" on bash

*basic text editor to edit files such as "GNU nano" or "vim"

UPDATE: *very* basic text editor implemented as "textedit". 

*Multi-Tasking commands to manage different processes on host system

### Making-Of
SCCL relies heavily on functions mostly found in low-level libraries such as unistd.h and stdio.h making it portable across
most of today's platforms.
#### Initial Start-up
![startup prompt](https://imgur.com/FEAWln5.png)


The program first displays a welcome graphic detailing the CLI's version.Then, the user is prompted
to enter a password which will later be used for the logout feature. the file passwd is created and the password stored inside 
a string and inside passwd with fprintf. we then close it and move on to the prompt.
#### Prompt
we then move on to a while(1){} infinite loop in which we ask for the user's input. we compare the input with the known commands
with strcmp() and execute if it matches. if not we goto PROMPT; .In most CLIs commands have arguments which allow you to specify
what to do with your command. In order to avoid having to deconstruct the user's input into multiple strings without spaces we
ask the user to first input the command (for e.x "cd") and then ask him to input the necessary arguments in seperate scanf()
instances. So the user types :

>root@SCCL # cd

>Enter new directory : mydir

This is to simply the coding process. It is true that simply typing "cd mydir" is faster but for the moment I focused on making
a functional CLI.
### Installing
SCCL is currently readily available on windows as a standalone executable can be found in the debug folder,
however OSX and Linux versions will have to be compiled manually.

## Built With

* [Code::Blocks](http://www.codeblocks.org) - IDE
* [GNU GCC](https://gcc.gnu.org/) - Compiler 


## Contributing

Please read CONTRIBUTING.MD for my rules and things to keep in mind when contributing

## Author(s)
The entire code was written by me (suroxdesigns) and some parts inspired by various resources online.
## License

This project is licensed under the GPLv3

![GNU GPLV3](https://imgur.com/imkUoGR.png)




