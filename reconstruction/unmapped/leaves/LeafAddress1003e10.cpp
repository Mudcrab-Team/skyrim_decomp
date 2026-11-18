// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1003e10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1003e10 LeafAddress1003e10::Address
#include "LeafAddress1003e10.h"
extern unsigned char leaf_global;
void* LeafAddress1003e10::Address() { return &leaf_global; }
