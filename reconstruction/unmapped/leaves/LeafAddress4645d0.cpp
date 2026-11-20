// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress4645d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x4645d0 LeafAddress4645d0::Address
#include "LeafAddress4645d0.h"
extern unsigned char leaf_global;
void* LeafAddress4645d0::Address() { return &leaf_global; }
