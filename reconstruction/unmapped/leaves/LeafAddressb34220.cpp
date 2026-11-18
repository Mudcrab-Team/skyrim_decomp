// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb34220, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb34220 LeafAddressb34220::Address
#include "LeafAddressb34220.h"
extern unsigned char leaf_global;
void* LeafAddressb34220::Address() { return &leaf_global; }
