// Source exposure: binary-analysis
// Static109b90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109b90;
extern void construct(Static109b90*, const Descriptor*);
extern void destroy(Static109b90*);
struct Static109b90 {
    void* value;
    Static109b90() { construct(this, &descriptor); }
    ~Static109b90() { destroy(this); }
};
