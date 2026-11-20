// Source exposure: binary-analysis
// Staticb7970, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7970;
extern void construct(Staticb7970*, const Descriptor*);
extern void destroy(Staticb7970*);
struct Staticb7970 {
    void* value;
    Staticb7970() { construct(this, &descriptor); }
    ~Staticb7970() { destroy(this); }
};
