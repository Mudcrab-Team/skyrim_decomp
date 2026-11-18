// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf0f820, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf0f820 LeafAddressf0f820::Address
#include "LeafAddressf0f820.h"
extern unsigned char leaf_global;
void* LeafAddressf0f820::Address() { return &leaf_global; }
