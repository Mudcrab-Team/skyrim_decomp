// Source exposure: binary-analysis
// Staticfc00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticfc00;
extern void construct(Staticfc00*, const Descriptor*);
extern void destroy(Staticfc00*);
struct Staticfc00 {
    void* value;
    Staticfc00() { construct(this, &descriptor); }
    ~Staticfc00() { destroy(this); }
};
