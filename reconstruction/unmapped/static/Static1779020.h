// Source exposure: binary-analysis; no external implementation source reused.
// Static1779020, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779020;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779020*);
    virtual void release(Static1779020*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779020*);
struct Static1779020 {
    void* value;
    Static1779020();
    ~Static1779020() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
