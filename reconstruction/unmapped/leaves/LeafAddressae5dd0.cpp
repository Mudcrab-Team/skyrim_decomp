// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5dd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5dd0 LeafAddressae5dd0::Address
#include "LeafAddressae5dd0.h"
extern unsigned char leaf_global;
void* LeafAddressae5dd0::Address() { return &leaf_global; }
