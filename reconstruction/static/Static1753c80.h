// Source exposure: binary-analysis; no external implementation source reused.
// Static1753c80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753c80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753c80*);
    virtual void release(Static1753c80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753c80*);
struct Static1753c80 {
    void* value;
    Static1753c80();
    ~Static1753c80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
