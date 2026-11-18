// Source exposure: binary-analysis
// Staticb9060, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9060;
extern void construct(Staticb9060*, const Descriptor*);
extern void destroy(Staticb9060*);
struct Staticb9060 {
    void* value;
    Staticb9060() { construct(this, &descriptor); }
    ~Staticb9060() { destroy(this); }
};
