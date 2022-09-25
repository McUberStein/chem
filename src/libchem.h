#ifndef LIBCHEM_H
#define LIBCHEM_H

#include "elements/types.h"
#include "calc/parse.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

#define NA 6.022 * 10^23
#define VM 22.41


element_t *element_by_name(elestring_t name);
element_t *element_by_sign(elestring_t sign);
element_t *element_by_number(elenum_t atomic);

float molar_mass(char* solution);
float relative_atomic_mass(elestring_t element);

#endif // LIBCHEM_H
