// Source exposure: binary-analysis; no external implementation source reused.
// Static1741510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741510*);
    virtual void release(Static1741510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741510*);
struct Static1741510 {
    void* value;
    Static1741510();
    ~Static1741510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
