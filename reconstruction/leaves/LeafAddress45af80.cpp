// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45af80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45af80 LeafAddress45af80::Address
#include "LeafAddress45af80.h"
extern unsigned char leaf_global;
void* LeafAddress45af80::Address() { return &leaf_global; }
