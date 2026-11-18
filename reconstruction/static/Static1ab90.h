// Source exposure: binary-analysis
// Static1ab90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1ab90;
extern void construct(Static1ab90*, const Descriptor*);
extern void destroy(Static1ab90*);
struct Static1ab90 {
    void* value;
    Static1ab90() { construct(this, &descriptor); }
    ~Static1ab90() { destroy(this); }
};
