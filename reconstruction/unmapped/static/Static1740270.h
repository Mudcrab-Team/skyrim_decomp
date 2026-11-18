// Source exposure: binary-analysis; no external implementation source reused.
// Static1740270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740270*);
    virtual void release(Static1740270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740270*);
struct Static1740270 {
    void* value;
    Static1740270();
    ~Static1740270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
