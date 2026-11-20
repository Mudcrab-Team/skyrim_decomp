// Source exposure: binary-analysis; no external implementation source reused.
// Static1751980, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751980;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751980*);
    virtual void release(Static1751980*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751980*);
struct Static1751980 {
    void* value;
    Static1751980();
    ~Static1751980() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
