// Source exposure: binary-analysis
// Static219a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static219a0;
extern void construct(Static219a0*, const Descriptor*);
extern void destroy(Static219a0*);
struct Static219a0 {
    void* value;
    Static219a0() { construct(this, &descriptor); }
    ~Static219a0() { destroy(this); }
};
