// Source exposure: binary-analysis; no external implementation source reused.
// Static1795240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795240*);
    virtual void release(Static1795240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795240*);
struct Static1795240 {
    void* value;
    Static1795240();
    ~Static1795240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
