// Source exposure: binary-analysis; no external implementation source reused.
// Static1753b90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753b90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753b90*);
    virtual void release(Static1753b90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753b90*);
struct Static1753b90 {
    void* value;
    Static1753b90();
    ~Static1753b90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
