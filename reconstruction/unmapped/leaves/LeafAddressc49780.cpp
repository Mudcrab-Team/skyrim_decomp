// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc49780, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc49780 LeafAddressc49780::Address
#include "LeafAddressc49780.h"
extern unsigned char leaf_global;
void* LeafAddressc49780::Address() { return &leaf_global; }
