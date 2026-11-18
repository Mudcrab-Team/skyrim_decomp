// Source exposure: binary-analysis; no external implementation source reused.
// Static1750b70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750b70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750b70*);
    virtual void release(Static1750b70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750b70*);
struct Static1750b70 {
    void* value;
    Static1750b70();
    ~Static1750b70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
