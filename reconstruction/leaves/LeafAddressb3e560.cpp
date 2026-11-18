// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3e560, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3e560 LeafAddressb3e560::Address
#include "LeafAddressb3e560.h"
extern unsigned char leaf_global;
void* LeafAddressb3e560::Address() { return &leaf_global; }
