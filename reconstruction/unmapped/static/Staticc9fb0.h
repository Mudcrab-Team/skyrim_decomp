// Source exposure: binary-analysis
// Staticc9fb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc9fb0;
extern void construct(Staticc9fb0*, const Descriptor*);
extern void destroy(Staticc9fb0*);
struct Staticc9fb0 {
    void* value;
    Staticc9fb0() { construct(this, &descriptor); }
    ~Staticc9fb0() { destroy(this); }
};
