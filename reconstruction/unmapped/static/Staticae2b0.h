// Source exposure: binary-analysis
// Staticae2b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticae2b0;
extern void construct(Staticae2b0*, const Descriptor*);
extern void destroy(Staticae2b0*);
struct Staticae2b0 {
    void* value;
    Staticae2b0() { construct(this, &descriptor); }
    ~Staticae2b0() { destroy(this); }
};
