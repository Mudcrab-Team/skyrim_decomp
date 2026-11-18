// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb53070, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb53070 LeafAddressb53070::Address
#include "LeafAddressb53070.h"
extern unsigned char leaf_global;
void* LeafAddressb53070::Address() { return &leaf_global; }
