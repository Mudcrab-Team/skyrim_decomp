// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf15ff0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf15ff0 LeafAddressf15ff0::Address
#include "LeafAddressf15ff0.h"
extern unsigned char leaf_global;
void* LeafAddressf15ff0::Address() { return &leaf_global; }
