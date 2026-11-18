// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressadfb20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xadfb20 LeafAddressadfb20::Address
#include "LeafAddressadfb20.h"
extern unsigned char leaf_global;
void* LeafAddressadfb20::Address() { return &leaf_global; }
