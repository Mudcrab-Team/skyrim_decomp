// Source exposure: binary-analysis
// Staticc56f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc56f0;
extern void construct(Staticc56f0*, const Descriptor*);
extern void destroy(Staticc56f0*);
struct Staticc56f0 {
    void* value;
    Staticc56f0() { construct(this, &descriptor); }
    ~Staticc56f0() { destroy(this); }
};
