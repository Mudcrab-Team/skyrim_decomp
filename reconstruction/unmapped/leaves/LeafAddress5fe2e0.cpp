// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5fe2e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5fe2e0 LeafAddress5fe2e0::Address
#include "LeafAddress5fe2e0.h"
extern unsigned char leaf_global;
void* LeafAddress5fe2e0::Address() { return &leaf_global; }
