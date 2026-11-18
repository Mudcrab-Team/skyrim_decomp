// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress109e9f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x109e9f0 LeafAddress109e9f0::Address
#include "LeafAddress109e9f0.h"
extern unsigned char leaf_global;
void* LeafAddress109e9f0::Address() { return &leaf_global; }
