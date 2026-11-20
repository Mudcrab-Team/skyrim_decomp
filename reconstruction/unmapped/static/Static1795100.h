// Source exposure: binary-analysis; no external implementation source reused.
// Static1795100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795100*);
    virtual void release(Static1795100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795100*);
struct Static1795100 {
    void* value;
    Static1795100();
    ~Static1795100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
