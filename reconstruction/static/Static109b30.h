// Source exposure: binary-analysis
// Static109b30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109b30;
extern void construct(Static109b30*, const Descriptor*);
extern void destroy(Static109b30*);
struct Static109b30 {
    void* value;
    Static109b30() { construct(this, &descriptor); }
    ~Static109b30() { destroy(this); }
};
