// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb53060, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb53060 LeafAddressb53060::Address
#include "LeafAddressb53060.h"
extern unsigned char leaf_global;
void* LeafAddressb53060::Address() { return &leaf_global; }
