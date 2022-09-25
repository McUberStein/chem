#include "../libchem.h"
#include "utils.h"
#include <stdlib.h>


#define SOL E.stp_state = solid
#define GAS E.stp_state = gas
#define LIQ E.stp_state = liquid
#define UNK E.stp_state = unknown
#define RAD E.radioactive = true


elenium_t stoen(elestring_t str, elestring_t strarr[]){
      for(int c = 0; c < n_of_elements; c++){
            if(strcmp(str, strarr[c]) == 0){
                  int out = c+1;
                  return (elenium_t)out;
            }
      }
      return ERR;
}

elestring_t entos(elenium_t sign, elestring_t strarr[]){
      int n = (int)sign-1;
      return strarr[n];
}

element_t *setstruct_int(int num){
  static element_t E;

  E.radioactive = false;
  E.stp_state = solid;
  E.atomic = num;
  E.name = list_long[num-1];
  E.sign = entos((elenium_t)num, list);

  switch(num){
  case H:
      E.mass = 1.008;
      E.group = 1;
      E.period = 1;
      break;

    case He:
      E.mass = 4.00;
      E.group = 18;
      E.period = 1;
      break;

    case Li:
      E.mass = 4;
      E.group = 2;
      E.period = 1;
      break;

    case Be:
      E.mass = 9.012;
      E.group = 2;
      E.period = 2;
      break;

    case B:
      E.mass = 10.81;
      E.group = 13;
      E.period = 2;
      break;

    case C:
      E.mass = 12.011;
      E.group = 14;
      E.period = 2;
      break;

    case N:
      E.mass = 14.007;
      E.group = 15;
      E.period = 2;
      GAS;
      break;

    case O:
      E.mass = 15.999;
      E.group = 16;
      E.period = 2;
      GAS;
      break;

    case F:
      E.mass = 18.998;
      E.group = 17;
      E.period = 2;
      GAS;
      break;

    case Ne:
      E.mass = 20.180;
      E.group = 18;
      E.period = 2;
      GAS;
      break;

    case Na:
      E.mass = 22.990;
      E.group = 1;
      E.period = 3;
      break;

    case Mg:
      E.mass = 24.306;
      E.group = 2;
      E.period = 3;
      break;

    case Al:
      E.mass = 26.982;
      E.group = 13;
      E.period = 3;
      break;

    case Si:
      E.mass = 28.085;
      E.group = 14;
      E.period = 3;
      break;

    case P:
      E.mass = 30.974;
      E.group = 15;
      E.period = 3;
      break;

    case S:
      E.mass = 32.06;
      E.group = 16;
      E.period = 3;
      break;

    case Cl:
      E.mass = 35.45;
      E.group = 17;
      E.period = 3;
      GAS;
      break;

    case Ar:
      E.mass = 39.948;
      E.group = 18;
      E.period = 3;
      GAS;
      break;

    case K:
      E.mass = 39.098;
      E.group = 1;
      E.period = 4;
      break;

    case Ca:
      E.mass = 40.078;
      E.group = 2;
      E.period = 4;
      break;

    case Sc:
      E.mass = 44.956;
      E.group = 3;
      E.period = 4;
      break;

    case Ti:
      E.mass = 47.867;
      E.group = 4;
      E.period = 4;
      break;

    case V:
      E.mass = 50.942;
      E.group = 5;
      E.period = 4;
      break;

    case Cr:
      E.mass = 51.996;
      E.group = 6;
      E.period = 4;
      break;

    case Mn:
      E.mass = 54.938;
      E.group = 7;
      E.period = 4;
      break;

    case Fe:
      E.mass = 55.845;
      E.group = 8;
      E.period = 4;
      break;

    case Co:
      E.mass = 58.933;
      E.group = 9;
      E.period = 4;
      break;

    case Ni:
      E.mass = 58.693;
      E.group = 10;
      E.period = 4;
      break;

    case Cu:
      E.mass = 63.546;
      E.group = 11;
      E.period = 4;
      break;

    case Zn:
      E.mass = 65.38;
      E.group = 12;
      E.period = 4;
      break;

    case Ga:
      E.mass = 69.723;
      E.group = 13;
      E.period = 4;
      break;

    case Ge:
      E.mass = 72.630;
      E.group = 14;
      E.period = 4;
      break;

    case As:
      E.mass = 74.922;
      E.group = 15;
      E.period = 4;
      break;

    case Se:
      E.mass = 78.971;
      E.group = 16;
      E.period = 4;
      break;

    case Br:
      E.mass = 79.904;
      E.group = 17;
      E.period = 4;
      LIQ;
      break;

    case Kr:
      E.mass = 83.798;
      E.group = 18;
      E.period = 4;
      GAS;
      break;

    case Rb:
      E.mass = 85.468;
      E.group = 1;
      E.period = 5;
      break;

    case Sr:
      E.mass = 87.62;
      E.group = 2;
      E.period = 5;
      break;

    case Y:
      E.mass = 88.906;
      E.group = 3;
      E.period = 5;
      break;

    case Zr:
      E.mass = 91.224;
      E.group = 4;
      E.period = 5;
      break;

    case Nb:
      E.mass = 92.906;
      E.group = 5;
      E.period = 5;
      break;

    case Mo:
      E.mass = 95.95;
      E.group = 6;
      E.period = 5;
      break;

    case Tc:
      E.mass = 98;
      E.group = 7;
      E.period = 5;
      RAD;
      break;

    case Ru:
      E.mass = 101.07;
      E.group = 8;
      E.period = 5;
      break;

    case Rh:
      E.mass = 102.91;
      E.group = 9;
      E.period = 5;
      break;

    case Pd:
      E.mass = 106.42;
      E.group = 10;
      E.period = 5;
      break;

    case Ag:
      E.mass = 107.87;
      E.group = 11;
      E.period = 5;
      break;

    case Cd:
      E.mass = 112.41;
      E.group = 12;
      E.period = 5;
      break;

    case In:
      E.mass = 114.82;
      E.group = 13;
      E.period = 5;
      break;

    case Sn:
      E.mass = 118.71;
      E.group = 14;
      E.period = 5;
      break;

    case Sb:
      E.mass = 121.76;
      E.group = 15;
      E.period = 5;
      break;

    case Te:
      E.mass = 127.60;
      E.group = 16;
      E.period = 5;
      break;

    case I:
      E.mass = 126.90;
      E.group = 17;
      E.period = 5;
      break;

    case Xe:
      E.mass = 131.29;
      E.group = 18;
      E.period = 5;
      GAS;
      break;

    case Cs:
      E.mass = 132.91;
      E.group = 1;
      E.period = 6;
      break;

    case Ba:
      E.mass = 137.33;
      E.group = 2;
      E.period = 6;
      break;

    case La:
      E.mass = 138.91;
      E.group = 3;
      E.period = 6;
      break;

    case Ce:
      E.mass = 140.12;
      E.group = 3;
      E.period = 6;
      break;

    case Pr:
      E.mass = 140.91;
      E.group = 3;
      E.period = 6;
      break;

    case Nd:
      E.mass = 144.24;
      E.group = 3;
      E.period = 6;
      break;

    case Pm:
      E.mass = 145;
      E.group = 3;
      E.period = 6;
      break;

    case Sm:
      E.mass = 150.36;
      E.group = 3;
      E.period = 6;
      break;

    case Eu:
      E.mass = 151.96;
      E.group = 3;
      E.period = 6;
      break;

    case Gd:
      E.mass = 157.25;
      E.group = 3;
      E.period = 6;
      break;

    case Tb:
      E.mass = 158.93;
      E.group = 3;
      E.period = 6;
      break;

    case Dy:
      E.mass = 162.50;
      E.group = 3;
      E.period = 6;
      break;

    case Ho:
      E.mass = 164.93;
      E.group = 3;
      E.period = 6;
      break;

    case Er:
      E.mass = 167.26;
      E.group = 3;
      E.period = 6;
      break;

    case Tm:
      E.mass = 168.93;
      E.group = 3;
      E.period = 6;
      break;

    case Yb:
      E.mass = 173.05;
      E.group = 3;
      E.period = 6;
      break;

    case Lu:
      E.mass = 174.97;
      E.group = 3;
      E.period = 6;
      break;

    case Hf:
      E.mass = 178.49;
      E.group = 4;
      E.period = 6;
      break;

    case Ta:
      E.mass = 180.95;
      E.group = 5;
      E.period = 6;
      break;

    case W:
      E.mass = 183.84;
      E.group = 6;
      E.period = 6;
      break;

    case Re:
      E.mass = 186.21;
      E.group = 7;
      E.period = 6;
      break;

    case Os:
      E.mass = 190.23;
      E.group = 8;
      E.period = 6;
      break;

    case Ir:
      E.mass = 192.22;
      E.group = 9;
      E.period = 6;
      break;

    case Pt:
      E.mass = 195.08;
      E.group = 10;
      E.period = 6;
      break;

    case Au:
      E.mass = 196.97;
      E.group = 11;
      E.period = 6;
      break;

    case Hg:
      E.mass = 200.59;
      E.group = 12;
      E.period = 6;
      LIQ;
      break;

    case Tl:
      E.mass = 204.38;
      E.group = 13;
      E.period = 6;
      break;

    case Pb:
      E.mass = 207.2;
      E.group = 14;
      E.period = 6;
      break;

    case Bi:
      E.mass = 208.98;
      E.group = 15;
      E.period = 6;
      break;

    case Po:
      E.mass = 209;
      E.group = 16;
      E.period = 6;
      RAD;
      break;

    case At:
      E.mass = 210;
      E.group = 17;
      E.period = 6;
      RAD;
      break;

    case Rn:
      E.mass = 222;
      E.group = 18;
      E.period = 6;
      RAD;
      GAS;
      break;

    case Fr:
      E.mass = 223;
      E.group = 1;
      E.period = 7;
      RAD;
      break;


    case Ra:
      E.mass = 226;
      E.group = 2;
      E.period = 7;
      RAD;
      break;

    case Ac:
      E.mass = 227;
      E.group = 3;
      E.period = 7;
      RAD;
      break;

    case Th:
      E.mass = 232.04;
      E.group = 3;
      E.period = 7;
      RAD;
      break;

    case Pa:
      E.mass = 231.04;
      E.group = 3;
      E.period = 7;
      RAD;
      break;

    case U:
      E.mass = 238.03;
      E.group = 3;
      E.period = 7;
      RAD;
      break;

    case Np:
      E.mass = 237;
      E.group = 3;
      E.period = 7;
      RAD;
      break;

    case Pu:
      E.mass = 244;
      E.group = 3;
      E.period = 7;
      RAD;
      break;

    case Am:
      E.mass = 243;
      E.group = 3;
      E.period = 7;
      RAD;
      break;

    case Cm:
      E.mass = 247;
      E.group = 3;
      E.period = 7;
      RAD;
      break;

    case Bk:
      E.mass = 247;
      E.group = 3;
      E.period = 7;
      RAD;
      break;

    case Cf:
      E.mass = 251;
      E.group = 3;
      E.period = 7;
      RAD;
      break;

    case Es:
      E.mass = 252;
      E.group = 3;
      E.period = 7;
      RAD;
      break;

    case Fm:
      E.mass = 257;
      E.group = 3;
      E.period = 7;
      RAD;
      break;

    case Md:
      E.mass = 258;
      E.group = 3;
      E.period = 7;
      RAD;
      break;

    case No:
      E.mass = 259;
      E.group = 3;
      E.period = 7;
      RAD;
      break;

    case Lr:
      E.mass = 266;
      E.group = 3;
      E.period = 7;
      RAD;
      break;

    case Rf:
      E.mass = 267;
      E.group = 4;
      E.period = 7;
      RAD;
      break;

    case Db:
      E.mass = 268;
      E.group = 5;
      E.period = 7;
      RAD;
      UNK;
      break;

    case Sg:
      E.mass = 269;
      E.group = 6;
      E.period = 7;
      RAD;
      UNK;
      break;

    case Bh:
      E.mass = 270;
      E.group = 7;
      E.period = 7;
      RAD;
      UNK;
      break;

    case Hs:
      E.mass = 277;
      E.group = 8;
      E.period = 7;
      RAD;
      UNK;
      break;

    case Mt:
      E.mass = 278;
      E.group = 9;
      E.period = 7;
      RAD;
      UNK;
      break;

    case Ds:
      E.mass = 281;
      E.group = 10;
      E.period = 7;
      RAD;
      UNK;
      break;

    case Rg:
      E.mass = 282;
      E.group = 11;
      E.period = 7;
      RAD;
      UNK;
      break;

    case Cn:
      E.mass = 285;
      E.group = 12;
      E.period = 7;
      RAD;
      UNK;
      break;

    case Nh:
      E.mass = 286;
      E.group = 13;
      E.period = 7;
      RAD;
      UNK;
      break;

    case Fl:
      E.mass = 289;
      E.group = 14;
      E.period = 7;
      RAD;
      UNK;
      break;

    case Mc:
      E.mass = 290;
      E.group = 15;
      E.period = 7;
      RAD;
      UNK;
      break;

    case Lv:
      E.mass = 293;
      E.group = 16;
      E.period = 7;
      RAD;
      UNK;
      break;

    case Ts:
      E.mass = 294;
      E.group = 17;
      E.period = 7;
      RAD;
      UNK;
      break;

    case Og:
      E.mass = 294;
      E.group = 18;
      E.period = 7;
      RAD;
      UNK;
      break;

    default:
      return NULL;
      break;
  }
  return &E;
}
