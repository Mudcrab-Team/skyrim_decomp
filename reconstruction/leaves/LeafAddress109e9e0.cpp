// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress109e9e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x109e9e0 LeafAddress109e9e0::Address
#include "LeafAddress109e9e0.h"
extern unsigned char leaf_global;
void* LeafAddress109e9e0::Address() { return &leaf_global; }
