// Source exposure: binary-analysis
// Staticb5040, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5040;
extern void construct(Staticb5040*, const Descriptor*);
extern void destroy(Staticb5040*);
struct Staticb5040 {
    void* value;
    Staticb5040() { construct(this, &descriptor); }
    ~Staticb5040() { destroy(this); }
};
