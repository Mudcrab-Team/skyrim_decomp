// Source exposure: binary-analysis; no external implementation source reused.
// Static1752470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752470*);
    virtual void release(Static1752470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752470*);
struct Static1752470 {
    void* value;
    Static1752470();
    ~Static1752470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
