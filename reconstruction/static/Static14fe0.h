// Source exposure: binary-analysis
// Static14fe0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static14fe0;
extern void construct(Static14fe0*, const Descriptor*);
extern void destroy(Static14fe0*);
struct Static14fe0 {
    void* value;
    Static14fe0() { construct(this, &descriptor); }
    ~Static14fe0() { destroy(this); }
};
