// Source exposure: binary-analysis; no external implementation source reused.
// Static1747390, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1747390;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1747390*);
    virtual void release(Static1747390*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1747390*);
struct Static1747390 {
    void* value;
    Static1747390();
    ~Static1747390() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
