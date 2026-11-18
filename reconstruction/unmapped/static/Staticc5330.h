// Source exposure: binary-analysis
// Staticc5330, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc5330;
extern void construct(Staticc5330*, const Descriptor*);
extern void destroy(Staticc5330*);
struct Staticc5330 {
    void* value;
    Staticc5330() { construct(this, &descriptor); }
    ~Staticc5330() { destroy(this); }
};
