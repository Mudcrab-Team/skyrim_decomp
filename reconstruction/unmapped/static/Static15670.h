// Source exposure: binary-analysis
// Static15670, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15670;
extern void construct(Static15670*, const Descriptor*);
extern void destroy(Static15670*);
struct Static15670 {
    void* value;
    Static15670() { construct(this, &descriptor); }
    ~Static15670() { destroy(this); }
};
