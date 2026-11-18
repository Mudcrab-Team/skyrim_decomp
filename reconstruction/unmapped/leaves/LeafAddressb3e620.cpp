// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3e620, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3e620 LeafAddressb3e620::Address
#include "LeafAddressb3e620.h"
extern unsigned char leaf_global;
void* LeafAddressb3e620::Address() { return &leaf_global; }
