// Source exposure: binary-analysis; no external implementation source reused.
// Static1775470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775470*);
    virtual void release(Static1775470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775470*);
struct Static1775470 {
    void* value;
    Static1775470();
    ~Static1775470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
