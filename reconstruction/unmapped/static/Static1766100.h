// Source exposure: binary-analysis; no external implementation source reused.
// Static1766100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766100*);
    virtual void release(Static1766100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766100*);
struct Static1766100 {
    void* value;
    Static1766100();
    ~Static1766100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
