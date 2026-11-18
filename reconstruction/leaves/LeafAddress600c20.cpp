// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress600c20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x600c20 LeafAddress600c20::Address
#include "LeafAddress600c20.h"
extern unsigned char leaf_global;
void* LeafAddress600c20::Address() { return &leaf_global; }
