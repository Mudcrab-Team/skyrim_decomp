// Source exposure: binary-analysis; no external implementation source reused.
// Static1761290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761290*);
    virtual void release(Static1761290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761290*);
struct Static1761290 {
    void* value;
    Static1761290();
    ~Static1761290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
