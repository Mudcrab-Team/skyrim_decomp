// Source exposure: binary-analysis; no external implementation source reused.
// Static1753230, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753230;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753230*);
    virtual void release(Static1753230*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753230*);
struct Static1753230 {
    void* value;
    Static1753230();
    ~Static1753230() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
