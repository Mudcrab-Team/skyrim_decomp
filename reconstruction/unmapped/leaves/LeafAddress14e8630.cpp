// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress14e8630, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x14e8630 LeafAddress14e8630::Address
#include "LeafAddress14e8630.h"
extern unsigned char leaf_global;
void* LeafAddress14e8630::Address() { return &leaf_global; }
