// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6710, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6710 LeafAddressae6710::Address
#include "LeafAddressae6710.h"
extern unsigned char leaf_global;
void* LeafAddressae6710::Address() { return &leaf_global; }
