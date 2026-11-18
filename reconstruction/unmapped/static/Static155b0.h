// Source exposure: binary-analysis
// Static155b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static155b0;
extern void construct(Static155b0*, const Descriptor*);
extern void destroy(Static155b0*);
struct Static155b0 {
    void* value;
    Static155b0() { construct(this, &descriptor); }
    ~Static155b0() { destroy(this); }
};
