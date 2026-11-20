// Source exposure: binary-analysis
// Staticc16a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc16a0;
extern void construct(Staticc16a0*, const Descriptor*);
extern void destroy(Staticc16a0*);
struct Staticc16a0 {
    void* value;
    Staticc16a0() { construct(this, &descriptor); }
    ~Staticc16a0() { destroy(this); }
};
