// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52d30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52d30 LeafAddressb52d30::Address
#include "LeafAddressb52d30.h"
extern unsigned char leaf_global;
void* LeafAddressb52d30::Address() { return &leaf_global; }
