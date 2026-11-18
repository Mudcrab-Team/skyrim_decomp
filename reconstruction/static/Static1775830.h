// Source exposure: binary-analysis; no external implementation source reused.
// Static1775830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775830*);
    virtual void release(Static1775830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775830*);
struct Static1775830 {
    void* value;
    Static1775830();
    ~Static1775830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
