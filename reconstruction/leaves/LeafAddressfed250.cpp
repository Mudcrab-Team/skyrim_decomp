// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfed250, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfed250 LeafAddressfed250::Address
#include "LeafAddressfed250.h"
extern unsigned char leaf_global;
void* LeafAddressfed250::Address() { return &leaf_global; }
