// Source exposure: binary-analysis; no external implementation source reused.
// Static1756f70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756f70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756f70*);
    virtual void release(Static1756f70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756f70*);
struct Static1756f70 {
    void* value;
    Static1756f70();
    ~Static1756f70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
