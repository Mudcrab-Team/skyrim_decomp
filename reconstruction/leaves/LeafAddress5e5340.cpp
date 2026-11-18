// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5e5340, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5e5340 LeafAddress5e5340::Address
#include "LeafAddress5e5340.h"
extern unsigned char leaf_global;
void* LeafAddress5e5340::Address() { return &leaf_global; }
