// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress442e20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x442e20 LeafAddress442e20::Address
#include "LeafAddress442e20.h"
extern unsigned char leaf_global;
void* LeafAddress442e20::Address() { return &leaf_global; }
