// Source exposure: binary-analysis
// Staticc2650, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc2650;
extern void construct(Staticc2650*, const Descriptor*);
extern void destroy(Staticc2650*);
struct Staticc2650 {
    void* value;
    Staticc2650() { construct(this, &descriptor); }
    ~Staticc2650() { destroy(this); }
};
