// Source exposure: binary-analysis
// Staticd1e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd1e0;
extern void construct(Staticd1e0*, const Descriptor*);
extern void destroy(Staticd1e0*);
struct Staticd1e0 {
    void* value;
    Staticd1e0() { construct(this, &descriptor); }
    ~Staticd1e0() { destroy(this); }
};
