// Source exposure: binary-analysis; no external implementation source reused.
// Static1779d40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779d40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779d40*);
    virtual void release(Static1779d40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779d40*);
struct Static1779d40 {
    void* value;
    Static1779d40();
    ~Static1779d40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
