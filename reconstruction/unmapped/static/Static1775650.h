// Source exposure: binary-analysis; no external implementation source reused.
// Static1775650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775650*);
    virtual void release(Static1775650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775650*);
struct Static1775650 {
    void* value;
    Static1775650();
    ~Static1775650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
