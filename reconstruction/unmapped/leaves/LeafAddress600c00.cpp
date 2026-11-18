// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress600c00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x600c00 LeafAddress600c00::Address
#include "LeafAddress600c00.h"
extern unsigned char leaf_global;
void* LeafAddress600c00::Address() { return &leaf_global; }
