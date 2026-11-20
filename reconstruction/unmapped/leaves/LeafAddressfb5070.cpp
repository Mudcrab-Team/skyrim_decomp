// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfb5070, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfb5070 LeafAddressfb5070::Address
#include "LeafAddressfb5070.h"
extern unsigned char leaf_global;
void* LeafAddressfb5070::Address() { return &leaf_global; }
