// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52f50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52f50 LeafAddressb52f50::Address
#include "LeafAddressb52f50.h"
extern unsigned char leaf_global;
void* LeafAddressb52f50::Address() { return &leaf_global; }
