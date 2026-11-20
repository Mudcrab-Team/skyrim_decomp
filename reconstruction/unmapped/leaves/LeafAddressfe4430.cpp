// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfe4430, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfe4430 LeafAddressfe4430::Address
#include "LeafAddressfe4430.h"
extern unsigned char leaf_global;
void* LeafAddressfe4430::Address() { return &leaf_global; }
