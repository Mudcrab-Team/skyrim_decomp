// Source exposure: binary-analysis; no external implementation source reused.
// Static1777950, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777950;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777950*);
    virtual void release(Static1777950*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777950*);
struct Static1777950 {
    void* value;
    Static1777950();
    ~Static1777950() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
