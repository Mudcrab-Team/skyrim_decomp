// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressadd660, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xadd660 LeafAddressadd660::Address
#include "LeafAddressadd660.h"
extern unsigned char leaf_global;
void* LeafAddressadd660::Address() { return &leaf_global; }
