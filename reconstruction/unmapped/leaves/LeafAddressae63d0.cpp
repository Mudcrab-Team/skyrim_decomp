// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae63d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae63d0 LeafAddressae63d0::Address
#include "LeafAddressae63d0.h"
extern unsigned char leaf_global;
void* LeafAddressae63d0::Address() { return &leaf_global; }
