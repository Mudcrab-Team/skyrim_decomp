// Source exposure: binary-analysis; no external implementation source reused.
// Static1784510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784510*);
    virtual void release(Static1784510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784510*);
struct Static1784510 {
    void* value;
    Static1784510();
    ~Static1784510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
