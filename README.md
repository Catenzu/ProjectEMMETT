EMMETT
======
EMMETT is a simple 6502 virtual machine made in C++, named after the best scientist of all time, Emmett Brown.

This project was made as an educational challenge in order to learn Virtual Machines and CPUs.
It is a simple virtual machine of a MOS 6502, made by Benjamin Bourge and Xavier Bailly.

Althought this can be wrong, we made our best to be sure that the instructions are correct.
If you find any mistake, please let us know.

We didn't implement the pins, so the program is not able to communicate with the outside world.
We also didn't implement the interrupts, so the program will run until the end.

We may implement these features in the future, but for now, we are happy with the result.

## How to use
To use this project, just compile it with the CMakeLists.txt file and run the executable.
You can also use the `-h` flag to see the available options.

## Custom instructions

In order to run code on it, we add some custom instructions to the original 6502 instructions set.
Here is the list of the custom instructions:

```
"PRT_IM" -> 0xFC
"PRT_ZERO" -> 0xFB
"PRT_ZEROX" -> 0xFA
"PRT_ABS" -> 0xF2
"PRT_ABSX" -> 0xEF
"PRT_ABSY" -> 0xEB
"PRT_INDX" -> 0xF3
"PRT_INDY" -> 0xF4
"END" -> 0xFF
```

The `PRT` instructions are used to print the value as ASCII in the memory at the address given by the instruction.
The `END` instruction is used to stop the execution of the program, returning the Accumulator value.

## How to write code
The code is written in a txt file, with the following syntax:
```
START <position to start, placed in 0xFFFC and 0xFFFD>
<position> <value>
...
```

We also provide a simple example in the `file.txt` file, used as default when no file is given with -f.

