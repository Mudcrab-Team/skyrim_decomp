// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52f40, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52f40 LeafAddressb52f40::Address
#include "LeafAddressb52f40.h"
extern unsigned char leaf_global;
void* LeafAddressb52f40::Address() { return &leaf_global; }
