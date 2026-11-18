// Source exposure: binary-analysis
// Staticb8d60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb8d60;
extern void construct(Staticb8d60*, const Descriptor*);
extern void destroy(Staticb8d60*);
struct Staticb8d60 {
    void* value;
    Staticb8d60() { construct(this, &descriptor); }
    ~Staticb8d60() { destroy(this); }
};
