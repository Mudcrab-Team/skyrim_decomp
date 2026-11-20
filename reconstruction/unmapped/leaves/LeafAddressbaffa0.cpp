// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbaffa0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbaffa0 LeafAddressbaffa0::Address
#include "LeafAddressbaffa0.h"
extern unsigned char leaf_global;
void* LeafAddressbaffa0::Address() { return &leaf_global; }
