// Source exposure: binary-analysis; no external implementation source reused.
// Static1768360, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768360;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768360*);
    virtual void release(Static1768360*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768360*);
struct Static1768360 {
    void* value;
    Static1768360();
    ~Static1768360() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
