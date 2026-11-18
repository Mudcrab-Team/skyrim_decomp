// Source exposure: binary-analysis; no external implementation source reused.
// Static1755620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755620*);
    virtual void release(Static1755620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755620*);
struct Static1755620 {
    void* value;
    Static1755620();
    ~Static1755620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
