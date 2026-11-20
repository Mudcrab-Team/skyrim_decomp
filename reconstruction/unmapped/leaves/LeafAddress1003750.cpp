// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1003750, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1003750 LeafAddress1003750::Address
#include "LeafAddress1003750.h"
extern unsigned char leaf_global;
void* LeafAddress1003750::Address() { return &leaf_global; }
