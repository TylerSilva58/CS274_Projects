# CS 274 — Systems Programming

Coursework from Oregon State University's CS 274 (Systems Programming), a collection
of small C and C++ programs covering pointers, memory management, data structures,
and low-level I/O.

## Projects

| Project | Description |
| --- | --- |
| [`project1`](project1) | Command-line utilities built around `argv` parsing and math library calls (`mult`, `pi`, `sqrt`, `temp`). |
| [`project-caesar`](project-caesar) | Caesar cipher encoder/decoder for encrypted text files. |
| [`Project 3`](Project%203) | String-processing utility that collapses repeated whitespace. |
| [`starship_database`](starship_database) | Flat-file database for tracking a starship fleet's roster. |
| [`PRN_Calculator`](PRN_Calculator) | Postfix (RPN) calculator backed by a custom stack implementation. |
| [`project6`](project6.cpp) | Standalone C++ program (see `project6.cpp`). |
| [`project7`](project7) | A small virtual CPU and program runner/interpreter. |
| [`Project8`](Project8) | Shape hierarchy in C++ exercising inheritance and polymorphism. |
| [`Challenges`](Challenges) | Weekly in-class challenges and exercises, organized by week. |

## Building

Most projects ship with their own `Makefile`:

```sh
cd <project-directory>
make
```

Compiled binaries and object files are intentionally excluded from version control;
build locally after cloning.
