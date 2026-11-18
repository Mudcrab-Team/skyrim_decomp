// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfeb360, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfeb360 LeafAddressfeb360::Address
#include "LeafAddressfeb360.h"
extern unsigned char leaf_global;
void* LeafAddressfeb360::Address() { return &leaf_global; }
