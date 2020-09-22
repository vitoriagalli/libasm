# LIBASM

![](https://img.shields.io/badge/code-Assembly-red)
![](https://img.shields.io/badge/School-42-black)

## Introduction

The aim of this project is to get familiar with assembly language.

An assembly language is a low-level programming language designed for a specific type of processor. It may be produced by compiling source code from a high-level programming language (such as C/C++) but can also be written from scratch, requiring less memory and execution time, as it was done in this project.

* ASM 64 Bits
* Intel Syntax
* Running on Linux


## Usage

#### Prerequisites

[NASM Compiler](https://www.nasm.us)

#### Build Instructions

```bash
$ git clone https://github.com/vscabell/libasm
$ cd libasm
```
<i>compile libasm.a</i>
```bash
$ make
$ make bonus
```
<i>running main tests</i>
```bash
$ make test
$ ./test
$ make testbonus
$ ./testbonus
```

## Functions

### II. Functions List

#### Mandatory Functions
|  Function | Synopsis  |
| ------------ | ------------ |
| ft_strlen | size_t	ft_strlen(const char *s) |
| ft_strcpy | char	*ft_strcpy(char *dest, const char *src) |
| ft_strcmp | int		ft_strcmp(const char *s1, const char *s2) |
| ft_write | ssize_t	ft_write(int fd, const void *buf, size_t count) |
| ft_read | ssize_t	ft_read(int fd, void *buf, size_t count) |
| ft_strdup | char	*ft_strdup(const char *s) |

#### Bonus Functions
|  Function | Synopsis  |
| ------------ | ------------ |
| ft_atoi_base | int	ft_atoi_base(char *str, char *base) |
| ft_list_push_front | void	ft_list_push_front(t_list **begin_list, void *data) |
| ft_list_size | int	ft_list_size(t_list *begin_list) |
| ft_list_sort | void	ft_list_sort(t_list **begin_list, int (*cmp)()) |
| ft_list_remove_if |void	ft_list_remove_if(t_list **begin_list, void *data_ref,mint (*cmp)(), void (*free_fct)(void *)) |
