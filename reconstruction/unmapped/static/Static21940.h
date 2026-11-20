// Source exposure: binary-analysis
// Static21940, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21940;
extern void construct(Static21940*, const Descriptor*);
extern void destroy(Static21940*);
struct Static21940 {
    void* value;
    Static21940() { construct(this, &descriptor); }
    ~Static21940() { destroy(this); }
};
