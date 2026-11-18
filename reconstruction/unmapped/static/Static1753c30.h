// Source exposure: binary-analysis; no external implementation source reused.
// Static1753c30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753c30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753c30*);
    virtual void release(Static1753c30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753c30*);
struct Static1753c30 {
    void* value;
    Static1753c30();
    ~Static1753c30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
