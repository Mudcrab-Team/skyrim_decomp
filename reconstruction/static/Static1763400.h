// Source exposure: binary-analysis; no external implementation source reused.
// Static1763400, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763400;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763400*);
    virtual void release(Static1763400*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763400*);
struct Static1763400 {
    void* value;
    Static1763400();
    ~Static1763400() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
