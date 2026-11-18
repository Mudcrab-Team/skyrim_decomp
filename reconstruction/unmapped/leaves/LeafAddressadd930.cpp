// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressadd930, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xadd930 LeafAddressadd930::Address
#include "LeafAddressadd930.h"
extern unsigned char leaf_global;
void* LeafAddressadd930::Address() { return &leaf_global; }
