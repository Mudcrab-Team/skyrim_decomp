// Source exposure: binary-analysis
// Staticc9bc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc9bc0;
extern void construct(Staticc9bc0*, const Descriptor*);
extern void destroy(Staticc9bc0*);
struct Staticc9bc0 {
    void* value;
    Staticc9bc0() { construct(this, &descriptor); }
    ~Staticc9bc0() { destroy(this); }
};
