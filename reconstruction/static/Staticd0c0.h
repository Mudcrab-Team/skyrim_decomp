// Source exposure: binary-analysis
// Staticd0c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd0c0;
extern void construct(Staticd0c0*, const Descriptor*);
extern void destroy(Staticd0c0*);
struct Staticd0c0 {
    void* value;
    Staticd0c0() { construct(this, &descriptor); }
    ~Staticd0c0() { destroy(this); }
};
