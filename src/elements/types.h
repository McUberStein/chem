#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>

typedef enum{H = 1, He, Li, Be, B, C, N, O, F, Ne, Na, Mg, Al, Si, P, S, Cl, Ar, K, Ca, Sc, Ti, V, Cr, Mn, Fe, Co, Ni, Cu, Zn, Ga, Ge, As, Se, Br, Kr, Rb, Sr, Y, Zr, Nb, Mo, Tc, Ru, Rh, Pd, Ag, Cd, In, Sn, Sb, Te, I, Xe, Cs, Ba, La, Ce, Pr, Nd, Pm, Sm, Eu, Gd, Tb, Dy, Ho, Er, Tm, Yb, Lu, Hf, Ta, W, Re, Os, Ir, Pt, Au, Hg, Tl, Pb, Bi, Po, At, Rn, Fr, Ra, Ac, Th, Pa, U, Np, Pu, Am, Cm, Bk, Cf, Es, Fm, Md, No, Lr, Rf, Db, Sg, Bh, Hs, Mt, Ds, Rg, Cn, Nh, Fl, Mc, Lv, Ts, Og, ERR = 4000} elenium_t;
typedef enum{solid = 1, gas, liquid, unknown} elestate_t;
typedef unsigned short elenum_t;
typedef const char* elestring_t;
typedef struct{
    elestring_t name;
    elestring_t sign;
    float mass;
    elenum_t group, period;
    elenum_t atomic;
    elestate_t stp_state;
    bool radioactive;
} element_t;
extern elestring_t list[];
extern elestring_t list_long[];
extern int n_of_elements;

#endif
