// Source exposure: binary-analysis; no external implementation source reused.
// Static1779480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779480*);
    virtual void release(Static1779480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779480*);
struct Static1779480 {
    void* value;
    Static1779480();
    ~Static1779480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
