// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6240, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6240 LeafAddressae6240::Address
#include "LeafAddressae6240.h"
extern unsigned char leaf_global;
void* LeafAddressae6240::Address() { return &leaf_global; }
