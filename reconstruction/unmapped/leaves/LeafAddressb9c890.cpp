// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb9c890, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb9c890 LeafAddressb9c890::Address
#include "LeafAddressb9c890.h"
extern unsigned char leaf_global;
void* LeafAddressb9c890::Address() { return &leaf_global; }
