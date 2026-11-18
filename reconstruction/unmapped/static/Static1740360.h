// Source exposure: binary-analysis; no external implementation source reused.
// Static1740360, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740360;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740360*);
    virtual void release(Static1740360*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740360*);
struct Static1740360 {
    void* value;
    Static1740360();
    ~Static1740360() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
