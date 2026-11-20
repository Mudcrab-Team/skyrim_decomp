// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb86ad0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb86ad0 LeafAddressb86ad0::Address
#include "LeafAddressb86ad0.h"
extern unsigned char leaf_global;
void* LeafAddressb86ad0::Address() { return &leaf_global; }
