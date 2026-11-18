// Source exposure: binary-analysis
// Staticc15e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc15e0;
extern void construct(Staticc15e0*, const Descriptor*);
extern void destroy(Staticc15e0*);
struct Staticc15e0 {
    void* value;
    Staticc15e0() { construct(this, &descriptor); }
    ~Staticc15e0() { destroy(this); }
};
