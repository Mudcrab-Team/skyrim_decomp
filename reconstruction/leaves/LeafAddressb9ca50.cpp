// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb9ca50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb9ca50 LeafAddressb9ca50::Address
#include "LeafAddressb9ca50.h"
extern unsigned char leaf_global;
void* LeafAddressb9ca50::Address() { return &leaf_global; }
