// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfd92b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfd92b0 LeafAddressfd92b0::Address
#include "LeafAddressfd92b0.h"
extern unsigned char leaf_global;
void* LeafAddressfd92b0::Address() { return &leaf_global; }
