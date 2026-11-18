// Source exposure: binary-analysis; no external implementation source reused.
// Static1740070, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740070;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740070*);
    virtual void release(Static1740070*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740070*);
struct Static1740070 {
    void* value;
    Static1740070();
    ~Static1740070() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
