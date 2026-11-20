// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb7e260, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb7e260 LeafAddressb7e260::Address
#include "LeafAddressb7e260.h"
extern unsigned char leaf_global;
void* LeafAddressb7e260::Address() { return &leaf_global; }
