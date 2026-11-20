// Source exposure: binary-analysis; no external implementation source reused.
// Static174d130, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d130;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d130*);
    virtual void release(Static174d130*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d130*);
struct Static174d130 {
    void* value;
    Static174d130();
    ~Static174d130() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
