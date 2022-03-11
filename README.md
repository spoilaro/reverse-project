# Reverse Tool

## General
This tool can be used to reverse the order of the lines.</br>
For instance:
```
Hello
World
This is me
```
Transforms into:
```
This is me
World
Hello
```
## Build
Running `make` will build executable called `reverse`

## Usage
Reverse tool can be used in three ways.

### __Without arguments:__
```
$ ./reverse
```
This will ask user to enter lines that will be printed in reversed order after ending the entering process.

### __Input file as an argument:__
```
$ ./reverse <input>
```

### __Input and output file as argument:__
```
$ ./reverse <input> <output>
```