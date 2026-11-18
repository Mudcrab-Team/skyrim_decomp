// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress461bb0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x461bb0 LeafAddress461bb0::Address
#include "LeafAddress461bb0.h"
extern unsigned char leaf_global;
void* LeafAddress461bb0::Address() { return &leaf_global; }
