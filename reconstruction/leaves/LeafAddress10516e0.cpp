// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10516e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10516e0 LeafAddress10516e0::Address
#include "LeafAddress10516e0.h"
extern unsigned char leaf_global;
void* LeafAddress10516e0::Address() { return &leaf_global; }
