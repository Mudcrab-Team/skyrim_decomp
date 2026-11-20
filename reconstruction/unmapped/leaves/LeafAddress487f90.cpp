// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress487f90, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x487f90 LeafAddress487f90::Address
#include "LeafAddress487f90.h"
extern unsigned char leaf_global;
void* LeafAddress487f90::Address() { return &leaf_global; }
