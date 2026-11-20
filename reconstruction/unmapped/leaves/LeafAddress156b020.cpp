// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress156b020, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x156b020 LeafAddress156b020::Address
#include "LeafAddress156b020.h"
extern unsigned char leaf_global;
void* LeafAddress156b020::Address() { return &leaf_global; }
