// Source exposure: binary-analysis; no external implementation source reused.
// Static1775d80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775d80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775d80*);
    virtual void release(Static1775d80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775d80*);
struct Static1775d80 {
    void* value;
    Static1775d80();
    ~Static1775d80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
