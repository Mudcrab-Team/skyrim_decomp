// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress14e9e70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x14e9e70 LeafAddress14e9e70::Address
#include "LeafAddress14e9e70.h"
extern unsigned char leaf_global;
void* LeafAddress14e9e70::Address() { return &leaf_global; }
