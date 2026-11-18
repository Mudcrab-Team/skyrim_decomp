// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress107f9d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x107f9d0 LeafAddress107f9d0::Address
#include "LeafAddress107f9d0.h"
extern unsigned char leaf_global;
void* LeafAddress107f9d0::Address() { return &leaf_global; }
