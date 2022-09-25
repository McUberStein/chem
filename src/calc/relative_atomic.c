#include "../libchem.h"
#include <string.h>

float relative_atomic_mass(elestring_t element){
  int len = strlen(element);
  element_t *_rel_atom_mass;
  _rel_atom_mass = (len>2 ? element_by_name(element) : element_by_sign(element));
  if(_rel_atom_mass != NULL)
    return _rel_atom_mass->mass;
  return -1;
}
