#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    if(argc <= 2) {
      printf("usage: %s 'text' file <max count>", argv[0]);
      return 0;
    }

    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    size_t lineNumber = 0;
    ssize_t read;

    char * needle = argv[1];
    char * fileName = argv[2];
    size_t maxCount = argv[3] ? strtol(argv[3],NULL,10) : 1;
    bool isTextFound = false;

    printf("Trying find this text \"%s\" position in file: \"%s\"\n\n", needle, fileName);

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error: file: %s not found", fileName);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        lineNumber++;
        if(strstr(line, needle) != NULL){
            printf("Line #%d: %s", lineNumber, line);
            printf("HEX ADDRESS: %016lx \n\n", ftell(fp));
            isTextFound = true;
            maxCount--;
            if(maxCount == 0){
              fclose(fp);
              exit(EXIT_SUCCESS);
            }
        }
    }
    if(!isTextFound){
      printf("Error: text \"%s\" not found", needle);
    }

    fclose(fp);
    if (line){
      free(line);
    }
    exit(EXIT_SUCCESS);
}

