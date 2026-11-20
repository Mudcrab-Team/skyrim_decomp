// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress4a9fb0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x4a9fb0 LeafAddress4a9fb0::Address
#include "LeafAddress4a9fb0.h"
extern unsigned char leaf_global;
void* LeafAddress4a9fb0::Address() { return &leaf_global; }
