// Source exposure: binary-analysis
// Staticefdc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticefdc0;
extern void construct(Staticefdc0*, const Descriptor*);
extern void destroy(Staticefdc0*);
struct Staticefdc0 {
    void* value;
    Staticefdc0() { construct(this, &descriptor); }
    ~Staticefdc0() { destroy(this); }
};
