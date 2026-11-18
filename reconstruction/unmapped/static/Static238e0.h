// Source exposure: binary-analysis
// Static238e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static238e0;
extern void construct(Static238e0*, const Descriptor*);
extern void destroy(Static238e0*);
struct Static238e0 {
    void* value;
    Static238e0() { construct(this, &descriptor); }
    ~Static238e0() { destroy(this); }
};
