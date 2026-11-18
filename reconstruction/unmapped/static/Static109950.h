// Source exposure: binary-analysis
// Static109950, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109950;
extern void construct(Static109950*, const Descriptor*);
extern void destroy(Static109950*);
struct Static109950 {
    void* value;
    Static109950() { construct(this, &descriptor); }
    ~Static109950() { destroy(this); }
};
