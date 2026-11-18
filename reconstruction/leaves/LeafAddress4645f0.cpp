// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress4645f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x4645f0 LeafAddress4645f0::Address
#include "LeafAddress4645f0.h"
extern unsigned char leaf_global;
void* LeafAddress4645f0::Address() { return &leaf_global; }
