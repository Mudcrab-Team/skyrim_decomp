// Source exposure: binary-analysis; no external implementation source reused.
// Static1787fd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1787fd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1787fd0*);
    virtual void release(Static1787fd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1787fd0*);
struct Static1787fd0 {
    void* value;
    Static1787fd0();
    ~Static1787fd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
