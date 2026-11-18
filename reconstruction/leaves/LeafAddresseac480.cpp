// Source exposure: binary-analysis; no external implementation reused.
// LeafAddresseac480, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xeac480 LeafAddresseac480::Address
#include "LeafAddresseac480.h"
extern unsigned char leaf_global;
void* LeafAddresseac480::Address() { return &leaf_global; }
