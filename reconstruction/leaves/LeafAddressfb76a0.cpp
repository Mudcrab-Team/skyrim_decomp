// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfb76a0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfb76a0 LeafAddressfb76a0::Address
#include "LeafAddressfb76a0.h"
extern unsigned char leaf_global;
void* LeafAddressfb76a0::Address() { return &leaf_global; }
