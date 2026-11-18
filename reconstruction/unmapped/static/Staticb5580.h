// Source exposure: binary-analysis
// Staticb5580, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5580;
extern void construct(Staticb5580*, const Descriptor*);
extern void destroy(Staticb5580*);
struct Staticb5580 {
    void* value;
    Staticb5580() { construct(this, &descriptor); }
    ~Staticb5580() { destroy(this); }
};
