#pragma once
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_substr(const char* s, const char* p);

char** search_file(const char *p_dir_name, const char* key_word, int *file_num);
