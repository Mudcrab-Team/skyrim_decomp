// Source exposure: binary-analysis; no external implementation source reused.
// Static1795950, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795950;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795950*);
    virtual void release(Static1795950*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795950*);
struct Static1795950 {
    void* value;
    Static1795950();
    ~Static1795950() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
