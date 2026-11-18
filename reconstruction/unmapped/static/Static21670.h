// Source exposure: binary-analysis
// Static21670, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21670;
extern void construct(Static21670*, const Descriptor*);
extern void destroy(Static21670*);
struct Static21670 {
    void* value;
    Static21670() { construct(this, &descriptor); }
    ~Static21670() { destroy(this); }
};
