// Source exposure: binary-analysis; no external implementation source reused.
// Static1743150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743150*);
    virtual void release(Static1743150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743150*);
struct Static1743150 {
    void* value;
    Static1743150();
    ~Static1743150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
