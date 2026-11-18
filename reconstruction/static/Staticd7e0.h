// Source exposure: binary-analysis
// Staticd7e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd7e0;
extern void construct(Staticd7e0*, const Descriptor*);
extern void destroy(Staticd7e0*);
struct Staticd7e0 {
    void* value;
    Staticd7e0() { construct(this, &descriptor); }
    ~Staticd7e0() { destroy(this); }
};
