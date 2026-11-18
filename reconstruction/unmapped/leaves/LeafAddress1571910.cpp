// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1571910, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1571910 LeafAddress1571910::Address
#include "LeafAddress1571910.h"
extern unsigned char leaf_global;
void* LeafAddress1571910::Address() { return &leaf_global; }
