// Source exposure: binary-analysis; no external implementation source reused.
// Static174d940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d940*);
    virtual void release(Static174d940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d940*);
struct Static174d940 {
    void* value;
    Static174d940();
    ~Static174d940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
