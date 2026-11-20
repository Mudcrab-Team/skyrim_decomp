// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3e520, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3e520 LeafAddressb3e520::Address
#include "LeafAddressb3e520.h"
extern unsigned char leaf_global;
void* LeafAddressb3e520::Address() { return &leaf_global; }
