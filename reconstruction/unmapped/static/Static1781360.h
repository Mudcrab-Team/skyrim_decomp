// Source exposure: binary-analysis; no external implementation source reused.
// Static1781360, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781360;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781360*);
    virtual void release(Static1781360*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781360*);
struct Static1781360 {
    void* value;
    Static1781360();
    ~Static1781360() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
