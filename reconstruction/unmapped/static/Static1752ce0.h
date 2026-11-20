// Source exposure: binary-analysis; no external implementation source reused.
// Static1752ce0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752ce0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752ce0*);
    virtual void release(Static1752ce0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752ce0*);
struct Static1752ce0 {
    void* value;
    Static1752ce0();
    ~Static1752ce0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
