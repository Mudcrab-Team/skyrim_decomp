// Source exposure: binary-analysis; no external implementation source reused.
// Static1795010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795010*);
    virtual void release(Static1795010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795010*);
struct Static1795010 {
    void* value;
    Static1795010();
    ~Static1795010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
