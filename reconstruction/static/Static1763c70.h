// Source exposure: binary-analysis; no external implementation source reused.
// Static1763c70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763c70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763c70*);
    virtual void release(Static1763c70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763c70*);
struct Static1763c70 {
    void* value;
    Static1763c70();
    ~Static1763c70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
