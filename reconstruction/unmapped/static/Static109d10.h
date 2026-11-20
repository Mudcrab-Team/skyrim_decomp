// Source exposure: binary-analysis
// Static109d10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109d10;
extern void construct(Static109d10*, const Descriptor*);
extern void destroy(Static109d10*);
struct Static109d10 {
    void* value;
    Static109d10() { construct(this, &descriptor); }
    ~Static109d10() { destroy(this); }
};
