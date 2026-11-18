// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3e690, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3e690 LeafAddressb3e690::Address
#include "LeafAddressb3e690.h"
extern unsigned char leaf_global;
void* LeafAddressb3e690::Address() { return &leaf_global; }
