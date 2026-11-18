// Source exposure: binary-analysis; no external implementation reused.
// LeafAddresscd6290, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xcd6290 LeafAddresscd6290::Address
#include "LeafAddresscd6290.h"
extern unsigned char leaf_global;
void* LeafAddresscd6290::Address() { return &leaf_global; }
