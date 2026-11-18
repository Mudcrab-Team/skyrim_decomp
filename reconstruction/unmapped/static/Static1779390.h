// Source exposure: binary-analysis; no external implementation source reused.
// Static1779390, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779390;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779390*);
    virtual void release(Static1779390*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779390*);
struct Static1779390 {
    void* value;
    Static1779390();
    ~Static1779390() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
