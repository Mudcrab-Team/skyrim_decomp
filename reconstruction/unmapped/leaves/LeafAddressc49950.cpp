// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc49950, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc49950 LeafAddressc49950::Address
#include "LeafAddressc49950.h"
extern unsigned char leaf_global;
void* LeafAddressc49950::Address() { return &leaf_global; }
