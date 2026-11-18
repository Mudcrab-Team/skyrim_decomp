// Source exposure: binary-analysis
// Staticef460, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef460;
extern void construct(Staticef460*, const Descriptor*);
extern void destroy(Staticef460*);
struct Staticef460 {
    void* value;
    Staticef460() { construct(this, &descriptor); }
    ~Staticef460() { destroy(this); }
};
