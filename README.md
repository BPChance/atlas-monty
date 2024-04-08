
# Monty Interpreter

This is a simple interpreter for the Monty programming language. Monty is a high-level programming language like Python, but it's stack-based. This interpreter reads Monty bytecode files and executes the operations specified in them.


## Usage

```c
./monty <file_name.m> 
```
replace <file_name.m> with the name of your monty bytecode file.

## Examples

```c
example.m

push 1
push 2
push 3
pall
add
pall
```

Output
```c
3
2
1
5
1
```


## Features

- push <int>: Pushes an integer onto the stack.
- pall: Prints all the values on the stack, starting from the top.
- pint: Prints the value at the top of the stack.
- pop: Removes the top element of the stack.
- swap: Swaps the top two elements of the stack.
- add: Adds the top two elements of the stack.
- nop: Does nothing.


## Bugs

- Negative numbers are not handled properly. Currently, if a negative character is encountered, the interpreter may not interpret it correctly. This issue needs to be addressed for proper handling of negative numbers.
## Contributers

- Braden Chance



