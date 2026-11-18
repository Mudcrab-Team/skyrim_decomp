// Source exposure: binary-analysis; no external implementation source reused.
// Static1761650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761650*);
    virtual void release(Static1761650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761650*);
struct Static1761650 {
    void* value;
    Static1761650();
    ~Static1761650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
