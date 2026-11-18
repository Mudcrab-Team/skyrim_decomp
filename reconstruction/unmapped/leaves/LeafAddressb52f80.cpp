// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52f80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52f80 LeafAddressb52f80::Address
#include "LeafAddressb52f80.h"
extern unsigned char leaf_global;
void* LeafAddressb52f80::Address() { return &leaf_global; }
