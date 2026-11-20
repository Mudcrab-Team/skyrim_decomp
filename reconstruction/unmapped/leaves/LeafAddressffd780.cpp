// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressffd780, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xffd780 LeafAddressffd780::Address
#include "LeafAddressffd780.h"
extern unsigned char leaf_global;
void* LeafAddressffd780::Address() { return &leaf_global; }
