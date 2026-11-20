// Source exposure: binary-analysis; no external implementation source reused.
// Static1795290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795290*);
    virtual void release(Static1795290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795290*);
struct Static1795290 {
    void* value;
    Static1795290();
    ~Static1795290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
