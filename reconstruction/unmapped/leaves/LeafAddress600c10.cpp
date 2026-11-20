// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress600c10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x600c10 LeafAddress600c10::Address
#include "LeafAddress600c10.h"
extern unsigned char leaf_global;
void* LeafAddress600c10::Address() { return &leaf_global; }
