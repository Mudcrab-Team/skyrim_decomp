// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52ee0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52ee0 LeafAddressb52ee0::Address
#include "LeafAddressb52ee0.h"
extern unsigned char leaf_global;
void* LeafAddressb52ee0::Address() { return &leaf_global; }
