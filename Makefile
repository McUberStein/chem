CALCFILES = ../calc/molar.c ../calc/relative_atomic.c ../calc/parse.c
ELFILES = ../elements/vars.c ../elements/utils.c

SRCFILES = vars.c utils.c chem.c 
OBJFILES = out/vars.o out/utils.o out/chem.o

PREFIX = /usr/local
LIBDIR = $(PREFIX)/lib
INCLUDE = $(PREFIX)/include
CHEMDIR = $(INCLUDE)/chem

all: chem
chem:
	@-mkdir -p out/{elements,calc} &> /dev/null 
	@-mkdir out/obj
	@cp src/libchem.h out/ && cp src/chem.c out/ 
	@cp src/elements/* out/elements/
	@cp src/calc/* out/calc/
	@cd out/obj && gcc -fPIC ../chem.c $(CALCFILES) $(ELFILES) -c					
	@ld -shared out/obj/* -o libchem.so
	@rm -rf out/*
	@mv libchem.so out/
	@cp -r include/ out/
install: install_headers
	@install -d -m 755 '$(LIBDIR)'
	@install out/libchem.so '$(LIBDIR)'
install_headers: chem
	@mkdir $(CHEMDIR)
	@install -d -m 755 '$(CHEMDIR)'
	@install include/* '$(CHEMDIR)'
clean:
	@rm -rf out

.PHONY = chem
