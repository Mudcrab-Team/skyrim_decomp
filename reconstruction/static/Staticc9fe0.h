// Source exposure: binary-analysis
// Staticc9fe0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc9fe0;
extern void construct(Staticc9fe0*, const Descriptor*);
extern void destroy(Staticc9fe0*);
struct Staticc9fe0 {
    void* value;
    Staticc9fe0() { construct(this, &descriptor); }
    ~Staticc9fe0() { destroy(this); }
};
