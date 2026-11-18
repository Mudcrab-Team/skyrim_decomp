// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf1e520, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf1e520 LeafAddressf1e520::Address
#include "LeafAddressf1e520.h"
extern unsigned char leaf_global;
void* LeafAddressf1e520::Address() { return &leaf_global; }
