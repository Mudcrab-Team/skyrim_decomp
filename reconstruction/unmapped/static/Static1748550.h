// Source exposure: binary-analysis; no external implementation source reused.
// Static1748550, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1748550;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1748550*);
    virtual void release(Static1748550*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1748550*);
struct Static1748550 {
    void* value;
    Static1748550();
    ~Static1748550() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
