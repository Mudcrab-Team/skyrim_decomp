// Source exposure: binary-analysis; no external implementation source reused.
// Static1783f70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783f70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783f70*);
    virtual void release(Static1783f70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783f70*);
struct Static1783f70 {
    void* value;
    Static1783f70();
    ~Static1783f70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
