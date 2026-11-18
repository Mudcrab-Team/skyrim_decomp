// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfaefd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfaefd0 LeafAddressfaefd0::Address
#include "LeafAddressfaefd0.h"
extern unsigned char leaf_global;
void* LeafAddressfaefd0::Address() { return &leaf_global; }
