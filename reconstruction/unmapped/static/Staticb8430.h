// Source exposure: binary-analysis
// Staticb8430, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb8430;
extern void construct(Staticb8430*, const Descriptor*);
extern void destroy(Staticb8430*);
struct Staticb8430 {
    void* value;
    Staticb8430() { construct(this, &descriptor); }
    ~Staticb8430() { destroy(this); }
};
