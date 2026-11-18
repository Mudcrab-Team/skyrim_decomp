// Source exposure: binary-analysis
// Staticb6830, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb6830;
extern void construct(Staticb6830*, const Descriptor*);
extern void destroy(Staticb6830*);
struct Staticb6830 {
    void* value;
    Staticb6830() { construct(this, &descriptor); }
    ~Staticb6830() { destroy(this); }
};
