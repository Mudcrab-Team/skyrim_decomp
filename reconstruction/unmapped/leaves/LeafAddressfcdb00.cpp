// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfcdb00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfcdb00 LeafAddressfcdb00::Address
#include "LeafAddressfcdb00.h"
extern unsigned char leaf_global;
void* LeafAddressfcdb00::Address() { return &leaf_global; }
