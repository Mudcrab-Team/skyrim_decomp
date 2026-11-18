// Source exposure: binary-analysis
// Staticda80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticda80;
extern void construct(Staticda80*, const Descriptor*);
extern void destroy(Staticda80*);
struct Staticda80 {
    void* value;
    Staticda80() { construct(this, &descriptor); }
    ~Staticda80() { destroy(this); }
};
