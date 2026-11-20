// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3e670, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3e670 LeafAddressb3e670::Address
#include "LeafAddressb3e670.h"
extern unsigned char leaf_global;
void* LeafAddressb3e670::Address() { return &leaf_global; }
