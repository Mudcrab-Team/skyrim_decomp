// Source exposure: binary-analysis
// Staticb9150, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9150;
extern void construct(Staticb9150*, const Descriptor*);
extern void destroy(Staticb9150*);
struct Staticb9150 {
    void* value;
    Staticb9150() { construct(this, &descriptor); }
    ~Staticb9150() { destroy(this); }
};
