// Source exposure: binary-analysis
// Staticb6500, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb6500;
extern void construct(Staticb6500*, const Descriptor*);
extern void destroy(Staticb6500*);
struct Staticb6500 {
    void* value;
    Staticb6500() { construct(this, &descriptor); }
    ~Staticb6500() { destroy(this); }
};
