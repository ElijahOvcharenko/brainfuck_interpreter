# brainfuck_interpreter
Brainfuck interpreter written on C++

### Warning!
This version is built on int array (note: not char) so every cell could be from int_min to int_max respectively.
Max quantity of cells is 3000.

### How to build?
First of all clone or download project.
It's required any c++ compiler to be installed.
g++ example
```
$ g++ main.cpp -o brainfuck_interpreter

```


### How to use?
It takes as a parametr .bf filename or starts in interactive mode without any argument.

```
./brainfuck_interpreter [filename]

```

Example #1 (load code from file): ./brainfuck_interpreter file_name.bf

Example #2 (interactive mode): ./brainfuck_interpreter
                                Enter brainfuck code
         
         
