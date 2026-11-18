// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf85310, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf85310 LeafAddressf85310::Address
#include "LeafAddressf85310.h"
extern unsigned char leaf_global;
void* LeafAddressf85310::Address() { return &leaf_global; }
