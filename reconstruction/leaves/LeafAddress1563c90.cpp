// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1563c90, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1563c90 LeafAddress1563c90::Address
#include "LeafAddress1563c90.h"
extern unsigned char leaf_global;
void* LeafAddress1563c90::Address() { return &leaf_global; }
