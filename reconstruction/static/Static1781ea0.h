// Source exposure: binary-analysis; no external implementation source reused.
// Static1781ea0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781ea0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781ea0*);
    virtual void release(Static1781ea0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781ea0*);
struct Static1781ea0 {
    void* value;
    Static1781ea0();
    ~Static1781ea0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
