// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfa8f10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfa8f10 LeafAddressfa8f10::Address
#include "LeafAddressfa8f10.h"
extern unsigned char leaf_global;
void* LeafAddressfa8f10::Address() { return &leaf_global; }
