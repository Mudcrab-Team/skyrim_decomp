// Source exposure: binary-analysis; no external implementation source reused.
// Static1788070, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788070;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788070*);
    virtual void release(Static1788070*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788070*);
struct Static1788070 {
    void* value;
    Static1788070();
    ~Static1788070() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
