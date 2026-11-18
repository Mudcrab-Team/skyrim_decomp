// Source exposure: binary-analysis
// Staticb7c70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7c70;
extern void construct(Staticb7c70*, const Descriptor*);
extern void destroy(Staticb7c70*);
struct Staticb7c70 {
    void* value;
    Staticb7c70() { construct(this, &descriptor); }
    ~Staticb7c70() { destroy(this); }
};
