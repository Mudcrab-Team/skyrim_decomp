// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1467b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1467b0 LeafAddress1467b0::Address
#include "LeafAddress1467b0.h"
extern unsigned char leaf_global;
void* LeafAddress1467b0::Address() { return &leaf_global; }
