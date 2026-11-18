// Source exposure: binary-analysis; no external implementation source reused.
// Static1753780, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753780;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753780*);
    virtual void release(Static1753780*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753780*);
struct Static1753780 {
    void* value;
    Static1753780();
    ~Static1753780() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
