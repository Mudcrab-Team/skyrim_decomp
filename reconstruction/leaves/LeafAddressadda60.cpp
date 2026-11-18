// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressadda60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xadda60 LeafAddressadda60::Address
#include "LeafAddressadda60.h"
extern unsigned char leaf_global;
void* LeafAddressadda60::Address() { return &leaf_global; }
