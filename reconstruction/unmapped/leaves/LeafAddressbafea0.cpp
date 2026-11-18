// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbafea0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbafea0 LeafAddressbafea0::Address
#include "LeafAddressbafea0.h"
extern unsigned char leaf_global;
void* LeafAddressbafea0::Address() { return &leaf_global; }
