// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1004bf0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1004bf0 LeafAddress1004bf0::Address
#include "LeafAddress1004bf0.h"
extern unsigned char leaf_global;
void* LeafAddress1004bf0::Address() { return &leaf_global; }
