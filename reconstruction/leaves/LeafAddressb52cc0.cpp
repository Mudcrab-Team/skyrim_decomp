// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52cc0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52cc0 LeafAddressb52cc0::Address
#include "LeafAddressb52cc0.h"
extern unsigned char leaf_global;
void* LeafAddressb52cc0::Address() { return &leaf_global; }
