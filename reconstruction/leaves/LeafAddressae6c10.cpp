// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6c10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6c10 LeafAddressae6c10::Address
#include "LeafAddressae6c10.h"
extern unsigned char leaf_global;
void* LeafAddressae6c10::Address() { return &leaf_global; }
