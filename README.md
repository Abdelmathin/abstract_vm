# 🧩 Abstract VM

## Overview
Abstract VM is a C++ project that simulates a stack-based virtual machine capable of executing instructions defined in a custom assembly-like language. This project allows you to perform various operations such as arithmetic calculations, data manipulation, and more.

## Features
- **Stack Operations:** Push and pop data from the stack.
- **Arithmetic Operations:** Perform operations like addition, multiplication, and more.
- **Type Handling:** Support for various data types, including `int32`, `float`, and `double`.
- **Assertions:** Validate stack values with assertions.
- **Exit Command:** Gracefully terminate the program execution.

## Example
The following example illustrates how to use the virtual machine:

```assembly
; -------------
; example.avm -
; -------------

push int32(42)
push int32(33)

add

push float(44.55)

mul

push double(42.42)
push int32(42)

dump

pop

assert double(42.42)

exit
```
