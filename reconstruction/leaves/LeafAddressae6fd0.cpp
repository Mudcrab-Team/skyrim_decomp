// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6fd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6fd0 LeafAddressae6fd0::Address
#include "LeafAddressae6fd0.h"
extern unsigned char leaf_global;
void* LeafAddressae6fd0::Address() { return &leaf_global; }
