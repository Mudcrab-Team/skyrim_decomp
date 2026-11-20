// Source exposure: binary-analysis
// Static109d40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109d40;
extern void construct(Static109d40*, const Descriptor*);
extern void destroy(Static109d40*);
struct Static109d40 {
    void* value;
    Static109d40() { construct(this, &descriptor); }
    ~Static109d40() { destroy(this); }
};
