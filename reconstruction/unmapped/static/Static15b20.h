// Source exposure: binary-analysis
// Static15b20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15b20;
extern void construct(Static15b20*, const Descriptor*);
extern void destroy(Static15b20*);
struct Static15b20 {
    void* value;
    Static15b20() { construct(this, &descriptor); }
    ~Static15b20() { destroy(this); }
};
