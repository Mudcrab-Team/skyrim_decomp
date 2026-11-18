// Source exposure: binary-analysis; no external implementation source reused.
// Static1754360, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754360;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754360*);
    virtual void release(Static1754360*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754360*);
struct Static1754360 {
    void* value;
    Static1754360();
    ~Static1754360() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
