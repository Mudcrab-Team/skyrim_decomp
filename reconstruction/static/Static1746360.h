// Source exposure: binary-analysis; no external implementation source reused.
// Static1746360, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1746360;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1746360*);
    virtual void release(Static1746360*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1746360*);
struct Static1746360 {
    void* value;
    Static1746360();
    ~Static1746360() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
