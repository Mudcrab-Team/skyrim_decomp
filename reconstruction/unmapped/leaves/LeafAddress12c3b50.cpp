// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12c3b50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12c3b50 LeafAddress12c3b50::Address
#include "LeafAddress12c3b50.h"
extern unsigned char leaf_global;
void* LeafAddress12c3b50::Address() { return &leaf_global; }
