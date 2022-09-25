# Chem
A small, non-scientific C library for providing various chemistry-centered functions

# Compilation
To compile the library, run `make` in the directory with the Makefile. An 'out' directory will be made with the libchem.so inside of it.

# Installation
To install, run `make install` with root privileges. This will install the .so to `/usr/local/lib/` and the headers to `/usr/local/include/chem/`

# Usage
## Chem types:  
* elenum_t, defined as `typedef unsigned short elenum_t`  
* elestate_t, defined as `typedef enum {solid = 1, gas, liquid, unknown} elestate_t`  
* elenium_t, defined as `typedef enum{`ALL 118 element signs`, ERR = 4000} elenium_t`  
* elestring_t, defined as `typedef const char* elestring_t`  
* element_t, defined as `typedef struct{  
                            elestring_t name, sign;
                            float mass;
                            elenum_t group, period, atomic;
                            elestate_t stp_state;
                            bool radioactive;
                            } element_t`
## Global chem variables:  
* `extern elestring_t list[]` = A list of all element signs  
* `extern elestring_t list_long[]` = A list of all element names  
* `extern int n_of_elements` = The number of elements in list  

## Chem functions:  
* `element_t *element_by_name(elestring_t name)` = Searches for element in list_long[], returns an element_t struct pointer if found, else returns NULL  
* `element_t *element_by_sign(elestring_t sign)` = Searches for element in list[], return same as `element_by_name`  
