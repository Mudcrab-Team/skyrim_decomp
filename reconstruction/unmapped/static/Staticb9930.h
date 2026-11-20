// Source exposure: binary-analysis
// Staticb9930, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9930;
extern void construct(Staticb9930*, const Descriptor*);
extern void destroy(Staticb9930*);
struct Staticb9930 {
    void* value;
    Staticb9930() { construct(this, &descriptor); }
    ~Staticb9930() { destroy(this); }
};
