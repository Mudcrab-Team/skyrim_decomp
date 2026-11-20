// Source exposure: binary-analysis; no external implementation source reused.
// Static1753140, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753140;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753140*);
    virtual void release(Static1753140*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753140*);
struct Static1753140 {
    void* value;
    Static1753140();
    ~Static1753140() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
