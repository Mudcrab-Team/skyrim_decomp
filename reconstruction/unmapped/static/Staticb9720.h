// Source exposure: binary-analysis
// Staticb9720, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9720;
extern void construct(Staticb9720*, const Descriptor*);
extern void destroy(Staticb9720*);
struct Staticb9720 {
    void* value;
    Staticb9720() { construct(this, &descriptor); }
    ~Staticb9720() { destroy(this); }
};
