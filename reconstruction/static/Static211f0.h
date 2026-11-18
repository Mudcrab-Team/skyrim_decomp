// Source exposure: binary-analysis
// Static211f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static211f0;
extern void construct(Static211f0*, const Descriptor*);
extern void destroy(Static211f0*);
struct Static211f0 {
    void* value;
    Static211f0() { construct(this, &descriptor); }
    ~Static211f0() { destroy(this); }
};
