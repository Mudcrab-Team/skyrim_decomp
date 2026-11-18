// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress106a2b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x106a2b0 LeafAddress106a2b0::Address
#include "LeafAddress106a2b0.h"
extern unsigned char leaf_global;
void* LeafAddress106a2b0::Address() { return &leaf_global; }
