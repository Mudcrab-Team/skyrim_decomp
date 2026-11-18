// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbafe40, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbafe40 LeafAddressbafe40::Address
#include "LeafAddressbafe40.h"
extern unsigned char leaf_global;
void* LeafAddressbafe40::Address() { return &leaf_global; }
