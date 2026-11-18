// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45af60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45af60 LeafAddress45af60::Address
#include "LeafAddress45af60.h"
extern unsigned char leaf_global;
void* LeafAddress45af60::Address() { return &leaf_global; }
