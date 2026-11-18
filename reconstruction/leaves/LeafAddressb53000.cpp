// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb53000, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb53000 LeafAddressb53000::Address
#include "LeafAddressb53000.h"
extern unsigned char leaf_global;
void* LeafAddressb53000::Address() { return &leaf_global; }
