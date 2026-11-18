// Source exposure: binary-analysis; no external implementation source reused.
// Static1785550, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785550;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785550*);
    virtual void release(Static1785550*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785550*);
struct Static1785550 {
    void* value;
    Static1785550();
    ~Static1785550() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
