// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressff5ac0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xff5ac0 LeafAddressff5ac0::Address
#include "LeafAddressff5ac0.h"
extern unsigned char leaf_global;
void* LeafAddressff5ac0::Address() { return &leaf_global; }
