// Source exposure: binary-analysis; no external implementation source reused.
// Static1771140, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771140;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771140*);
    virtual void release(Static1771140*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771140*);
struct Static1771140 {
    void* value;
    Static1771140();
    ~Static1771140() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
