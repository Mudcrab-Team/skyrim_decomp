// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfa5f10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfa5f10 LeafAddressfa5f10::Address
#include "LeafAddressfa5f10.h"
extern unsigned char leaf_global;
void* LeafAddressfa5f10::Address() { return &leaf_global; }
