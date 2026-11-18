// Source exposure: binary-analysis; no external implementation source reused.
// Static1799620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1799620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1799620*);
    virtual void release(Static1799620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1799620*);
struct Static1799620 {
    void* value;
    Static1799620();
    ~Static1799620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
