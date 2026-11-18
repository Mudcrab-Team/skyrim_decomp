// Source exposure: binary-analysis; no external implementation source reused.
// Static1756390, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756390;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756390*);
    virtual void release(Static1756390*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756390*);
struct Static1756390 {
    void* value;
    Static1756390();
    ~Static1756390() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
