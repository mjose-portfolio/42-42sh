# 42sh

This project consists of creating a complete shell and uses the work done on your 21sh. A minimum set of functionalities is asked, from which your will build your own finalized shell, potentially going as far as job control and shell script. This project will involve a large variety of standard UNIX (and POSIX) functionalities.

## 1. Project Partners

- [Abraham Gimbao](https://github.com/abguimba)
- [Alexandre Somville](https://github.com/alsomvil42)
- [Brendan Siche](https://github.com/BrendanSiche)
- [Marc Jose](https://github.com/mjose-portfolio)

## 2. Install
------

- `make`

![alt text](README_resources/make.gif)

### 2.1. Make Options

- `make`: Compiles the files and creates the executable 42sh
- `make clean`: Remove binary files.
- `make fclean`: Deletes the binary files and the 42sh executable file.
- `make re`: Deletes the binary files and the 42sh executable file and recompiles them.

## 3. Features
------
### 3.1 Builtins

- [3.1.1 alias](./builtins#311-alias)
- [3.1.2 bg](./builtins#312-bg)
- [3.1.3 cd](./builtins#313-cd)
- [3.1.4 echo](./builtins#314-echo)
- [3.1.5 env](./builtins#315-env)
- [3.1.6 exit](./builtins#316-exit--n-)
- [3.1.7 export](./builtins#317-export)
- [3.1.8 false](./builtins#318-false)
- [3.1.9 fg](./builtins#319-fg)
- [3.1.10 hash](./builtins#3110-hash)
- [3.1.11 history](./builtins#3111-history)
- [3.1.12 jobs](./builtins#3112-jobs)
- [3.1.13 set](./builtins#3113-set)
- [3.1.14 test](./builtins#3114-test)
- [3.1.15 true](./builtins#3115-true)
- [3.1.16 type](./builtins#3116-type)
- [3.1.17 unalias](./builtins#3117-unalias)
- [3.1.18 unset](./builtins#3118-unset)

### 3.2 Prompt

The prompt is displayed as follows:

- `["user"]<"current directory">42sh $/>`

The current directory is updated live, each time you change directory, of course, the information is collected from the environment variable `PWD`.

### 3.3 Execution of Commands

The command shall be searched for using the PATH environment variable.

It is possible to specify the paths where the command to execute resides (in case you want to execute a command that does not reside in any directory of the PATH variable, or the variable is not defined).

The parameters of each command are taken into account.

### 3.4 Redirections

- [3.4.1 Redirecting Input](./redirections#341-redirecting-input)
- [3.4.2 Redirecting Output](./redirections#342-redirecting-output)
- [3.4.3 Here-Document](./redirections#343-here-document)
- [3.4.4 Duplicating an Input File Descriptor](./redirections#344-duplicating-an-input-file-descriptor)
- [3.4.5 Duplicating an Output File Descriptor](./redirections#345-duplicating-an-output-file-descriptor)

### 3.5 Pipelines

The format for a pipeline is:

```
command1 [ | command2 ...]
```

The standard output of `command1` shall be connected to the standard input of `command2`. The standard input, standard output, or both of a command shall be considered to be assigned by the pipeline before any redirection specified by redirection operators that are part of the command.

### 3.6 `;` Operand

it is possible to separate commands using the operand `;`.

```
command1 ; command2 ...
```

### 3.7 Management Of Internal Variables

- Creation of internal variables according to the syntax:

```
name=value
```

- Export of internal variables to the environment, via built-in [export](./builtins#317-export).
- List the internal variables of the shell via the built-in [set]((./builtins#3113-set)).
- Removal of internal and environmental variables, via the built-in [unset](./builtins#3118-unset).
- Creation of environment variables for a single command, example :

```
HOME=/tmp cd
```

- Simple expansion of parameters according to the syntax:

```
${name}
$name
```

- Management of special parameters:

```
$: PID of the current process.
?: Last command exit code.
0: Shell name.
!: PID of the last process launched in backround.
_: Last parameter used in a command.
```