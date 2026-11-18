// Source exposure: binary-analysis; no external implementation source reused.
// Static1779c50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779c50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779c50*);
    virtual void release(Static1779c50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779c50*);
struct Static1779c50 {
    void* value;
    Static1779c50();
    ~Static1779c50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
