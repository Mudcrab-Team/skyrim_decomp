// Source exposure: binary-analysis
// Staticc9cb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc9cb0;
extern void construct(Staticc9cb0*, const Descriptor*);
extern void destroy(Staticc9cb0*);
struct Staticc9cb0 {
    void* value;
    Staticc9cb0() { construct(this, &descriptor); }
    ~Staticc9cb0() { destroy(this); }
};
