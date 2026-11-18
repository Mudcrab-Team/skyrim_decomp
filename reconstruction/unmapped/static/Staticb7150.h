// Source exposure: binary-analysis
// Staticb7150, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7150;
extern void construct(Staticb7150*, const Descriptor*);
extern void destroy(Staticb7150*);
struct Staticb7150 {
    void* value;
    Staticb7150() { construct(this, &descriptor); }
    ~Staticb7150() { destroy(this); }
};
