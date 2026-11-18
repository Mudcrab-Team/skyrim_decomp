// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress461b90, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x461b90 LeafAddress461b90::Address
#include "LeafAddress461b90.h"
extern unsigned char leaf_global;
void* LeafAddress461b90::Address() { return &leaf_global; }
