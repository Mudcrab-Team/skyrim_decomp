// Source exposure: binary-analysis
// Static15400, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15400;
extern void construct(Static15400*, const Descriptor*);
extern void destroy(Static15400*);
struct Static15400 {
    void* value;
    Static15400() { construct(this, &descriptor); }
    ~Static15400() { destroy(this); }
};
