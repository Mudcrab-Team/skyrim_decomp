// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc49990, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc49990 LeafAddressc49990::Address
#include "LeafAddressc49990.h"
extern unsigned char leaf_global;
void* LeafAddressc49990::Address() { return &leaf_global; }
