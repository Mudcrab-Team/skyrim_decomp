// Source exposure: binary-analysis
// Staticd240, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd240;
extern void construct(Staticd240*, const Descriptor*);
extern void destroy(Staticd240*);
struct Staticd240 {
    void* value;
    Staticd240() { construct(this, &descriptor); }
    ~Staticd240() { destroy(this); }
};
