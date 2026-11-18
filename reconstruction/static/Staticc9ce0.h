// Source exposure: binary-analysis
// Staticc9ce0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc9ce0;
extern void construct(Staticc9ce0*, const Descriptor*);
extern void destroy(Staticc9ce0*);
struct Staticc9ce0 {
    void* value;
    Staticc9ce0() { construct(this, &descriptor); }
    ~Staticc9ce0() { destroy(this); }
};
