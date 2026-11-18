// Source exposure: binary-analysis
// Staticadbb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticadbb0;
extern void construct(Staticadbb0*, const Descriptor*);
extern void destroy(Staticadbb0*);
struct Staticadbb0 {
    void* value;
    Staticadbb0() { construct(this, &descriptor); }
    ~Staticadbb0() { destroy(this); }
};
