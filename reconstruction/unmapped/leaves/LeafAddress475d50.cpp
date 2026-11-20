// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress475d50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x475d50 LeafAddress475d50::Address
#include "LeafAddress475d50.h"
extern unsigned char leaf_global;
void* LeafAddress475d50::Address() { return &leaf_global; }
