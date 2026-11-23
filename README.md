# CS 274 — Systems Programming

Coursework from Oregon State University's CS 274 (Systems Programming), a collection
of small C and C++ programs covering pointers, memory management, data structures,
and low-level I/O.

## Projects

| Project | Description |
| --- | --- |
| [`project1`](project1) | Command-line utilities built around `argv` parsing and math library calls (`mult`, `pi`, `sqrt`, `temp`). |
| [`project-caesar`](project-caesar) | Caesar cipher encoder/decoder for encrypted text files. |
| [`project3`](project3) | String-processing utility that collapses repeated whitespace. |
| [`starship-database`](starship-database) | Flat-file database for tracking a starship fleet's roster. |
| [`prn-calculator`](prn-calculator) | Postfix (RPN) calculator backed by a custom stack implementation. |
| [`project6`](project6) | Word-count utility reading from stdin or files. |
| [`project7`](project7) | A small virtual CPU and program runner/interpreter. |
| [`project8`](project8) | Shape hierarchy in C++ exercising inheritance and polymorphism. |
| [`Challenges`](Challenges) | Weekly in-class challenges and exercises, organized by week. |

## Building

Most projects ship with their own `Makefile`:

```sh
cd <project-directory>
make
```

Compiled binaries and object files are intentionally excluded from version control;
build locally after cloning.
