// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress133420, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x133420 LeafAddress133420::Address
#include "LeafAddress133420.h"
extern unsigned char leaf_global;
void* LeafAddress133420::Address() { return &leaf_global; }
