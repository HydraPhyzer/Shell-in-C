<h1 align="center">Shell</h1>

<br>

<h3 align="center">This Project is Part of My Operating System Lab (OS Lab)</h3>

<hr>

### Following Are The Key Points of Project

### 1) <ins>Shell</ins>

A Shell provides you with a CLI (Command Line Interface) interface. It
gathers input from you and executes programs based on that input. When
a program finishes executing, it displays that program's output.
Shell is an environment in which we can run our commands, programs, and
shell scripts. There are different flavors of a shell, just as there are different
flavors of operating systems. Each flavor of shell has its own set of
recognized commands and functions.

### 2) <ins>Working of Shell</ins>

Shell reads your input after you press Enter. It determines the command
you want executed by looking at the first word of your input. A word is an
unbroken set of characters. Spaces and tabs separate words.

### 3) <ins>Examples of Shell</ins>

There are many shells available in different operating systems.
Few of them are given below

* Linux Shell
* Command Prompt
* PowerShell
* The Bourne Sell for Solaris

The Shell that we have implemented is basically a simples shell, which works
very similer to the shell tha we use in th ubuntu operating system
The Shell is named as `Pearl`

### 3.1) <ins>How to Run</ins>

In Order to Run This Project. Just Open Linux Terminal In Same Folder and Type

```c
gcc Shell.c
```
and Press Enter and Type
```c
./a.out
```

### 4) <ins>Basic Layout of `Pearl`</ins>

![Basic Layout](./Project%20Snaps/Screenshot%20from%202022-04-25%2020-18-20.png)

The commands that we have implemented in this shell are given below

* help
* man
* leave
* pwd 
* whoami
* echo
* color
* bgcolor
* crdir
* deldir
* cd
* ls
* ls –all
* ls –tree
* del
* cat
* touch
* copy

<!-- ========================= -->

### 5) <ins>Cat Command</ins>
cat commands is implemented. The working of this command is to read the
content of file and also write the content into the file.

![Cat Command](./Project%20Snaps/cat.png)

```c
    //Read Format
    cat FILENAME.txt
    //Write Format
    cat > FILENAME.txtCat Read
```
### 6) <ins>CD Commands</ins>

CD Commands is Refferred as Change Directory Command , this is use to
move from one directory to another directory. We can move to the parent
directory by command of cd ..

![CD Command](./Project%20Snaps/cd.png)
```c
// Syntax:
 cd New
 cd ..
 cd .
 cd Folder#1
```
### 7) <ins>CRDIR & DELDIR</ins>

These both command are used to create the directory and delete directory.
Borth commands are multi-arguments. We can give one or more than one
argument to this commands. This is helpful in creating and deleting multiple direcroties at a time

![Basic Layout](./Project%20Snaps/crdir.png)
![Basic Layout](./Project%20Snaps/deldir.png)
```c
// Syntax:
crdir Folder#1
crdir Folder#2
deldir Folder#1
deldir Folder#2
```
### 8) <ins>LS Command</ins>

LS commad is used to list all files and folder names in the current directory. This is implemented in three ways

```c
ls
// This is very simple , this only show the folder of files in the current directory

ls –tree

// This command is used to show the all files and folder inside a current folder . this works recursively and check every fil and folder

ls –all

// This command is very similer to the simple ls commands , but provides us with the additional information including the files or folder access rights , size and creation date etc
```

![LS Commands](./Project%20Snaps/ls.png)
![LS Commands](./Project%20Snaps/ls%20-all.png)
![LS Commands](./Project%20Snaps/ls%20-tree.png)

### 9) <ins>Man Command</ins>

Man keyword is short form manual , this command is used to get the deep
information about command.

![Basic Layout](./Project%20Snaps/man.png)

```c
// Syntax:
man wipe
//give manual of wipe command used to clear the screen
man color
//give manual color command
man copy
//give manual of copy commandHelp Command:
```


### 10) <ins>Help Command</ins>

Help command is used to know that which command are supported by this
shell and and detailed preview of the command syntax, which is helpful for new user. Just type `help` in terminal to run this commmand.

![Basic Layout](./Project%20Snaps/help.png)