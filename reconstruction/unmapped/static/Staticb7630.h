// Source exposure: binary-analysis
// Staticb7630, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7630;
extern void construct(Staticb7630*, const Descriptor*);
extern void destroy(Staticb7630*);
struct Staticb7630 {
    void* value;
    Staticb7630() { construct(this, &descriptor); }
    ~Staticb7630() { destroy(this); }
};
