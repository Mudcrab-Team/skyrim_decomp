// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress136a80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x136a80 LeafAddress136a80::Address
#include "LeafAddress136a80.h"
extern unsigned char leaf_global;
void* LeafAddress136a80::Address() { return &leaf_global; }
