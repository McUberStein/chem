#ifndef PARSE_H
#define PARSE_H

#ifndef _STDBOOL_H
#define bool _Bool
#endif

#define MAX_ELS 20


typedef char* sstring_t;
typedef struct{
  sstring_t str;
  unsigned short count;
  int locations[];
} numloc_t;


extern char parsed_list[MAX_ELS][10];
extern char parsebuff[MAX_ELS][10];
extern int parsed_size;

float handle_element(sstring_t str);
float handle_bracket(sstring_t str);
int parse_elements(sstring_t solution, char p_list[MAX_ELS][10]);
void clearbuff(char buff[MAX_ELS][10]);
bool onlist(sstring_t str);
bool check_elements();
numloc_t *numloc(sstring_t str);

#endif
