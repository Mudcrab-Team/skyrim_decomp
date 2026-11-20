// Source exposure: binary-analysis
// Staticd6c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd6c0;
extern void construct(Staticd6c0*, const Descriptor*);
extern void destroy(Staticd6c0*);
struct Staticd6c0 {
    void* value;
    Staticd6c0() { construct(this, &descriptor); }
    ~Staticd6c0() { destroy(this); }
};
