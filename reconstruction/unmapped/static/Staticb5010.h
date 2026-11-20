// Source exposure: binary-analysis
// Staticb5010, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5010;
extern void construct(Staticb5010*, const Descriptor*);
extern void destroy(Staticb5010*);
struct Staticb5010 {
    void* value;
    Staticb5010() { construct(this, &descriptor); }
    ~Staticb5010() { destroy(this); }
};
