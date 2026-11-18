// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfe1dd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfe1dd0 LeafAddressfe1dd0::Address
#include "LeafAddressfe1dd0.h"
extern unsigned char leaf_global;
void* LeafAddressfe1dd0::Address() { return &leaf_global; }
