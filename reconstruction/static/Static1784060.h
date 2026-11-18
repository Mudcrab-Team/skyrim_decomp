// Source exposure: binary-analysis; no external implementation source reused.
// Static1784060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784060*);
    virtual void release(Static1784060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784060*);
struct Static1784060 {
    void* value;
    Static1784060();
    ~Static1784060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
