// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress4103b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x4103b0 LeafAddress4103b0::Address
#include "LeafAddress4103b0.h"
extern unsigned char leaf_global;
void* LeafAddress4103b0::Address() { return &leaf_global; }
