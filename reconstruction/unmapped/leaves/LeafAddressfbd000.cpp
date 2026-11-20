// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfbd000, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfbd000 LeafAddressfbd000::Address
#include "LeafAddressfbd000.h"
extern unsigned char leaf_global;
void* LeafAddressfbd000::Address() { return &leaf_global; }
