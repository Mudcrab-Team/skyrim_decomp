// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12c3a80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12c3a80 LeafAddress12c3a80::Address
#include "LeafAddress12c3a80.h"
extern unsigned char leaf_global;
void* LeafAddress12c3a80::Address() { return &leaf_global; }
