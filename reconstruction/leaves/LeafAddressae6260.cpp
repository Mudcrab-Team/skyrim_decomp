// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6260, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6260 LeafAddressae6260::Address
#include "LeafAddressae6260.h"
extern unsigned char leaf_global;
void* LeafAddressae6260::Address() { return &leaf_global; }
