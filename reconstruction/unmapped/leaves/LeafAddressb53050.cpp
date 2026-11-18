// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb53050, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb53050 LeafAddressb53050::Address
#include "LeafAddressb53050.h"
extern unsigned char leaf_global;
void* LeafAddressb53050::Address() { return &leaf_global; }
