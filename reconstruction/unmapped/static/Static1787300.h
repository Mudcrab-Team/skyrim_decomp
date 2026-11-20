// Source exposure: binary-analysis; no external implementation source reused.
// Static1787300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1787300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1787300*);
    virtual void release(Static1787300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1787300*);
struct Static1787300 {
    void* value;
    Static1787300();
    ~Static1787300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
