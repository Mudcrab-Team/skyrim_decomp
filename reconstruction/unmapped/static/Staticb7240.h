// Source exposure: binary-analysis
// Staticb7240, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7240;
extern void construct(Staticb7240*, const Descriptor*);
extern void destroy(Staticb7240*);
struct Staticb7240 {
    void* value;
    Staticb7240() { construct(this, &descriptor); }
    ~Staticb7240() { destroy(this); }
};
