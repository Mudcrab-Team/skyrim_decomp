// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12967f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12967f0 LeafAddress12967f0::Address
#include "LeafAddress12967f0.h"
extern unsigned char leaf_global;
void* LeafAddress12967f0::Address() { return &leaf_global; }
