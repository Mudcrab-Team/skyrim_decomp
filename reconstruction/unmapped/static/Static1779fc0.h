// Source exposure: binary-analysis; no external implementation source reused.
// Static1779fc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779fc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779fc0*);
    virtual void release(Static1779fc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779fc0*);
struct Static1779fc0 {
    void* value;
    Static1779fc0();
    ~Static1779fc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
