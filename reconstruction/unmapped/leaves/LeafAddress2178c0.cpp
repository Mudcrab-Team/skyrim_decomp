// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress2178c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x2178c0 LeafAddress2178c0::Address
#include "LeafAddress2178c0.h"
extern unsigned char leaf_global;
void* LeafAddress2178c0::Address() { return &leaf_global; }
