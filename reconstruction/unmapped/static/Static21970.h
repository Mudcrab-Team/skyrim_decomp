// Source exposure: binary-analysis
// Static21970, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21970;
extern void construct(Static21970*, const Descriptor*);
extern void destroy(Static21970*);
struct Static21970 {
    void* value;
    Static21970() { construct(this, &descriptor); }
    ~Static21970() { destroy(this); }
};
