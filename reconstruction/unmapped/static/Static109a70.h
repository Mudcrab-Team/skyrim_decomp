// Source exposure: binary-analysis
// Static109a70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109a70;
extern void construct(Static109a70*, const Descriptor*);
extern void destroy(Static109a70*);
struct Static109a70 {
    void* value;
    Static109a70() { construct(this, &descriptor); }
    ~Static109a70() { destroy(this); }
};
