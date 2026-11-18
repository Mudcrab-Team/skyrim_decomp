// Source exposure: binary-analysis; no external implementation source reused.
// Static1779f20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779f20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779f20*);
    virtual void release(Static1779f20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779f20*);
struct Static1779f20 {
    void* value;
    Static1779f20();
    ~Static1779f20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
