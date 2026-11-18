// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress475d60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x475d60 LeafAddress475d60::Address
#include "LeafAddress475d60.h"
extern unsigned char leaf_global;
void* LeafAddress475d60::Address() { return &leaf_global; }
