// Source exposure: binary-analysis; no external implementation reused.
// LeafAddresseac650, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xeac650 LeafAddresseac650::Address
#include "LeafAddresseac650.h"
extern unsigned char leaf_global;
void* LeafAddresseac650::Address() { return &leaf_global; }
