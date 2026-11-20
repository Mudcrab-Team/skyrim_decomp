// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress44f800, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x44f800 LeafAddress44f800::Address
#include "LeafAddress44f800.h"
extern unsigned char leaf_global;
void* LeafAddress44f800::Address() { return &leaf_global; }
