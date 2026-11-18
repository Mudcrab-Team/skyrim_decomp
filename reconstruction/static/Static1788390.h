// Source exposure: binary-analysis; no external implementation source reused.
// Static1788390, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788390;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788390*);
    virtual void release(Static1788390*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788390*);
struct Static1788390 {
    void* value;
    Static1788390();
    ~Static1788390() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
