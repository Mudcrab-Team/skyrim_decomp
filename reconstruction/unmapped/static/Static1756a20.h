// Source exposure: binary-analysis; no external implementation source reused.
// Static1756a20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756a20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756a20*);
    virtual void release(Static1756a20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756a20*);
struct Static1756a20 {
    void* value;
    Static1756a20();
    ~Static1756a20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
