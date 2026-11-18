// Source exposure: binary-analysis
// Static9ed50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9ed50;
extern void construct(Static9ed50*, const Descriptor*);
extern void destroy(Static9ed50*);
struct Static9ed50 {
    void* value;
    Static9ed50() { construct(this, &descriptor); }
    ~Static9ed50() { destroy(this); }
};
