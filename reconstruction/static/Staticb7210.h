// Source exposure: binary-analysis
// Staticb7210, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7210;
extern void construct(Staticb7210*, const Descriptor*);
extern void destroy(Staticb7210*);
struct Staticb7210 {
    void* value;
    Staticb7210() { construct(this, &descriptor); }
    ~Staticb7210() { destroy(this); }
};
