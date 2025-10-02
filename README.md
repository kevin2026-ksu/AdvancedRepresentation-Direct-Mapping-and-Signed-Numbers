# CS 3503 Assignment 2 - Data Representation and Mapping

## Author
Kevin Lara

## Description
Advanced data representation functions for Owl Tech’s CPU design team. are printed to the console and can be redirected to `output.txt`.

## What’s New
- Implemented **direct mapping conversions**:
  - `oct_to_bin` → Octal to Binary (3-bit mapping)  
  - `oct_to_hex` → Octal to Hexadecimal (via binary)  
  - `hex_to_bin` → Hexadecimal to Binary (4-bit mapping)  

- Implemented **signed number representations**:
  - `to_sign_magnitude` → Sign-Magnitude representation (32 bits)  
  - `to_ones_complement` → One’s Complement representation (32 bits)  
  - `to_twos_complement` → Two’s Complement representation (32 bits, modern CPU standard)  

- Reused the **test driver from Assignment 1** (`main.c`) with updated parsing logic for the new functions.  

## Build Instructions
To compile and run in a terminal (Windows with MinGW, Linux, or macOS):

```bash
gcc -o convert convert.c main.c
./convert > output.txt
```
## Test Results
49/51
