// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress11b470, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x11b470 LeafAddress11b470::Address
#include "LeafAddress11b470.h"
extern unsigned char leaf_global;
void* LeafAddress11b470::Address() { return &leaf_global; }
