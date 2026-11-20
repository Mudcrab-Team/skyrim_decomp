// Source exposure: binary-analysis
// Staticc5600, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc5600;
extern void construct(Staticc5600*, const Descriptor*);
extern void destroy(Staticc5600*);
struct Staticc5600 {
    void* value;
    Staticc5600() { construct(this, &descriptor); }
    ~Staticc5600() { destroy(this); }
};
