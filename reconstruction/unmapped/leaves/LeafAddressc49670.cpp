// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc49670, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc49670 LeafAddressc49670::Address
#include "LeafAddressc49670.h"
extern unsigned char leaf_global;
void* LeafAddressc49670::Address() { return &leaf_global; }
