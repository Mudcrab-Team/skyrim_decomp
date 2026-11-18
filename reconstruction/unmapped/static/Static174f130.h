// Source exposure: binary-analysis; no external implementation source reused.
// Static174f130, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f130;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f130*);
    virtual void release(Static174f130*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f130*);
struct Static174f130 {
    void* value;
    Static174f130();
    ~Static174f130() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
