// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress461b80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x461b80 LeafAddress461b80::Address
#include "LeafAddress461b80.h"
extern unsigned char leaf_global;
void* LeafAddress461b80::Address() { return &leaf_global; }
