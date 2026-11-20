// Source exposure: binary-analysis
// Staticb7300, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7300;
extern void construct(Staticb7300*, const Descriptor*);
extern void destroy(Staticb7300*);
struct Staticb7300 {
    void* value;
    Staticb7300() { construct(this, &descriptor); }
    ~Staticb7300() { destroy(this); }
};
