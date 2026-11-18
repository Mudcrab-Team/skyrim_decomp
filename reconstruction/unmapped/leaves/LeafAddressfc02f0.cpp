// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfc02f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfc02f0 LeafAddressfc02f0::Address
#include "LeafAddressfc02f0.h"
extern unsigned char leaf_global;
void* LeafAddressfc02f0::Address() { return &leaf_global; }
