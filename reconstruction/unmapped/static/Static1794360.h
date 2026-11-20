// Source exposure: binary-analysis; no external implementation source reused.
// Static1794360, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1794360;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1794360*);
    virtual void release(Static1794360*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1794360*);
struct Static1794360 {
    void* value;
    Static1794360();
    ~Static1794360() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
