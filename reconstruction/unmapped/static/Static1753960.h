// Source exposure: binary-analysis; no external implementation source reused.
// Static1753960, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753960;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753960*);
    virtual void release(Static1753960*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753960*);
struct Static1753960 {
    void* value;
    Static1753960();
    ~Static1753960() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
