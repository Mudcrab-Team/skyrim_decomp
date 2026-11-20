// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf79890, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf79890 LeafAddressf79890::Address
#include "LeafAddressf79890.h"
extern unsigned char leaf_global;
void* LeafAddressf79890::Address() { return &leaf_global; }
