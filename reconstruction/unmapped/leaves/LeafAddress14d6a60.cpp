// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress14d6a60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x14d6a60 LeafAddress14d6a60::Address
#include "LeafAddress14d6a60.h"
extern unsigned char leaf_global;
void* LeafAddress14d6a60::Address() { return &leaf_global; }
