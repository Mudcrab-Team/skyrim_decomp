// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressbaff60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xbaff60 LeafAddressbaff60::Address
#include "LeafAddressbaff60.h"
extern unsigned char leaf_global;
void* LeafAddressbaff60::Address() { return &leaf_global; }
