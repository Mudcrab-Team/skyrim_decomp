// Source exposure: binary-analysis
// Static109f80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109f80;
extern void construct(Static109f80*, const Descriptor*);
extern void destroy(Static109f80*);
struct Static109f80 {
    void* value;
    Static109f80() { construct(this, &descriptor); }
    ~Static109f80() { destroy(this); }
};
