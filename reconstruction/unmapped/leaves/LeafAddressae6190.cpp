// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6190, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6190 LeafAddressae6190::Address
#include "LeafAddressae6190.h"
extern unsigned char leaf_global;
void* LeafAddressae6190::Address() { return &leaf_global; }
