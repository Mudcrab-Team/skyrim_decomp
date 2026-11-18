// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc49980, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc49980 LeafAddressc49980::Address
#include "LeafAddressc49980.h"
extern unsigned char leaf_global;
void* LeafAddressc49980::Address() { return &leaf_global; }
