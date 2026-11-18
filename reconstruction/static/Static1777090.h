// Source exposure: binary-analysis; no external implementation source reused.
// Static1777090, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777090;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777090*);
    virtual void release(Static1777090*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777090*);
struct Static1777090 {
    void* value;
    Static1777090();
    ~Static1777090() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
