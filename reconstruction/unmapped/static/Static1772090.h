// Source exposure: binary-analysis; no external implementation source reused.
// Static1772090, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772090;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772090*);
    virtual void release(Static1772090*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772090*);
struct Static1772090 {
    void* value;
    Static1772090();
    ~Static1772090() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
