// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfba130, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfba130 LeafAddressfba130::Address
#include "LeafAddressfba130.h"
extern unsigned char leaf_global;
void* LeafAddressfba130::Address() { return &leaf_global; }
