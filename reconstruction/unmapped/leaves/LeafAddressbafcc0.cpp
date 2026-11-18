// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbafcc0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbafcc0 LeafAddressbafcc0::Address
#include "LeafAddressbafcc0.h"
extern unsigned char leaf_global;
void* LeafAddressbafcc0::Address() { return &leaf_global; }
