// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress665880, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x665880 LeafAddress665880::Address
#include "LeafAddress665880.h"
extern unsigned char leaf_global;
void* LeafAddress665880::Address() { return &leaf_global; }
