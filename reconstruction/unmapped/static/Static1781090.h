// Source exposure: binary-analysis; no external implementation source reused.
// Static1781090, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781090;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781090*);
    virtual void release(Static1781090*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781090*);
struct Static1781090 {
    void* value;
    Static1781090();
    ~Static1781090() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
