// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc49680, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc49680 LeafAddressc49680::Address
#include "LeafAddressc49680.h"
extern unsigned char leaf_global;
void* LeafAddressc49680::Address() { return &leaf_global; }
