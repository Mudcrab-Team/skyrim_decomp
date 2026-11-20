// Source exposure: binary-analysis; no external implementation source reused.
// Static1796400, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796400;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796400*);
    virtual void release(Static1796400*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796400*);
struct Static1796400 {
    void* value;
    Static1796400();
    ~Static1796400() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
