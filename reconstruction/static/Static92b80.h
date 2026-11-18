// Source exposure: binary-analysis
// Static92b80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static92b80;
extern void construct(Static92b80*, const Descriptor*);
extern void destroy(Static92b80*);
struct Static92b80 {
    void* value;
    Static92b80() { construct(this, &descriptor); }
    ~Static92b80() { destroy(this); }
};
