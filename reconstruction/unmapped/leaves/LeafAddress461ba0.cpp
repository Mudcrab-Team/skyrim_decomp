// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress461ba0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x461ba0 LeafAddress461ba0::Address
#include "LeafAddress461ba0.h"
extern unsigned char leaf_global;
void* LeafAddress461ba0::Address() { return &leaf_global; }
