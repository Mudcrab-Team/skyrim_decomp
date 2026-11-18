// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress477ca0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x477ca0 LeafAddress477ca0::Address
#include "LeafAddress477ca0.h"
extern unsigned char leaf_global;
void* LeafAddress477ca0::Address() { return &leaf_global; }
