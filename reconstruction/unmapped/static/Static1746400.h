// Source exposure: binary-analysis; no external implementation source reused.
// Static1746400, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1746400;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1746400*);
    virtual void release(Static1746400*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1746400*);
struct Static1746400 {
    void* value;
    Static1746400();
    ~Static1746400() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
