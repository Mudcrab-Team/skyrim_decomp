// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress51c9f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x51c9f0 LeafAddress51c9f0::Address
#include "LeafAddress51c9f0.h"
extern unsigned char leaf_global;
void* LeafAddress51c9f0::Address() { return &leaf_global; }
