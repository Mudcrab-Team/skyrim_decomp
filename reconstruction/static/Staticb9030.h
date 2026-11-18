// Source exposure: binary-analysis
// Staticb9030, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9030;
extern void construct(Staticb9030*, const Descriptor*);
extern void destroy(Staticb9030*);
struct Staticb9030 {
    void* value;
    Staticb9030() { construct(this, &descriptor); }
    ~Staticb9030() { destroy(this); }
};
