// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb2f250, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb2f250 LeafAddressb2f250::Address
#include "LeafAddressb2f250.h"
extern unsigned char leaf_global;
void* LeafAddressb2f250::Address() { return &leaf_global; }
