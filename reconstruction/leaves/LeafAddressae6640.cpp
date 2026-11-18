// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6640, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6640 LeafAddressae6640::Address
#include "LeafAddressae6640.h"
extern unsigned char leaf_global;
void* LeafAddressae6640::Address() { return &leaf_global; }
