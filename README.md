# shell v2

The project, shell_v2 is a project of the first trimester in Holberton school system programming specialization, that project is a second part of the original shell build in foundations, the goal is build a program as similar as possible to the unix shell using the programming language C.

This project was built by Alejandro López and Hugo Bayona.

# Table of Contents
1. [Authors](#Authors)
2. [How Use](#How-Use)
3. .[explanation](#Explanation)

# Authors

 👤 **Alejandro López**

- Twitter: [@alejolo311](https://twitter.com/alejolo311)
- Github: [@alejolo311](https://github.com/alejolo311)

👤 **Hugo Bayona**

- Twitter: [@BatmanEsFriki](https://twitter.com/BatmanEsFriki)
- Github: [@hb4y](https://github.com/hb4y)


# How Use

## How to compile

### Requirements

- All your files will be compiled on Ubuntu 14.04 LTS
- Make
- Your C programs and functions will be compiled with gcc 4.8.4
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

### How to compile

`$ git clone https://github.com/alejolo311/shell_v2.git`
`$ cd shell_v2`
`$ make`

## Explanation


## Non interactive

pass the commands in the stdin but no prints the prompt.

`$ echo "ls" | ./hsh`

## interactive

the program is execute and the prompt is print, and wait for the user.

`$ ./hsh`
`($)`
`($) ls > output_file`
`($) cat output_file`
