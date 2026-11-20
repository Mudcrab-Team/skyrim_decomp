// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress135470, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x135470 LeafAddress135470::Address
#include "LeafAddress135470.h"
extern unsigned char leaf_global;
void* LeafAddress135470::Address() { return &leaf_global; }
