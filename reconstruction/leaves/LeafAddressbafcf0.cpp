// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbafcf0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbafcf0 LeafAddressbafcf0::Address
#include "LeafAddressbafcf0.h"
extern unsigned char leaf_global;
void* LeafAddressbafcf0::Address() { return &leaf_global; }
