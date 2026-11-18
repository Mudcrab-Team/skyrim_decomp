// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressaaaa40, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xaaaa40 LeafAddressaaaa40::Address
#include "LeafAddressaaaa40.h"
extern unsigned char leaf_global;
void* LeafAddressaaaa40::Address() { return &leaf_global; }
