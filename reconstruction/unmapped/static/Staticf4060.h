// Source exposure: binary-analysis
// Staticf4060, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf4060;
extern void construct(Staticf4060*, const Descriptor*);
extern void destroy(Staticf4060*);
struct Staticf4060 {
    void* value;
    Staticf4060() { construct(this, &descriptor); }
    ~Staticf4060() { destroy(this); }
};
