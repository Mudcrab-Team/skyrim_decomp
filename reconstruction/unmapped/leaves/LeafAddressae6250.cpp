// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6250, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6250 LeafAddressae6250::Address
#include "LeafAddressae6250.h"
extern unsigned char leaf_global;
void* LeafAddressae6250::Address() { return &leaf_global; }
