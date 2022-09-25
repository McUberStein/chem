#include "../libchem.h"
#include "parse.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int parsed_size = 0;
char parsed_list[MAX_ELS][10];
char parsebuff[MAX_ELS][10];

int parse_elements(sstring_t solution, char p_list[MAX_ELS][10]){
    int n = 0, j = 0, i;
    bool bracket = false;

    for(i = 0; 1; i++){

        if(solution[i] == '\0')
            break;

        if(solution[i] == '('){
            n++, j = 0;
            p_list[n][j++] = solution[i];
            bracket = true;
        }
        if(solution[i] == ')'){
            p_list[n][j++] = solution[i];
            bracket = false;
            while(isdigit(solution[i+1])){
                p_list[n][j++] = solution[i+1], i++;
            }
            p_list[n][j++] = '\0';
        }

        if(isupper(solution[i]) || islower(solution[i]) || isdigit(solution[i])){
            p_list[n][j++] = solution[i];
        }
        if(isupper(solution[i+1]) && !bracket){
            p_list[n][j++] = '\0', n++, j = 0;
        }

    }
    parsed_size = n+1;
    return parsed_size;
}

void clearbuff(char buff[MAX_ELS][10]){
    for(int i = 0; i < MAX_ELS; i++)
        buff[i][0] = '\0';
}

bool onlist(sstring_t str){
    int size = n_of_elements; 
    for(int i = 0; i < size; i++){
        if(strcmp(list[i], str) == 0)
            return true;
    }
    return false;
}

bool check_elements(sstring_t solution){
    parse_elements(solution, parsed_list);
    for(int i = 0; i < parsed_size; i++){
        if(!onlist(parsed_list[i]))
            return false;  
    } 
    return true;
}

numloc_t *numloc(sstring_t str){
    static numloc_t __number_location_test_type;
    __number_location_test_type.str = str;
    __number_location_test_type.count = 0;
    int n = 0;

    for(int i = 0; 1; i++){
        if(isdigit(str[i]))
            __number_location_test_type.locations[n] = i+1, __number_location_test_type.count++, n++;

        if(str[i] == '\0')
            break;
    }
    return &__number_location_test_type;
}
