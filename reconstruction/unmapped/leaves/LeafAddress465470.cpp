// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress465470, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x465470 LeafAddress465470::Address
#include "LeafAddress465470.h"
extern unsigned char leaf_global;
void* LeafAddress465470::Address() { return &leaf_global; }
