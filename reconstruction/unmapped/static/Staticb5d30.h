// Source exposure: binary-analysis
// Staticb5d30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5d30;
extern void construct(Staticb5d30*, const Descriptor*);
extern void destroy(Staticb5d30*);
struct Staticb5d30 {
    void* value;
    Staticb5d30() { construct(this, &descriptor); }
    ~Staticb5d30() { destroy(this); }
};
