// Source exposure: binary-analysis; no external implementation source reused.
// Static1795600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795600*);
    virtual void release(Static1795600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795600*);
struct Static1795600 {
    void* value;
    Static1795600();
    ~Static1795600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
