<p align="center">
	<img src="https://apply.holbertonschool.com/holberton-logo.png">
	<br>
	<img src="https://readme-typing-svg.herokuapp.com?font=Open+Sans&weight=900&pause=1000&color=1D5ABD&center=true&vCenter=true&width=500&lines=LOW+LEVEL+PROGRAMMING+PROJECT+IN+C" alt="Typing SVG" />
</p>

#
# <p align="center">C - Stacks, Queues - LIFO, FIFO</p>

## :bookmark: Table of contents

<details>
        <summary>
		CLICK TO ENLARGE
        </summary>
        :memo: <a href="#objective">Objective</a>
        <br>
	    :page_facing_up: <a href="#description">Description</a>
        <br>
        :hammer: <a href="#tech-stack">Tech stack</a>
        <br>
        :floppy_disk: <a href="#prototype">Prototypes</a>
        <br>
        :clipboard: <a href="#requirements">Requirements</a>
        <br>
        :floppy_disk: <a href="#compilation-command">Compilation command</a>
        <br>
        :mortar_board: <a href="#instructions">Instructions</a>
        <br>
        :bookmark_tabs: <a href="#flowcharts">Flowcharts</a>
        <br>
        :open_file_folder: <a href="#files-description">Files description</a>
        <br>
        :computer: <a href="#install_use">How to install and use the program</a>
		<br>
        :blue_book: <a href="#examples">Examples</a>
        <br>
        :blue_book: <a href="#man-page">MAN page</a>
        <br>
        :heartpulse: <a href="#thanks">Thanks</a>
        <br>
        :construction_worker: <a href="#authors">Authors</a>
</details>

## :memo: <span id="objective">Objective</span>

To write a Monty ByteCodes interpreter.

## :page_facing_up: <span id="description">Description</span>

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

## :hammer: <span id="tech-stack">Tech stack</span>

<div style="display: flex;">
	<img width="45px" height="50px" src="https://upload.wikimedia.org/wikipedia/commons/1/19/C_Logo.png">
    &emsp;
	<img width="50px" height="50px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/a/ab/Logo-ubuntu_cof-orange-hex.svg/1200px-Logo-ubuntu_cof-orange-hex.svg.png">
	&emsp;
	<img wigth="50px" height="50px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/9f/Vimlogo.svg/544px-Vimlogo.svg.png">
    &emsp;
    <img width="45px" height="50px"
src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/9a/Visual_Studio_Code_1.35_icon.svg/2048px-Visual_Studio_Code_1.35_icon.svg.png">
</div>

## :floppy_disk: <span id="prototype">Prototypes</span>

`int main(int argc, char *argv[]);`: main fonction of the Monty ByteCodes interpreter (entry point).

`int exec_instructions(stack_t **stack, char *opcode, unsigned int line_number);`: executes a specific opcode on a stack data structure.

`void free_stack(stack_t *stack);`: frees the memory allocated for the stack.

`int is_digit(char *opcode)`: checks if a string represents an integer.

`void push(stack_t **head, unsigned int line_number);`: pushes an element to the stack.

`void pall(stack_t **stack, unsigned int line_number);`: prints all the values on the stack, starting from the top of the stack.

`void pint(stack_t **stack, unsigned int line_number);`: prints the value at the top of the stack, followed by a new line.

`void pop(stack_t **stack, unsigned int line_number);`: removes the top element of the stack.

`void swap(stack_t **stack, unsigned int line_number);`: swaps the top two elements of the stack.

`void add(stack_t **stack, unsigned int line_number);`: adds the top two elements of the stack.

`void nop(stack_t **stack, unsigned int line_number);`: doesn’t do anything :).

## :clipboard: <span id="requirements">Requirements</span>

- Allowed editors: **vim**, **emacs** or Visual Code Studio.
- All the files will be compiled on **Ubuntu 20.04 LTS** using **gcc**.
- The code should use the **betty style**.
- You allowed to use a maximum of one global variable.
- No more than 5 functions per file.
- You are allowed to use the C standard library.
- The header files should be include guarded.
- You are expected to do the tasks in the order shown in the project.

## :floppy_disk: <span id="compilation-command">Compilation command</a>

`gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

## :mortar_board: <span id="instructions">Instructions</span>

### <span id="mandatory-tasks">Mandatory tasks</span>

<details>
	<summary>
		<b>Task 0. push,pall</b>
	</summary>
	Implement the push and pall opcodes.</li>
	<br><br>
	<b>The push opcode</b>
	<br>
	The opcode push pushes an element to the stack.
	<ul>
		<li>Usage: push "int".</li>
		<ul>
			<li>where "int" is an integer.</li>
		</ul>
		<li>
			if "int" is not an integer or if there is no argument given to push, print the error message L"line_number": usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE.
		</li>
		<ul>
			<li>where is the line number in the file.</li>
		</ul>
		<li>You won’t have to deal with overflows. Use the atoi function.</li>
	</ul>
	<br>
	<b>The pall opcode</b>
	<br>
	The opcode pall prints all the values on the stack, starting from the top of the stack.
	<ul>
		<li>Usage pall.</li>
		<li>Format: see example.</li>
		<li>If the stack is empty, don’t print anything.</li>
	</ul>

```
julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$
```
</details>

<details>
	<summary>
		<b>Task 1. pint</b>
	</summary>
	Implement the pint opcode.
	<br><br>
	<b>The pint opcode</b>
	<br>
	The opcode pint prints the value at the top of the stack, followed by a new line.
	<ul>
		<li>Usage: pint.</li>
		<li>
			If the stack is empty, print the error message L"line_number": can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE.
		</li>
	</ul>

```
julien@ubuntu:~/monty$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/monty$ ./monty bytecodes/06.m 
1
2
3
julien@ubuntu:~/monty$ 
```
</details>

<details>
	<summary>
		<b>Task 2. pop</b>
	</summary>
	Implement the pop opcode.
	<br><br>
	<b>The pop opcode</b>
	<br>
	The opcode pop removes the top element of the stack.
	<ul>
		<li>Usage: pop.</li>
		<li>
			If the stack is empty, print the error message L"line_number": can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE.
		</li>
	</ul>

```
julien@ubuntu:~/monty$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/monty$ ./monty bytecodes/07.m 
3
2
1
2
1
1
julien@ubuntu:~/monty$ 
```
</details>

<details>
	<summary>
		<b>Task 3. swap</b>
	</summary>
	Implement the swap opcode.
	<br><br>
	<b>Implement the swap opcode.</b>
	<br>
	The opcode swap swaps the top two elements of the stack.
	<ul>
		<li>Usage: swap.</li>
		<li>
			If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE.
		</li>
	</ul>

```
julien@ubuntu:~/monty$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/monty$ ./monty bytecodes/09.m 
3
2
1
2
3
1
julien@ubuntu:~/monty$ 
```
</details>

<details>
	<summary>
		<b>Task 4. add</b>
	</summary>
	Implement the add opcode.
	<br><br>
	<b>The add opcode</b>
	<br>
	The opcode add adds the top two elements of the stack.
	<ul>
		<li>Usage: add.</li>
		<li>
			If the stack contains less than two elements, print the error message L"line_number": can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE.
		</li>
		<li>The result is stored in the second top element of the stack, and the top element is removed, so that at the end:</li>
		<ul>
			<li>The top element of the stack contains the result.</li>
			<li>The top element of the stack contains the result.</li>
		</ul>
	</ul>

```
julien@ubuntu:~/monty$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

julien@ubuntu:~/monty$ ./monty bytecodes/12.m 
3
2
1
5
1
julien@ubuntu:~/monty$
```
</details>

<details>
	<summary>
		<b>Task 5. nop</b>
	</summary>
	Implement the nop opcode.
	<br><br>
	<b>The nop opcode</b>
	<br>
	The opcode nop doesn’t do anything.
	<ul>
		<li>Usage: nop.</li>
	</ul>
</details>

### <span id="advanced-tasks">Advanced tasks</a>

## :bookmark_tabs: <span id="flowcharts">Flowcharts</a>

![Image](https://raw.githubusercontent.com/fchavonet/holbertonschool-monty/main/resources/screenshot-flowchart.png)

## :open_file_folder: <span id="files-description">Files description</span>

| FILE                | DESCRIPTION                                                                              |
|:-------------------:|:----------------------------------------------------------------------------------------:|
|      bytecodes      |                                contains example .m files                                 |
|      resources      |                            contains images for README.md file                            |
|      README.md      |                                 this readme file :wink:                                  |
|        add.c        |                                contains the add function                                 |
|     free_stack.c    |                             contains the free_stack function                             |
| exec_instructions.c |                          contains the exec_instructions function                         |
|       main.c        |        contains the main function of the Monty ByteCodes interpreter (entry point)       |
|      man_monty      |                         man page of the Monty ByteCodes interpreter                      |
|       monty.h       |                   includes libraries, structures and function prototypes                 |
|       nop.c         |                                 contains the nop function                                |
|       pall.c        |                                 contains the pall function                               |
|       pint.c        |                                 contains the pint function                               | 
|       pop.c         |                                 contains the pop function                                |
|       push.c        |                         contains the is_digit and push functions                         |
|       swap.c        |                                 contains the swap function                               |

## :computer: <span id="install_use">How to install and use the program</a>

To install and use our Monty ByteCodes interpreter program, follow these steps:

### Install:

1. Clone the repository using the following command:
```
git clone https://github.com/fchavonet/holbertonschool-monty.git
```

2. Compile the program by running the following command:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

### Use the Monty ByteCodes interpreter:

To use the Monty ByteCodes interpreter program, type the following command:
```
./monty "path_of_the_monty_bytecode_file_name.m"
```
<br>
The program will run the bytecodes line by line and stop if either:
<br>
- It executed properly every line of the file.
<br>
- It finds an error in the file.
<br>
- An error occured.

## :computer: <span id="examples">Examples</a>

You will find some examples .m files to test the program in the bytecodes folder:

<details>
	<summary>
		<b>00-mandatory_task0_push&pall.m</b>
	</summary>
	<br>

```
push 1
push 2
push 3
pall
```

<b>Output:</b>

```
$ ./monty bytecodes/00-mandatory_task0_push\&pall.m 
3
2
1
$ 
```
</details>

<details>
	<summary>
		<b>01-mandatory_task1_pint.m</b>
	</summary>
	<br>

```
push 1
pint
push 2
pint
push 3
pint
```

<b>Output:</b>

```
$ ./monty bytecodes/01-mandatory_task1_pint.m.m 
1
2
3
$ 
```
</details>

<details>
	<summary>
		<b>02-mandatory_task2_pop.m</b>
	</summary>
	<br>

```
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
```

<b>Output:</b>

```
$ ./monty bytecodes/02-mandatory_task2_pop.m 
3
2
1
2
1
1
```
</details>

<details>
	<summary>
		<b>03-mandatory_task3_swap.m</b>
	</summary>
	<br>

```
push 1
push 2
push 3
pall
swap
pall
```

<b>Output:</b>

```
$ ./monty bytecodes/03-mandatory_task3_swap.m 
3
2
1
2
3
1
$ 
```
</details>

<details>
	<summary>
		<b>04-mandatory_task4_add.m</b>
	</summary>
	<br>

```
push 1
push 2
push 3
pall
add
pall
```

<b>Output:</b>

```
$ ./monty bytecodes/04-mandatory_task4_add.m 
3
2
1
5
1
$ 
```
</details>

<details>
	<summary>
		<b>05-mandatory_task5_nop.m</b>
	</summary>
	<br>

```
nop
```

<b>Output:</b>

```
$ ./monty bytecodes/04-mandatory_task4_add.m 
$ 
```
</details>

## :blue_book: <span id="man-page">MAN page</a>

Execution: `man_monty`

![Image](https://raw.githubusercontent.com/fchavonet/holbertonschool-monty/main/resources/screenshot-man_page.png)

## :hearts: <span id="thanks">Thanks</span>

A big thank you to all our Holberton School peers for their help and support throughout this project.
<br>

## :construction_worker: <span id="authors">Authors</span>
**Fabien CHAVONET**
- Github: [@fchavonet](https://github.com/fchavonet)

**Jeremy MACAL**
- Github: [@JeremMac](https://github.com/JeremMac)
