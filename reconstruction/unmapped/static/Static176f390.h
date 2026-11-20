// Source exposure: binary-analysis; no external implementation source reused.
// Static176f390, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f390;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f390*);
    virtual void release(Static176f390*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f390*);
struct Static176f390 {
    void* value;
    Static176f390();
    ~Static176f390() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
