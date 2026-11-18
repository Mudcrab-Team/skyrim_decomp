// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb86ae0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb86ae0 LeafAddressb86ae0::Address
#include "LeafAddressb86ae0.h"
extern unsigned char leaf_global;
void* LeafAddressb86ae0::Address() { return &leaf_global; }
