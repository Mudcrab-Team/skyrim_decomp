// Source exposure: binary-analysis
// Staticefca0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticefca0;
extern void construct(Staticefca0*, const Descriptor*);
extern void destroy(Staticefca0*);
struct Staticefca0 {
    void* value;
    Staticefca0() { construct(this, &descriptor); }
    ~Staticefca0() { destroy(this); }
};
