// Source exposure: binary-analysis
// Static21bf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21bf0;
extern void construct(Static21bf0*, const Descriptor*);
extern void destroy(Static21bf0*);
struct Static21bf0 {
    void* value;
    Static21bf0() { construct(this, &descriptor); }
    ~Static21bf0() { destroy(this); }
};
