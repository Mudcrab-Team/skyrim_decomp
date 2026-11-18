// Source exposure: binary-analysis; no external implementation source reused.
// Static1774390, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774390;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774390*);
    virtual void release(Static1774390*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774390*);
struct Static1774390 {
    void* value;
    Static1774390();
    ~Static1774390() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
