// Source exposure: binary-analysis
// Staticb5d60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5d60;
extern void construct(Staticb5d60*, const Descriptor*);
extern void destroy(Staticb5d60*);
struct Staticb5d60 {
    void* value;
    Staticb5d60() { construct(this, &descriptor); }
    ~Staticb5d60() { destroy(this); }
};
