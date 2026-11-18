// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfaa190, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfaa190 LeafAddressfaa190::Address
#include "LeafAddressfaa190.h"
extern unsigned char leaf_global;
void* LeafAddressfaa190::Address() { return &leaf_global; }
