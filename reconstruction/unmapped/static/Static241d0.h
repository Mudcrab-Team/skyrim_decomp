// Source exposure: binary-analysis
// Static241d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static241d0;
extern void construct(Static241d0*, const Descriptor*);
extern void destroy(Static241d0*);
struct Static241d0 {
    void* value;
    Static241d0() { construct(this, &descriptor); }
    ~Static241d0() { destroy(this); }
};
