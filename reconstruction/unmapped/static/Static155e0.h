// Source exposure: binary-analysis
// Static155e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static155e0;
extern void construct(Static155e0*, const Descriptor*);
extern void destroy(Static155e0*);
struct Static155e0 {
    void* value;
    Static155e0() { construct(this, &descriptor); }
    ~Static155e0() { destroy(this); }
};
