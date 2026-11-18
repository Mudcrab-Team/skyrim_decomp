// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3e530, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3e530 LeafAddressb3e530::Address
#include "LeafAddressb3e530.h"
extern unsigned char leaf_global;
void* LeafAddressb3e530::Address() { return &leaf_global; }
