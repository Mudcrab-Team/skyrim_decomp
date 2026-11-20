// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressadf870, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xadf870 LeafAddressadf870::Address
#include "LeafAddressadf870.h"
extern unsigned char leaf_global;
void* LeafAddressadf870::Address() { return &leaf_global; }
