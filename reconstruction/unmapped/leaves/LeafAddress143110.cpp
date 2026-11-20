// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress143110, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x143110 LeafAddress143110::Address
#include "LeafAddress143110.h"
extern unsigned char leaf_global;
void* LeafAddress143110::Address() { return &leaf_global; }
