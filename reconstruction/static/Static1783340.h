// Source exposure: binary-analysis; no external implementation source reused.
// Static1783340, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783340;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783340*);
    virtual void release(Static1783340*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783340*);
struct Static1783340 {
    void* value;
    Static1783340();
    ~Static1783340() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
