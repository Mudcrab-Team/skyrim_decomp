// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5e9f60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5e9f60 LeafAddress5e9f60::Address
#include "LeafAddress5e9f60.h"
extern unsigned char leaf_global;
void* LeafAddress5e9f60::Address() { return &leaf_global; }
