// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3e640, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3e640 LeafAddressb3e640::Address
#include "LeafAddressb3e640.h"
extern unsigned char leaf_global;
void* LeafAddressb3e640::Address() { return &leaf_global; }
