// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress64b0d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x64b0d0 LeafAddress64b0d0::Address
#include "LeafAddress64b0d0.h"
extern unsigned char leaf_global;
void* LeafAddress64b0d0::Address() { return &leaf_global; }
