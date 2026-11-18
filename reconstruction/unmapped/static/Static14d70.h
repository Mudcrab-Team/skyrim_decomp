// Source exposure: binary-analysis
// Static14d70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static14d70;
extern void construct(Static14d70*, const Descriptor*);
extern void destroy(Static14d70*);
struct Static14d70 {
    void* value;
    Static14d70() { construct(this, &descriptor); }
    ~Static14d70() { destroy(this); }
};
