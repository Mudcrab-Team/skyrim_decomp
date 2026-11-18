// Source exposure: binary-analysis
// Staticb66b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb66b0;
extern void construct(Staticb66b0*, const Descriptor*);
extern void destroy(Staticb66b0*);
struct Staticb66b0 {
    void* value;
    Staticb66b0() { construct(this, &descriptor); }
    ~Staticb66b0() { destroy(this); }
};
