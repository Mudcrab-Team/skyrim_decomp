// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress133c590, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x133c590 LeafAddress133c590::Address
#include "LeafAddress133c590.h"
extern unsigned char leaf_global;
void* LeafAddress133c590::Address() { return &leaf_global; }
