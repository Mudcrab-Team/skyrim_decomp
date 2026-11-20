// Source exposure: binary-analysis
// Staticf2ea0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf2ea0;
extern void construct(Staticf2ea0*, const Descriptor*);
extern void destroy(Staticf2ea0*);
struct Staticf2ea0 {
    void* value;
    Staticf2ea0() { construct(this, &descriptor); }
    ~Staticf2ea0() { destroy(this); }
};
