// Source exposure: binary-analysis; no external implementation source reused.
// Static1778b20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778b20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778b20*);
    virtual void release(Static1778b20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778b20*);
struct Static1778b20 {
    void* value;
    Static1778b20();
    ~Static1778b20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
