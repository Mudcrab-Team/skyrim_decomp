// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress46e9c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x46e9c0 LeafAddress46e9c0::Address
#include "LeafAddress46e9c0.h"
extern unsigned char leaf_global;
void* LeafAddress46e9c0::Address() { return &leaf_global; }
