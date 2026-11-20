// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12cc120, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12cc120 LeafAddress12cc120::Address
#include "LeafAddress12cc120.h"
extern unsigned char leaf_global;
void* LeafAddress12cc120::Address() { return &leaf_global; }
