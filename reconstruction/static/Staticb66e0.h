// Source exposure: binary-analysis
// Staticb66e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb66e0;
extern void construct(Staticb66e0*, const Descriptor*);
extern void destroy(Staticb66e0*);
struct Staticb66e0 {
    void* value;
    Staticb66e0() { construct(this, &descriptor); }
    ~Staticb66e0() { destroy(this); }
};
