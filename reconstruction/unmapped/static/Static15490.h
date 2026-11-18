// Source exposure: binary-analysis
// Static15490, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15490;
extern void construct(Static15490*, const Descriptor*);
extern void destroy(Static15490*);
struct Static15490 {
    void* value;
    Static15490() { construct(this, &descriptor); }
    ~Static15490() { destroy(this); }
};
