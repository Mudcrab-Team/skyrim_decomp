// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45af70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45af70 LeafAddress45af70::Address
#include "LeafAddress45af70.h"
extern unsigned char leaf_global;
void* LeafAddress45af70::Address() { return &leaf_global; }
