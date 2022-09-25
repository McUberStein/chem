#include "libchem.h"
#include "elements/utils.h"
#include "calc/parse.h"


element_t *element_by_sign(elestring_t sign){
      element_t *E;
      for(int i = 0; i < n_of_elements; i++){
            if(strcmp(sign, list[i]) == 0){
                  E = setstruct_int(i+1);
                  return E;
            }
      }
      return NULL;
}

element_t *element_by_name(elestring_t name){
      element_t *E;
      for(int i = 0; i < n_of_elements; i++){
            if(strcmp(name, list_long[i]) == 0){
                  E = setstruct_int(i+1);
                  return E;
            }
      }
      return NULL;
}

element_t *element_by_number(elenum_t atomic){
  element_t *E = setstruct_int(atomic);
  return E;
}

float molar_mass(sstring_t solution){
  int n = parse_elements(solution, parsed_list);
  float M, all = 0;
  for(int i = 0; i < n; i++){
    M = (parsed_list[i][0] == '(') ? handle_bracket(parsed_list[i]) : handle_element(parsed_list[i]);
    if(0 > M){
      all = -10000;
      break;
    }
    all += M;
  }

  return (all <= 0) ? -1 : all;
}


