// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6280, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6280 LeafAddressae6280::Address
#include "LeafAddressae6280.h"
extern unsigned char leaf_global;
void* LeafAddressae6280::Address() { return &leaf_global; }
