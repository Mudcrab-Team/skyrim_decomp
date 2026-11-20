// Source exposure: binary-analysis; no external implementation source reused.
// Static1746310, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1746310;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1746310*);
    virtual void release(Static1746310*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1746310*);
struct Static1746310 {
    void* value;
    Static1746310();
    ~Static1746310() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
