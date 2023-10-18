
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/wait.h>

char **read_input(int *word_count);
void file_found(char *file, char **command, char **env);
void file_found(char *file, char **command, char **env);
void free_str(char **str, int count);
char *findfile(char *cmd);
char **parseInput(char *str, int *count);
char **parsePath(char *str, int *count);
int count_words(char *str);
int count_wordsp(char *str);
int *count_char(char *str);
int *count_charp(char *str);
char *argToStr(char **strstr);
char *_strcat(char *, char *);
int _countw(char *);
int *countc(char *);
char **parsePath(char *str, int *count);
char **parseInput(char *str, int *count);


#endif
