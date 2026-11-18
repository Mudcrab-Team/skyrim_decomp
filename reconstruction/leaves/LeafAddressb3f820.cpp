// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3f820, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3f820 LeafAddressb3f820::Address
#include "LeafAddressb3f820.h"
extern unsigned char leaf_global;
void* LeafAddressb3f820::Address() { return &leaf_global; }
