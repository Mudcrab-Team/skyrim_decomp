// Source exposure: binary-analysis
// Static15460, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15460;
extern void construct(Static15460*, const Descriptor*);
extern void destroy(Static15460*);
struct Static15460 {
    void* value;
    Static15460() { construct(this, &descriptor); }
    ~Static15460() { destroy(this); }
};
