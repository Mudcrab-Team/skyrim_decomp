// Source exposure: binary-analysis
// Static15430, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15430;
extern void construct(Static15430*, const Descriptor*);
extern void destroy(Static15430*);
struct Static15430 {
    void* value;
    Static15430() { construct(this, &descriptor); }
    ~Static15430() { destroy(this); }
};
