// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3f850, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3f850 LeafAddressb3f850::Address
#include "LeafAddressb3f850.h"
extern unsigned char leaf_global;
void* LeafAddressb3f850::Address() { return &leaf_global; }
