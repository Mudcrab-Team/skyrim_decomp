// Source exposure: binary-analysis; no external implementation source reused.
// Static1781540, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781540;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781540*);
    virtual void release(Static1781540*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781540*);
struct Static1781540 {
    void* value;
    Static1781540();
    ~Static1781540() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
