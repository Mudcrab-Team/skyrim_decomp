// Source exposure: binary-analysis; no external implementation source reused.
// Static1759360, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759360;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759360*);
    virtual void release(Static1759360*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759360*);
struct Static1759360 {
    void* value;
    Static1759360();
    ~Static1759360() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
