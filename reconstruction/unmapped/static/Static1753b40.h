// Source exposure: binary-analysis; no external implementation source reused.
// Static1753b40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753b40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753b40*);
    virtual void release(Static1753b40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753b40*);
struct Static1753b40 {
    void* value;
    Static1753b40();
    ~Static1753b40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
