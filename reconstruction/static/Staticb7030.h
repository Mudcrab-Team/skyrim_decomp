// Source exposure: binary-analysis
// Staticb7030, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7030;
extern void construct(Staticb7030*, const Descriptor*);
extern void destroy(Staticb7030*);
struct Staticb7030 {
    void* value;
    Staticb7030() { construct(this, &descriptor); }
    ~Staticb7030() { destroy(this); }
};
