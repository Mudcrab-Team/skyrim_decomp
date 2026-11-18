// Source exposure: binary-analysis; no external implementation source reused.
// Static1775bf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775bf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775bf0*);
    virtual void release(Static1775bf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775bf0*);
struct Static1775bf0 {
    void* value;
    Static1775bf0();
    ~Static1775bf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
