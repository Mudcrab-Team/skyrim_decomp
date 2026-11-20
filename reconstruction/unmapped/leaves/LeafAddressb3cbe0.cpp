// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3cbe0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3cbe0 LeafAddressb3cbe0::Address
#include "LeafAddressb3cbe0.h"
extern unsigned char leaf_global;
void* LeafAddressb3cbe0::Address() { return &leaf_global; }
