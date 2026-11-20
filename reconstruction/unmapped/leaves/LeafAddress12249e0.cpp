// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12249e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12249e0 LeafAddress12249e0::Address
#include "LeafAddress12249e0.h"
extern unsigned char leaf_global;
void* LeafAddress12249e0::Address() { return &leaf_global; }
