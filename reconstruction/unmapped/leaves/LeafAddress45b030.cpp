// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45b030, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45b030 LeafAddress45b030::Address
#include "LeafAddress45b030.h"
extern unsigned char leaf_global;
void* LeafAddress45b030::Address() { return &leaf_global; }
