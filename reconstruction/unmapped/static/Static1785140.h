// Source exposure: binary-analysis; no external implementation source reused.
// Static1785140, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785140;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785140*);
    virtual void release(Static1785140*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785140*);
struct Static1785140 {
    void* value;
    Static1785140();
    ~Static1785140() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
