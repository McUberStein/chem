#include "../libchem.h"
#include "parse.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float handle_element(sstring_t str);


char *strrev(char *str){
  char *p1, *p2;

  if (! str || ! *str)
        return str;
  for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
  }
  return str;
}

sstring_t strncut(sstring_t str, int n){
  sstring_t buff = str;
  buff[strlen(str)-n] = '\0';
  return buff;
}

void strrem(sstring_t str, char removal){
  int i, j;
  int len = strlen(str);
  for(i=0; i<len; i++)
    {
      if(str[i] == removal)
        {
          for(j=i; j<len; j++)
            {
              str[j] = str[j+1];
            }
          len--;
          i--;
        }
    }
}

float handle_bracket(sstring_t str){
 int multiplier, n = 0;
 int size = (strlen(str) > sizeof(str)) ? strlen(str) : sizeof(str);
 sstring_t strbuff = malloc(size);
 sstring_t numbuff = malloc(size);
 float total = 0, M;

 strcpy(strbuff, str);
 strrem(strbuff, '('), strrem(strbuff, ')');
 for(int i = 0; i < size; i++){
   if(str[i] == ')')
     while(isdigit(str[i+1]))
       numbuff[n] = str[i+1], i++, n++;
 }
 strbuff = strncut(strbuff, strlen(numbuff));
 multiplier = (0 >= strlen(numbuff)) ? 1 : atoi(numbuff);
 int p = parse_elements(strbuff, parsebuff);

 for(int i = 0; i < p; i++){
   M = handle_element(parsebuff[i]);
   if(0 > M)
     return -1;
   total += M;
 }

 clearbuff(parsebuff);
 return total * multiplier;
}

float handle_element(sstring_t str){
  if(strlen(str) > 4)
    return -1;
  float ra_mass;
  uint nums;
  int size = (strlen(str) > sizeof(str)) ? strlen(str) : sizeof(str);
  char *strbuff = malloc(size);
  char *numbuff = malloc(size);
  char *el_buff = malloc(sizeof(char) * strlen(str));
  numloc_t *T = numloc(str);
  if(T->count == 0){
    return relative_atomic_mass(str);
  }
  strcpy(strbuff, str);
  strncat(el_buff, str, T->locations[0]-1);
  if(!onlist(el_buff)){
    return -1;
  }
  strncat(numbuff, strrev(strbuff), T->count);
  strcpy(numbuff, strrev(numbuff));
  ra_mass = relative_atomic_mass(el_buff);
  nums = atoi(numbuff);
  return ra_mass * nums;
}
