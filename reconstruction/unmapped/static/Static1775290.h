// Source exposure: binary-analysis; no external implementation source reused.
// Static1775290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775290*);
    virtual void release(Static1775290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775290*);
struct Static1775290 {
    void* value;
    Static1775290();
    ~Static1775290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
