// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressaaf450, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xaaf450 LeafAddressaaf450::Address
#include "LeafAddressaaf450.h"
extern unsigned char leaf_global;
void* LeafAddressaaf450::Address() { return &leaf_global; }
