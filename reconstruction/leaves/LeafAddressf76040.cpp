// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf76040, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf76040 LeafAddressf76040::Address
#include "LeafAddressf76040.h"
extern unsigned char leaf_global;
void* LeafAddressf76040::Address() { return &leaf_global; }
