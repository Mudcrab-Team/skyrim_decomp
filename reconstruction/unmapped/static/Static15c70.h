// Source exposure: binary-analysis
// Static15c70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15c70;
extern void construct(Static15c70*, const Descriptor*);
extern void destroy(Static15c70*);
struct Static15c70 {
    void* value;
    Static15c70() { construct(this, &descriptor); }
    ~Static15c70() { destroy(this); }
};
