// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5e2300, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5e2300 LeafAddress5e2300::Address
#include "LeafAddress5e2300.h"
extern unsigned char leaf_global;
void* LeafAddress5e2300::Address() { return &leaf_global; }
