// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressadf8b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xadf8b0 LeafAddressadf8b0::Address
#include "LeafAddressadf8b0.h"
extern unsigned char leaf_global;
void* LeafAddressadf8b0::Address() { return &leaf_global; }
