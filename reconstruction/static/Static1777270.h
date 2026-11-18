// Source exposure: binary-analysis; no external implementation source reused.
// Static1777270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777270*);
    virtual void release(Static1777270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777270*);
struct Static1777270 {
    void* value;
    Static1777270();
    ~Static1777270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
