// Source exposure: binary-analysis
// Staticb9600, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9600;
extern void construct(Staticb9600*, const Descriptor*);
extern void destroy(Staticb9600*);
struct Staticb9600 {
    void* value;
    Staticb9600() { construct(this, &descriptor); }
    ~Staticb9600() { destroy(this); }
};
