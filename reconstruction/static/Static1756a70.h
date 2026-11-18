// Source exposure: binary-analysis; no external implementation source reused.
// Static1756a70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756a70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756a70*);
    virtual void release(Static1756a70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756a70*);
struct Static1756a70 {
    void* value;
    Static1756a70();
    ~Static1756a70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
