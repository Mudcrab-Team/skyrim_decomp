// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress44eac0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x44eac0 LeafAddress44eac0::Address
#include "LeafAddress44eac0.h"
extern unsigned char leaf_global;
void* LeafAddress44eac0::Address() { return &leaf_global; }
