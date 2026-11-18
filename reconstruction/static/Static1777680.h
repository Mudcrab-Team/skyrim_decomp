// Source exposure: binary-analysis; no external implementation source reused.
// Static1777680, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777680;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777680*);
    virtual void release(Static1777680*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777680*);
struct Static1777680 {
    void* value;
    Static1777680();
    ~Static1777680() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
