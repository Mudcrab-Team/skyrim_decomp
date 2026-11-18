// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress7382f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x7382f0 LeafAddress7382f0::Address
#include "LeafAddress7382f0.h"
extern unsigned char leaf_global;
void* LeafAddress7382f0::Address() { return &leaf_global; }
