// Source exposure: binary-analysis; no external implementation source reused.
// Static1751110, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751110;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751110*);
    virtual void release(Static1751110*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751110*);
struct Static1751110 {
    void* value;
    Static1751110();
    ~Static1751110() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
