// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12cc0f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12cc0f0 LeafAddress12cc0f0::Address
#include "LeafAddress12cc0f0.h"
extern unsigned char leaf_global;
void* LeafAddress12cc0f0::Address() { return &leaf_global; }
