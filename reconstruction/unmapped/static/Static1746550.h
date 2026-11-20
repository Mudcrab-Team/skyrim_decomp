// Source exposure: binary-analysis; no external implementation source reused.
// Static1746550, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1746550;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1746550*);
    virtual void release(Static1746550*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1746550*);
struct Static1746550 {
    void* value;
    Static1746550();
    ~Static1746550() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
