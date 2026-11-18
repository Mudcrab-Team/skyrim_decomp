// Source exposure: binary-analysis; no external implementation source reused.
// Static1753500, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753500;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753500*);
    virtual void release(Static1753500*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753500*);
struct Static1753500 {
    void* value;
    Static1753500();
    ~Static1753500() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
