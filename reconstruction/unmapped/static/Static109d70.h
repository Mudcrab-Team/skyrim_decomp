// Source exposure: binary-analysis
// Static109d70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109d70;
extern void construct(Static109d70*, const Descriptor*);
extern void destroy(Static109d70*);
struct Static109d70 {
    void* value;
    Static109d70() { construct(this, &descriptor); }
    ~Static109d70() { destroy(this); }
};
