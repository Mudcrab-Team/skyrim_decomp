// Source exposure: binary-analysis; no external implementation source reused.
// Static174f360, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f360;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f360*);
    virtual void release(Static174f360*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f360*);
struct Static174f360 {
    void* value;
    Static174f360();
    ~Static174f360() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
